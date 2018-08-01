#include <iostream>
#include <stdio.h>
using namespace std;

int T;

void solve(char *pStr) {
	int OCount = 0;
	int score = 0;	
	
	while(*pStr) {
		if (*pStr == 'X') {
			OCount = 0;
		}
		else {
			OCount++;
		}
		score += OCount;
		pStr++;
	}
	
	printf("%d\n", score);
}

int main()
{
	char input[82];
	cin >> T;
	for (int i = 0; i < T; i++) {
		scanf("%s", &input);
		solve(input);
	}

	return 0;
}