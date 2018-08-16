extern void Report(int p, int f);

static const int N = 100000, M = 15;

void FindFriend(double like[100000][15]) {
	for(int i = 0; i < N; ++i){
		
		Report(i, (i+1)%N);
		Report(i, (i+2)%N);
		Report(i, (i+3)%N);
	}
}