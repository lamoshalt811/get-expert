#include <stdio.h>

int main(){
	
	int T;
	scanf("%d", &T);
	
	while(T--) {
		
		int M, N, X, Y;
		int result;
		scanf("%d %d %d %d", &M, &N, &X , &Y);
		
		result = X;
		
		while(true) {
		
			if(result > M*N) {
				printf("-1\n");
				break;
			}
			
			int mod = result % N;
			mod = (mod == 0) ? N : mod;
			if( mod == Y) {
				printf("%d\n", result);
				break;
			}
			
			result += M;
		}
		
	}
	
	return 0;
}


	