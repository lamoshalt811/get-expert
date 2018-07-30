#include <stdio.h>

int main(void) {
	int n1, n2, n3;
	
	scanf("%d", &n1);
	scanf("%d", &n2);
	scanf("%d", &n3);
	
	int result = n1 * n2 * n3;
	int arr[10] = {0,0,0,0,0,0,0,0,0,0};
	
	while(result > 0) {
		arr[result%10]++;
		result /= 10;
	}
	
	for(int i=0; i<10; i++) {
		printf("%d\n", arr[i]);
	}
}