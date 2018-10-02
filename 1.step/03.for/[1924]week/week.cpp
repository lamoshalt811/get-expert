#include <stdio.h>

int main(){
	
	int mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	char prn[][5] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
	int x, y, days;
	
	scanf("%d %d", &x ,&y);
	
	days = 0;
	for(int i=0; i<x-1; i++) {
		days += mon[i];
	}
	days += y;
	
	printf("%s\n", prn[days%7]);
	
	return 0;
}