#include <stdio.h>
#define SIZE 10001

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

int main() {
	
	char bracket[51];
	int T, i;
	scanf("%d", &T);
	
	while(T--) {
		
		scanf("%s", bracket);
		
		i=0;
		init();
		while(true) {
			
			if(bracket[i] == '(') {
				push(bracket[i]);	
			} else if(bracket[i] == ')') {
				if(pop() == -1 ) {
					printf("NO\n");
					break;
				}
			} else {
				printf("%s\n", (size() == 0) ? "YES" : "NO");
				break;
			}
			
			i++;
		}
	}
	
	return 0;
}