#include <stdio.h>

static int r1, c1, r2, c2, min, max;
static int map[50][5];

void write(int i, int j, int n) {
	
	int r = i + min;
	int c = j + min;	
	
	if(r1 <= r && r <= r2 && c1 <= c && c <= c2) {
		map[r - r1][c - c1] = n;
	}
}

void topLeft(int s, int n) {
	int m = (2*n+1) * (2*n+1) - 4*n;
	write(s, s, m);
	
	for(register int i=1; i <= 2*n; i++) {
		write(s, s+i, m-i);
		write(s+i, s, m+i);
	}
}

void bottomRight(int s, int n) {
	int m = (2*n+1) * (2*n+1);
	write(s, s, m);	
	for(register int i=1; i <= 2*n-1; i++) {
		write(s, s-i, m-i);
	}
		
	n--;
	m = (2*n+1) * (2*n+1);	
	for(register int i=1; i <= 2*n+1; i++) {
		write(s-i, s, m+i);
	}	
}

void printMap() {
	
	int max, cnt;
	max=0;
	for(int i=0; i<=r2-r1; i++) {
		for(int j=0; j<=c2-c1; j++) {
			if(max < map[i][j]) 
				max = map[i][j];
		}
	}

	cnt=0;
	while(max) {
		cnt++;
		max/=10;
	}
	
	for(int i=0; i<=r2-r1; i++) {
		for(int j=0; j<=c2-c1; j++) {
			printf("%*d ", cnt, map[i][j]);
		}
		printf("\n");
	}
	
}

int main() {
	
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	
	min = (r1 < c1) ? r1 : c1;
	max = (r2 > c2) ? r2 : c2;	
	
	for(register int i=0; i<=max-min; i++) {
		int n = min + i;
		
		if(n < 0) {
			topLeft(i, -n);
		} else if (n > 0) {
			bottomRight(i, n);
		} else 
			write(i, i, 1);
	}
	
	printMap();
		
	return 0;
}