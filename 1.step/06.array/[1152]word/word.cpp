#include <stdio.h>

int main(void) {
    int cnt=0;
    bool b=true;
    char c;
    do {
        c = getchar();
        if(c == '\n')
            break;

        if(b && c != ' ') {
            cnt++;
            b = false;
        } 
        
        if( c == ' ') {
            b = true;
        }
       
    }while(true);

    printf("%d", cnt);
    
    return 0;
}