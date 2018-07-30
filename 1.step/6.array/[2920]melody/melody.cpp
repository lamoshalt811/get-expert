#include <stdio.h>

int main(void) {
	int i, in[10];
	bool asc=1, desc=1;	
	
	for(i=0; i<8; i++) {
		scanf("%d", in+i);
		
		asc &= in[i] == i+1;
		desc &= in[i] == 8-i;
	}
	
	if(asc)			printf("ascending\n");
	else if(desc)	printf("descending\n");
	else 			printf("mixed\n");
	
	return 0;
}