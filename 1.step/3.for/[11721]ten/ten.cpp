#include <stdio.h>

int main(){
	int i=0;
	char str[101];	
	scanf("%s", str);
	
	for(i=1; str[i-1]; i++) {
		printf("%c", str[i-1]);
		if(i > 0 && i % 10 == 0)
			printf("\n");
	}
	if((i-1) % 10 != 0)
		printf("\n");
	
	return 0;
}