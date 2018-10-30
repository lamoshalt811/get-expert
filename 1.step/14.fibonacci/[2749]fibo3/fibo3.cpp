#include <stdio.h>

static int mod = 1000000;
static int p = mod/10*15;

static long long _FIBO[1500000];

int main() {
    
	long long n;
	int i;
	
	_FIBO[1] = 1;
	_FIBO[2] = 1;
	
	for(i=3; i<p; i++) {
		_FIBO[i] = _FIBO[i-1] + _FIBO[i-2];
        _FIBO[i] %= mod;
	}
	
	scanf("%ld", &n);
	printf("%ld", _FIBO[n % p]);
    return 0;
}