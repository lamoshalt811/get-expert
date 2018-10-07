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

int main() {
	
	char op[10];
	int T, n;
	scanf("%d", &T);
	
	while(T--) {
		scanf("%s", op);
		
		if(op[0] == 'p' && op[1] == 'u') { 			// push X
			scanf("%d", &n);
			push(n);
		} else if(op[0] == 'p' && op[1] == 'o') { 	// pop
			printf("%d\n", pop());
		} else if(op[0] == 's') {					// size 
			printf("%d\n", size());
		} else if(op[0] == 'e') { 					// empty
			printf("%d\n", empty());
		} else if(op[0] == 't') {					// top
			printf("%d\n", top());
		}
	}
	
	return 0;
}