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

void push_front(int X) {
	if(_size) {
		QUEUE * TEMP = new QUEUE();
		TEMP->data = X;
		
		_FRONT->prev = TEMP;
		
		TEMP->prev = TEMP;
		TEMP->next = _FRONT;
		
		_FRONT = TEMP;
		
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

int pop_back() {
	if(!_size) {
		return -1;
	}
	
	QUEUE * TEMP = _BACK;
	int X = _BACK->data;
	
	_BACK = _BACK->prev;
	
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

void initQueue(){
	_size = 0;
}

int main() {
	
	char op[50];
	int T, x;
	
	scanf("%d", &T);
	
	while(T--) {
		scanf("%s", op);
		
		if(op[0] == 'p' && op[1] == 'u') {			//push
			scanf("%d", &x);
			if(op[5] == 'f') {						//push_front
				push_front(x);
			} else {								//push_back
				push(x);
			}
		} else if(op[0] == 'p' && op[1] == 'o') {	//pop
			if(op[4] == 'f') {
				printf("%d\n", pop());
			} else {
				printf("%d\n", pop_back());
			}
		} else if(op[0] == 's') {					//size
			printf("%d\n", size());
		} else if(op[0] == 'e') {					//empty
			printf("%d\n", empty());
		} else if(op[0] == 'f') {					//front
			printf("%d\n", front());
		} else if(op[0] == 'b') {					//back
			printf("%d\n", back());
		}
	}
	
	return 0;
}