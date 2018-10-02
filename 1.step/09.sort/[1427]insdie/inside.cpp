#include <stdio.h>

int main(){
	
	int i, j, len;
	char str[11], t;
	
	int n = scanf("%s", str);
		
	for(len=0; str[len]; len++);
	
	for(i=0; i<len-1; i++) {
		for(j=i; j<len; j++) {
			if(str[i] < str[j]) {
				t = str[i];
				str[i] = str[j];
				str[j] = t;
			}
		}
	}
	
	printf("%s\n", str);
}
