#include <stdio.h>

int main(void) {
	int T;
	char str[100] = "";
	
	scanf("%d", &T);
	
	do {
		scanf("%s", str);
				
		int i=0,  w=1, sum=0;
		while(str[i] != '\n') {
			printf("%c", str[i]);
			if(str[i] == 'O') {
				sum += w;
				++w;
			} else if(str[i] == 'X') {
				w=1;
			} else {
				break;
			}
			++i;
		}
		printf("%d\n", sum);
		--T;
	} while(T > 0);
}