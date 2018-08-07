#include <stdio.h>

/*
	č	c=
	ć	c-
	dž	dz=
	ñ	d-
	lj	lj
	nj	nj
	š	s=
	ž	z=
*/
int isCroatia(char *pStr) {
	
	if(pStr[0] == 'c' && pStr[1] == '=')
		return 2;
	
	if(pStr[0] == 'c' && pStr[1] == '-')
		return 2;
	
	if(pStr[0] == 'd' && pStr[1] == 'z' && pStr[2] == '=')
		return 3;
	
	if(pStr[0] == 'd' && pStr[1] == '-')
		return 2;
	
	if(pStr[0] == 'l' && pStr[1] == 'j')
		return 2;
	
	if(pStr[0] == 'n' && pStr[1] == 'j')
		return 2;
	
	if(pStr[0] == 's' && pStr[1] == '=')
		return 2;
		
	if(pStr[0] == 'z' && pStr[1] == '=')
		return 2;
		
	return 1;
}

int main(){
	
	char *pStr;
	int cnt; 
	
	pStr = new char[101];	
	scanf("%s", pStr);	
	cnt = 0;
	
	while(*pStr) {
		cnt++;
		pStr += isCroatia(pStr);
	}
	
	printf("%d\n", cnt);
	
	return 0;
}