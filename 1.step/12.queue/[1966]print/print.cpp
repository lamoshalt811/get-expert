#include <stdio.h>

static int PRIORITY[101];
static int CHECK[101];

struct DATA {
	int data;
	DATA * prev;
	DATA * next;
};

DATA * _FRONT;
DATA * _BACK;
int _size = 0;

void push(int X) {			
	if(_size) {
		DATA * TEMP = new DATA();
		TEMP->data = X;
		
		_BACK->next = TEMP;
		
		TEMP->prev = _BACK;
		TEMP->next = TEMP;
		
		_BACK = TEMP;
	} else {
		_FRONT = new DATA();
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
	
	DATA * TEMP = _FRONT;
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
	DATA * TEMP;
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

DATA * _LIST;

void insert(int p) {
	
	DATA * TEMP;
	DATA * N;
	
	if(_LIST == NULL) {
		_LIST = new DATA();
		_LIST->data = p;
		_LIST->prev = _LIST;
		_LIST->next = _LIST;				
	} else {	
		TEMP = _LIST;
		while(true) {
						
			if( TEMP->data < p ) {
				// printf("insert fornt\n");
				N = new DATA();
				N->data = p;
				
				if(TEMP == _LIST) {
					
					N->prev = N;
					
					N->next = TEMP;
					TEMP->prev = N;
					
					_LIST = N;
					
				} else {
					TEMP->prev->next = N;
					N->prev = TEMP->prev;
					
					N->next = TEMP;
					TEMP->prev = N;
				}
				
				break;
			}
			
			if( TEMP->next == TEMP ) {
				// printf("insert last\n");
				N = new DATA();
				N->data = p;
				
				N->prev = TEMP;
				TEMP->next = N;
				
				N->next = N;
				break;
			}
			
			TEMP = TEMP->next;			
		}
	}
}

// void prn(){
// 	DATA * TEMP = _LIST;
// 	printf(" == list == ");
// 	while(TEMP->next != TEMP) {
// 		printf("%d ", TEMP->data);
// 		TEMP = TEMP->next;
// 	}
// 	printf("%d\n", TEMP->data);
// }

int main(){
	
	int i, j, t, max = -1, cnt;
	int T, N, M;
	
	scanf("%d", &T);
		
	while(T--) {
		
		scanf("%d %d", &N, &M);	
		
		_LIST = NULL;
		initQueue();
		
		for(i=1; i<=N; i++) {
			scanf("%d", &PRIORITY[i]);
			insert(PRIORITY[i]);
			push(i);
		}
						
		cnt=1;
		while(1) {
			
			int doc = front();
						
			if(PRIORITY[doc] < _LIST->data) {
				shift();
				continue;
			} 
			
			if(doc == M+1) {
				printf("%d\n", cnt);
				break;
			}
			
			pop();
			_LIST = _LIST->next;
			cnt++;
		}
	}
	return 0;
}