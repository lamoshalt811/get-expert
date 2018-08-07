#include <stdio.h>

typedef struct list {
	int num;
	list *next;
} list;

list *HEAD;
list *TAIL;

void init() {
	HEAD = new list();
	TAIL = new list();
	HEAD->next = TAIL;
	TAIL->next = 0;
}

void insert(int index, int num) {
	
	list *NODE = HEAD;
	
	for(int i=0; i<index; i++) {
		NODE = NODE->next;		
	}
	
	list *newNode = new list();
	
	newNode->num = num;
	newNode->next = NODE->next;
	NODE->next = newNode;
}

int main(){
	
	int i, N, is;
	
	init();
	
	scanf("%d", &N);
	for(i=0; i<N;i++) {
		scanf("%d", &is);
		
		insert(i-is, i+1);
	}
	
	list *pNode = HEAD->next;
	while(pNode->next) {
		printf("%d ", pNode->num);	
		pNode = pNode->next;
	}
	printf("\n");
	
	return 0;
}