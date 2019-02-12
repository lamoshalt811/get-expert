#include <stdio.h>

int main(){
	
	int n1, n2, n3;
	
	scanf("%d %d", &n1, &n2);

	if (n2 > n1) {
		n3 = n1;
		n1 = n2;
		n2 = n3;
	} else if(n2 == n1) {
		n2 = 0;
	}

	for(int i=0; i<n1-n2; i++) {
		printf("1");
	}
	return 0;
}