#include <stdio.h>

int main(void) {
    int sum =0, n;
	
	for(int i=0; i<5; i++) {
		scanf("%d", &n);
		if(n < 40)
			n = 40;
		sum+=n;
	}
	
	printf("%d\n", sum/5);
	return 0;
}