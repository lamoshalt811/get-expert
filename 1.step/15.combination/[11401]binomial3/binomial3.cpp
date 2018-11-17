#include <stdio.h>

static int MOD = 1000000007;

// fac 구하기
static long fac(long n) {
	
	long ret = 1;
	while (n > 1)
	{
		ret = (ret * n) % MOD;
		n--;
	}
	return ret;
}

static long pow(long a, int b) {

	long ret= 1;
	long aa = a;

	while (b > 0) {

		if (b%2 == 1) 
			ret = ret * aa  % MOD;
		
		b = b/2;
		aa = (aa * aa) % MOD;
	}

	return ret;
}

int main() {

	long n, k;
	scanf("%ld %ld",&n, &k);

	long a = fac(n);
	long b = fac(n - k) * fac(k) % MOD;
	long result = a * pow(b, MOD-2) % MOD;

	printf("%ld", result);
        
	return 0;
}