#include <stdio.h>

int main(){
	int a, b, c, t;
	scanf("%d %d %d", &a, &b, &c);
	if(a<b) {
		t = a;
		a = b;
		b = t;
	}
	
	if(a>c) {	
		printf("%d\n", (c>b) ? c : b );	
	} else {
		printf("%d\n", a );		
	}
	return 0;	
}