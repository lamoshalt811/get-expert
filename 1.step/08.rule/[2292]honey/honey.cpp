#include <stdio.h>

int main(){
	int d=1, w=6, cnt=1, N;
	scanf("%d", &N);
	
	while(d < N) {
		++cnt;		
		d += w;
		w += 6;
	}
	
	printf("%d\n", cnt);
}
