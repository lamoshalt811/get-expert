#include <stdio.h>

long long int gcd(long long int a, long long int b){
	while(b!=0){
		long long int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

long long int lcm(long long int a, long long int b){
    return a * b / gcd(a,b);
}

int main(){
	
	long long int n1, n2, n3;
	
	scanf("%lld %lld", &n1, &n2);

	if (n2 > n1) {
		n3 = n1;
		n1 = n2;
		n2 = n3;
	}

	printf("%lld\n", lcm(n1, n2));
	
	return 0;
}