#include <stdio.h>

static int cnt[31];
static char kind[31][21];
static int size=0;

bool strcmp(char *s1, char *s2) {
	
	int i=0;
	while(s1[i]) {
		if(s1[i] != s2[i]) {
			return 0;
		}
		i++;
	}
	
	return s1[i] == s2[i];
}

void insert(char * str) {
	
	int i;
	
	for(i=0; i<size; i++) {
		if(strcmp(kind[i], str)) {
			cnt[i]++;
			return;
		}
	}	
	
	i=0;
	do {
		kind[size][i] = str[i];		
	}while(str[i++]);
	cnt[size] = 1;
	size++;
}

int main() {

	char str1[21], str2[21];
	int T, n, i, sum;
	
	scanf("%d", &T);
	
	while(T--) {
		
		scanf("%d", &n);
		
		size=0;
		for(i=0; i<n; i++) {
			scanf("%s %s", str1, str2);			
			insert(str2);
		}
		
		if(size == 0) {
			printf("0\n");
		} else {
			sum=1;
			for(i=0; i<size; i++) {
				sum *= (cnt[i] + 1);
			}
			--sum;
			printf("%d\n", sum);
		}
	}
	
	return 0;
}