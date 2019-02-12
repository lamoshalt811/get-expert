#include <stdio.h>

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}


int main(){
	
	int t, n1, n2, g;
	
	scanf("%d", &t);
	
	t--;
	scanf("%d", &n1);
		
	while(t--) {
		scanf("%d", &n2);
		
		if(n1 > n2) {
			g = gcd(n1, n2);
		} else {
			g = gcd(n2, n1);
		}
		
		printf("%d/%d\n", n1/g, n2/g);
	}
		
	return 0;
}