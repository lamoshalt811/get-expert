#include <stdio.h>

static int GRAPH[1001][1001];
static int CHECK[1001];
static int N, M, V;

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

void initQueue(){
	_size = 0;
}

void dfs(int V) {
	int i;
	
	printf("%d ", V);
	
	for(i=1; i<=N; i++) {
		if(GRAPH[V][i] == 1 && CHECK[i] == 0) {			
			CHECK[i] = 1;
			dfs(i);
		}
	}	
}

void bfs(int V) {
	int i;
	
	printf("%d ", V);
	
	for(i=1; i<=N; i++) {
		if(GRAPH[V][i] == 1 && CHECK[i] == 0) {
			push( i );
			CHECK[i] = 1;
		}
	}
	
	while(!empty()) {
		bfs(pop());
	}
}

void initCheck() {
	for(int i=0; i<1001; i++)
		CHECK[i] = 0;		
}

int main(){

	int i, x, y;
	
	scanf("%d %d %d", &N, &M, &V);
	
	for(i=0; i<M; i++) {
		scanf("%d %d", &x ,&y);
		GRAPH[x][y] = 1;
		GRAPH[y][x] = 1;
	}
	
	CHECK[V] = 1;
	dfs(V);
	printf("\n");
	
	initQueue();
	initCheck();
	
	CHECK[V] = 1;
	bfs(V);
	printf("\n");
	
	return 0;
}