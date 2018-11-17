#include <stdio.h>

struct MY_INT {
	char data[100];
	int length;
};
static MY_INT ONE;

static MY_INT _NCR[101][101];

MY_INT plus(MY_INT a, MY_INT b) {
	
	MY_INT result;
	int w=0;
	
	result.length = (a.length > b.length) ? a.length : b.length;
	for(int i=0 ; i< result.length; i++) {
		
		result.data[i] = ((a.length>i) ? a.data[i] : 0) + ((b.length>i) ? b.data[i] : 0) + w;
		w = result.data[i]/10;
		result.data[i] %= 10;
	}
	if(w>0) {
		result.data[result.length] = 1;
		result.length++;
	}
	
	return result;
}

void print(MY_INT a, bool bNewLine=false) {
	for(int i=a.length-1; i>=0; i--) {
			printf("%d", a.data[i]);
	}
	if(bNewLine)	
		printf("\n");
}

int main() {
	
	int n, r;

	ONE.data[0] = 1;
	ONE.length = 1;
	
	scanf("%d %d", &n, &r);
		
	_NCR[1][0] = ONE;
	_NCR[1][1] = ONE;
	
	for (int i=2; i<=n; i++) {
		for (int j=0; j<=i; j++) {			
			_NCR[i][j] = (i == j || j == 0) ? ONE : plus(_NCR[i-1][j-1], _NCR[i-1][j]);
		}
	}
		
	
	// for (int i=0; i<=n; i++) {
	// 	for (int j=0; j<=i; j++) {			
	// 		print(_NCR[i][j]);
	// 		printf("|");
	// 	}
	// 	printf("\n");
	// }
	
	print(_NCR[n][r]);
	
	return 0;
}
