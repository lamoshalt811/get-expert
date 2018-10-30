#include <stdio.h>

static long long _FIBO[30];

int main(){

	int n, i;
	
	_FIBO[1] = 1;
	_FIBO[2] = 1;
	
	for(i=3; i<=20; i++) {
		_FIBO[i] = _FIBO[i-1] + _FIBO[i-2];
	}
	
	scanf("%d", &n);
	printf("%ld", _FIBO[n]);

	return 0;
}