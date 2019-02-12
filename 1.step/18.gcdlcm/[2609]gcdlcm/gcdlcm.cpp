#include <stdio.h>

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main(){
	
	int n1, n2, n3;
	
	scanf("%d %d", &n1, &n2);

	if (n2 > n1) {
		n3 = n1;
		n1 = n2;
		n2 = n3;
	}

	printf("%d\n", gcd(n1, n2));
	printf("%d\n", lcm(n1, n2));
	
	return 0;
}