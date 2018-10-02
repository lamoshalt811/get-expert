#include <stdio.h>

int main(){
	
	int i, n, arr[10] = {0,0,0,0,0,0,0,0,0,0};
	char str[10];
	
	scanf("%s", str);
	
	for(i=0; str[i]; i++) { 
		n = str[i] - '0';
		n = (n==9) ? 6 : n;
		arr[n]++;
	}
	
	arr[6] = (arr[6]+1) / 2;
	
	int max = 0;
	for(i=0; i<9; i++) {
		if(max < arr[i])
			max = arr[i];
	}
	
	printf("%d\n", max);
	
	return 0;
}