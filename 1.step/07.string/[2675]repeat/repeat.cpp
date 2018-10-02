#include <stdio.h>

int main(){
	
	int i, T, R;
	char S[100];
	
	scanf("%d", &T);
		
	while(T--) {
	
		scanf("%d %s", &R, S);
		
		i=0;
		do{
		
			for(int j=0; j<R; j++) {
				putchar(S[i]);
			}
		} while(S[++i]);
		putchar('\n');
	}
		
	return 0;
}