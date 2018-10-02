#include <stdio.h>

int main(){
		
	int T;
	int H, W, M;
	scanf("%d", &T);
	
	while(T--) {
		scanf("%d %d %d", &H, &W, &M);
		
		M--;
		int h = M%H + 1;
		int w = M/H + 1;
		
		printf("%d%02d\n", h, w);
	}
}