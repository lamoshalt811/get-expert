#include <stdio.h>
#define IS_EMPTY() (FRONT == BACK)
#define IS_REVERSE(N) (N%2)

static int QUEUE[100001];
static int FRONT = 0;
static int BACK = 0;

void push(int x) {
	QUEUE[BACK] = x;
	++BACK;
}

int pop_front() {
	++FRONT;
	return QUEUE[FRONT-1];
}

int pop_back() {
	--BACK;
	return QUEUE[BACK];
}

void initQueue() {
	FRONT = 0;
	BACK = 0;
}

void inputByArray(int n) {
	char array[400010];
	int i, x;
	
	scanf("%s", array);
	
	x = 0;
	for(i=1; array[i] != ']'; i++) {
		
		if(array[i] == ',') {
			push(x);
			x=0;
		} else {
			x *= 10;
			x += array[i] - '0';
		}
	}
	push(x);
}

int main() {
	
	char op[100000];
	int T, i, n, rcount, isError;
	
	scanf("%d", &T);
	
	while(T--) {
		rcount=0;
		isError=0;
		initQueue();
		
		scanf("%s", op);
		scanf("%d", &n);
		
		inputByArray(n);
		if(n == 0) {
			initQueue();
		}
		
		for(i=0; op[i]; i++) {
			if(op[i] == 'R') {
				rcount++;
			} else if(op[i] == 'D') {
				if(IS_EMPTY()) {
					isError = 1;
					break;
				}
				
				if(IS_REVERSE(rcount)) {
					pop_back();
				} else {
					pop_front();
				}
			}
		}
		
		if(isError) {
			printf("error\n");
		} else if(IS_EMPTY()) {
			printf("[]\n");
		} else {
			printf("[%d", IS_REVERSE(rcount) ? pop_back() : pop_front());
			while(!IS_EMPTY()) {
				printf(",%d", IS_REVERSE(rcount) ? pop_back() : pop_front());
			}
			printf("]\n");
		}
	}
	
	return 0;
}