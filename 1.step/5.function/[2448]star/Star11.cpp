#include <stdio.h>

char map[6200][6200];

void arrayCopy(int dx, int dy, int size) {
	int i, j;
	
	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			map[i+dy][j+dx] = map[i][j];
		}
	}
}

int main(void) {
    
    int i, j, n;
	scanf("%d", &n);

	//init	
	map[0][0] = '*';

	map[1][0] = '*';
	map[1][1] = ' ';
	map[1][2] = '*';
		
	map[2][0] = '*';
	map[2][1] = '*';
	map[2][2] = '*';
	map[2][3] = '*';
	map[2][4] = '*';
	
	// copy
	for(i=6; i<=n; i*=2) {
		arrayCopy(0, i/2, i-1);
		arrayCopy(i, i/2, i-1);	
	}
		
	// prn
	for(i=0; i<n; i++) {
		for(j=n-1; j>i; j--) {
			printf(" ");
		}
		for(j=0; j<(2*(i+1))-1; j++) {
			printf("%c", (map[i][j] == '*' ? '*' : ' '));
		}
		for(j=n-1; j>i; j--) {
			printf(" ");
		}
		printf("\n");
	}

    return 0;
}

/*
1 *                        
3 * *                       
5 *****                      
7 *     *                     
9 * *   * *                    
11***** *****                   
13*           *                  
15* *         * *                 
17*****       *****                
19*     *     *     *               
21* *   * *   * *   * *              
23***** ***** ***** *****             
  *                       *            
  * *                     * *           
  *****                   *****          
  *     *                 *     *         
  * *   * *               * *   * *        
  ***** *****             ***** *****       
  *           *           *           *      
  * *         * *         * *         * *     
  *****       *****       *****       *****    
  *     *     *     *     *     *     *     *   
  * *   * *   * *   * *   * *   * *   * *   * *  
  ***** ***** ***** ***** ***** ***** ***** *****
*/