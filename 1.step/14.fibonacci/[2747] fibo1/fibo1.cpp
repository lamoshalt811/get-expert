#include <stdio.h>

static int _FIBO[50];

int main(){

	int n, i;
	
	_FIBO[1] = 1;
	_FIBO[2] = 1;
	
	for(i=3; i<=45; i++) {
		_FIBO[i] = _FIBO[i-1] + _FIBO[i-2];
	}
	
	scanf("%d", &n);
	printf("%d", _FIBO[n]);

	return 0;
}