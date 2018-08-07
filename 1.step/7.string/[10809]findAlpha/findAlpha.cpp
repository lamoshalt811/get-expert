#include <stdio.h>

int main() {
	
	char str [101];
	int i, arr[26];
	
	for(i=0; i<26; i++) {
		arr[i] = -1;
	}
	
	scanf("%s", str);
	
	for(i=0; str[i]; i++) {
		int index = str[i] - 'a';
		if( arr[index] < 0 ) {
			arr[index] = i;
		}
	}
	
	for(i=0; i<26; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}