#include <stdio.h>

int main(){
	char num[101];
	int n, sum;
	scanf("%d", &n);
	scanf("%s", num);
	
	sum=0;
	for(int i=0; num[i]; i++) {
		sum += (num[i]-'0');
	}
	
	printf("%d\n", sum);
	return 0;
}