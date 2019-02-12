#include <stdio.h>

int main(){
	
	int n1, n2, n3, n4;
	int t=3;

	while(t--) {
		
		scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
		
		switch(n1 + n2 + n3 + n4) {
			case 3:
				printf("A\n");
				break;
			case 2:
				printf("B\n");
				break;
			case 1:
				printf("C\n");
				break;
			case 0:
				printf("D\n");
				break;
			case 4:
				printf("E\n");
				break;
		}	
	}	
	
	return 0;
}