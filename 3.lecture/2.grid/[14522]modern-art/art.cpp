#include <stdio.h>

int N;
int map[1000][1000];


int main(){
	
	int i,j, cnt;
	
	scanf("%d", &N);
	cnt = N*N;
	
	for(i=0; i<N;i++) {
		for(j=0; j<N;j++) {
			scanf("%d", &map[i][j]);
			
			
		}
	}
	
	printf("%d\n", cnt);
	
	return 0;
}