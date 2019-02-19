#include <stdio.h>

#define PI 3.14159265359

int main() {
	int R;
	scanf("%d", &R);
	
	printf("%lf\n", R * R * PI);
	printf("%lf\n", R * R * 2.0);
	
	return 0;
}