#include <stdio.h>

bool arr[10001];
int d(int n);

int main(void) {
    
    for(int i=1; i<=10000; i++) {
        if(!arr[i]) {
            printf("%d\n", i);         
        }
        arr[d(i)] = true;
    }

    return 0;
}

int d(int n) {
    int sum = n;
    while(n > 0) {
        sum+=n%10;
        n/=10;
    }
    return sum;
}