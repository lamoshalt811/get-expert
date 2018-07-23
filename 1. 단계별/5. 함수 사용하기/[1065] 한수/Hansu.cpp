#include <stdio.h>

bool isArithmetic(int n);

int main(void) {
    
    int n, cnt=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        isArithmetic(i) ? cnt++ : cnt;
    }
    printf("%d", cnt);

    return 0;
}

bool isArithmetic(int n) {
    int d = (n%10) - ((n/10)%10);
    while(n > 9) {
        if( d != (n%10) - ((n/10)%10))
            return false;
        n /= 10;
    }
    return true;
}