#include <stdio.h>

int main() {
	
	int n, r;

	while(true) {
		scanf("%d %d", &n, &r);
		
		if(n == 0)
			break;
		
		long long result = 1;
		
		//nCr=nCn-r
		r = (r < n - r) ? r : n - r;
			 
		//nCr= nPr / r!
		for (int i = 1; i <= r; i++)
		{
			result *= n;
			result /= i;
			n--;
		}
		
		printf("%lld\n", result);
	}
	
	return 0;
}