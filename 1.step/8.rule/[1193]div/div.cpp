#include <stdio.h>

int main(){
	
	int N, d, w, m;
	scanf("%d", &N);
	
	w=2;
	d=1;
	m=1;
	while(d < N) {
		d += w;
		w++;
		m++;
	}
	
	if(m % 2)
		printf("%d/%d\n", d - N + 1, m - d + N);
	else
		printf("%d/%d\n", m - d + N, d - N + 1);
	
	return 0;
}