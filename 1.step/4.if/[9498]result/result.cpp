#include <stdio.h>

int main(){
	
	char prn[15] = "FFFFFFDCBAA";
	int n;
	scanf("%d", &n);
	printf("%c\n", prn[n/10]);
}