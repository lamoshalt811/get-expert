#include <stdio.h>

void space(int n);
void floor1(int n); 
void floor2(int n); 
void floor3(int n); 
int count(int n);

int main(void) {
    
    int i=0;
    int n = 6;
    // scanf("%d", &n);

    while(i<n) {
        int cnt = count((i+3)/3);
        for(int j=0;j<cnt;j++)
            floor1(n-i);
        printf("\n");
        for(int j=0;j<cnt;j++)
            floor2(n-i);
        printf("\n");
        for(int j=0;j<cnt;j++)
            floor3(n-i);
        printf("\n");   
        i+=3;
    }

    return 0;
}

void space(int n) {
    while(n--) {
        printf(" ");
    }
}

void floor1(int n) {
    space(n-1);
    printf("*");
    space(n-1);
}

void floor2(int n) {
    space(n-2);
    printf("* *");
    space(n-2);
}

void floor3(int n) {
    space(n-3);
    printf("*****");
    space(n-3);
}

int count(int n) {
    if(n==1)
        return 1;
    return 2 * count(n/2);
}