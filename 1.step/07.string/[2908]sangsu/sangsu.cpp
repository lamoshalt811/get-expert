#include <stdio.h>

int main() {
	char str1[5], str2[5], *result;
	
	scanf("%s %s", str1, str2);
	
	result = NULL;
	if(str1[2] > str2[2]) {
		result = str1;
	} else if(str1[2] < str2[2]) {
		result = str2;
	}
	
	if(!result && str1[1] > str2[1]) {
		result = str1;
	} else if(!result && str1[1] < str2[1]) {
		result = str2;
	}
	
	if(!result && str1[0] > str2[0]) {
		result = str1;
	} else if(!result && str1[0] < str2[0]) {
		result = str2;
	}
	
	printf("%c%c%c\n",result[2], result[1], result[0]);
	
	return 0;
}