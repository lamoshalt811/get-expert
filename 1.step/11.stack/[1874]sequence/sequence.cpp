#include <stdio.h>
#define SIZE 100001

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
	
	char prn[200000];
	int T, n, s, p;
	scanf("%d", &T);
	
	p=0;
	s = 1;
	for(int t=0; t<T; t++) {
		
		scanf("%d", &n);
		
		while(top() < n) {
			prn[p++] = '+';
			push(s++);
		}
		
		if(top() == n) {
			prn[p++] = '-';
			pop();
		} else if( top() > n) {
			p = -1;
			break;
		}
		prn[p] = 0;
	}
	
	if(p < 0) {
		printf("NO");
		return 0;
	}
	
	for(p=0; prn[p]; p++) {
		printf("%c\n", prn[p]);
	}
	
	return 0;
}