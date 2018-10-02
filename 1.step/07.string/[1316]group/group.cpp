#include <stdio.h>

int main(){
	
	bool check[26];
	char str[101];
	int cnt=0;
	int i, N;
	
	scanf("%d", &N);
	
	while(N--) {
		scanf("%s", str);
		
		for(i=0; i<26; i++) {
			check[i] = false;
		}
		
		check[str[0] - 'a'] = true;			
		cnt++;
		
		for(i=1; str[i]; i++) {
			if(check[str[i] - 'a'] && str[i] != str[i-1] ) {
				cnt--;
				break;
			} else {
				check[str[i] - 'a'] = true;
			}
		}
		
	}
	
	printf("%d\n", cnt);	
}