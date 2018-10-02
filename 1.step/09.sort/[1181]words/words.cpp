#include <stdio.h>

static char str [20001][51];

struct WORDLIST {
	char * pStr;
	int length;
	WORDLIST * next;
};

WORDLIST * HEAD = new WORDLIST;

int strcmp(char * pStr1, char * pStr2, int len) {
	
	int i;
		
	for(i=0; i<len; i++) {
		
		if(pStr1[i] > pStr2[i]) {
			return 1;
		}
		
		if(pStr1[i] < pStr2[i]) {
			return -1;
		}
	}
	
	return 0;
}

void addList(char * pStr, int len) {
	
	WORDLIST *node = new WORDLIST;
	node->pStr = pStr;
	node->length= len;
	node->next = NULL;
	
	WORDLIST *prev = HEAD;
	WORDLIST *list = HEAD->next;
	
	while(list) {	
		
		if(list->length > node->length) {
			prev->next = node;
			node->next = list;
			return;			
		} else if(list->length == node->length) {
			int cmp = strcmp(list->pStr, node->pStr, node->length);
			if(cmp > 0) {				
				prev->next = node;
				node->next = list;
				return;
			} else if( cmp == 0) {
				return;
			}
		}
		
		prev = list;
		list = prev->next;
	}
	
	prev->next = node;
}

int main(){
	
	int i, j, N, t, len;
	char * pT;
	
	scanf("%d", &N);
	HEAD->next = NULL;
	
	for(i=0; i<N; i++) {
		scanf("%s", str[i]);
		for(len=0; str[i][ len ] && len < 50; len++);
		
		addList(str[i], len);
	}
	
	WORDLIST *list = HEAD->next;
	while(list) {
		printf("%s\n", list->pStr);
		list = list->next;
	}
	
	return 0;
}