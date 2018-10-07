#include <stdio.h>
#define SIZE 50

static int _STACK[SIZE];
static int _top=-1;

void push(int n) {
	_STACK[++_top] = n;
}

int pop() {
	if(_top < 0) 
		return -1;
	
	return _STACK[_top--];
}

int size() {
	return _top+1;
}

int empty() {
	return (_top == -1) ? 1 : 0;
}

int top() {
	if(_top < 0)
		return -1;
	return _STACK[_top];
}	

void init() {
	_top = -1;
}

bool calc(char brace, int weight) {
	int n = 0, b;
	while(true) {
		b = pop();
		
		if(b == brace) {
			push( (n == 0 ? -1 : n) * weight );
			break;
		} else if(b < -1) {
			n += b;
		} else {
			return false;
		}
	}
	return true;
}

int main() {
	
	char bracket[SIZE];
	int i=0, n=0;
	
	scanf("%s", bracket);

	while(true) {

		if(bracket[i] == '(') {
			push('(');
		} else if(bracket[i] == '[') {
			push('[');
		} else if(bracket[i] == ')') {
			if( !calc('(', 2) ) 
				break;
		} else if(bracket[i] == ']') {
			if( !calc('[', 3) ) 
				break;
		} else {
			while(!empty()) {
				if(top() > 0) {
					n=0;
					break;
				}				
				
				n += pop();
			}
			n *= -1;
			break;
		}
		
		i++;
	}
	
	printf("%d", n);
	return 0;
}