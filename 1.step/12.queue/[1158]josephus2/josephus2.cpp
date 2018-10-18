#include <stdio.h>

struct QUEUE {
	int data;
	QUEUE * prev;
	QUEUE * next;
};

QUEUE * _FRONT;
QUEUE * _BACK;
int _size = 0;

void push(int X) {			
	if(_size) {
		QUEUE * TEMP = new QUEUE();
		TEMP->data = X;
		
		_BACK->next = TEMP;
		
		TEMP->prev = _BACK;
		TEMP->next = TEMP;
		
		_BACK = TEMP;
	} else {
		_FRONT = new QUEUE();
		_FRONT->data = X;
		
		_FRONT->prev = _FRONT;
		_FRONT->next = _FRONT;
		
		_BACK = _FRONT;
	}
	
	++_size;
}

int pop() {	
	if(!_size) {
		return -1;
	}
	
	QUEUE * TEMP = _FRONT;
	int X = _FRONT->data;
	
	_FRONT = _FRONT->next;
	
	delete TEMP;
	
	--_size;
	
	return X;
}

int size() {
	return _size;
}

int empty() {
	return _size ? 0 : 1;
}

int front() {
	return _size ? _FRONT->data : -1;
}

int back() {
	return _size ? _BACK->data : -1;
}

void shift() {
	QUEUE * TEMP;
	TEMP = _FRONT;
	
	_FRONT = _FRONT->next;
	_FRONT->prev = _FRONT;
	
	_BACK->next = TEMP;
	
	TEMP->prev = _BACK;
	TEMP->next = TEMP;
	
	_BACK = TEMP;
}

void initQueue(){
	_size = 0;
}

int main(){
	
	int i, cnt;
	int N, M;
	
	scanf("%d %d", &N, &M);
	
	for(i=1; i<=N; i++) {
		push(i);
	}
	
	cnt = 1;
	printf("<");
	while(1) {
		
		if(size() == 1) {
			printf("%d>", pop());
			break;
		}
		
		if(cnt % M == 0) {
			printf("%d, ", pop());
		} else {
			shift();
		}
		
		cnt++;
	}
	
	return 0;
}