#include <stdio.h>

/*
0	1
1	1
2	2
3	6
4	24
5	120
6	720
7	5,040
8	40,320
9	362,880
10	3,628,800
11	39,916,800
12	479,001,600
13	6,227,020,800
14	87,178,291,200
15	1,307,674,368,000
16	20,922,789,888,000
17	355,687,428,096,000
18	6,402,373,705,728,000
19	121,645,100,408,832,000
20	2,432,902,008,176,640,000
21	51,090,942,171,709,440,000
22	1,124,000,727,777,607,680,000
23	25,852,016,738,884,976,640,000
24	620,448,401,733,239,439,360,000
25	15,511,210,043,330,985,984,000,000
*/

/*
5 	1	5*1
10 	1	5*2
15	1	5*3
20	1	5*2*2
25	2	5*5
30	1	5*3*2
*/

int main() {
	
	int N, i, t, cnt;
	
	scanf("%d", &N);
	
	cnt=0;
	for(i=1; i<=N; i++) {
		
		t=i;
		while(t%5 ==0) {
			t /= 5;
			cnt++;
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}