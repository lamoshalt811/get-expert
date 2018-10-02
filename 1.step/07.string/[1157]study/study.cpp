#include <stdio.h>

int main(){
	
	int cnt[26], max;
	char c, prn;
	
	for(int i=0; i<26; i++) {
		cnt[i] = 0;
	}
	
	while(true) {
		c = getchar();
		
		if(!c || c == '\n')
			break;
		
		if(c < 'a') {
			cnt[c-'A']++;
		} else {
			cnt[c-'a']++;
		}
	}
	
	max = -1;
	for(int i=0; i<26; i++) {
		if(max < cnt[i]) {
			prn = 'A' + i;
			max = cnt[i];
		} else if( max == cnt[i]) {
			prn = '?';
		}
	}
	
	printf("%c\n", prn);
}