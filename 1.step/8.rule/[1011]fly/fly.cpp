#include <stdio.h>


int main(){
	
	int T, x, y;
	
	scanf("%d", &T);
	
	while(T--) {
		scanf("%d %d", &x, &y);
		
		int d = y-x;
		long long i=0;
		
		while(++i) {
			
			if( i*i -i < d && d <= i*i ) {
				printf("%lld\n", 2*i-1);
				break;
			} else if( i*i < d && d <= i*i +i) {
				printf("%lld\n", 2*i);
				break;
			}
			
		}
		
	}
	
	return 0;
}

