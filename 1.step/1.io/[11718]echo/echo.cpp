#include <stdio.h>
int main() {
	int i=0;
	char j;
	while (1) {
		j=getchar();
		if (j == EOF)
			break;
		putchar(j);
	}
}