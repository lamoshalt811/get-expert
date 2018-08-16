#include <cstdio>
#include <cmath>
#include <cassert>

static const int N = 100000, M = 15;
static const int FRIEND_N = 3;
static const int DUMMY_SIZE = 3000;

static int dummy1[DUMMY_SIZE];

static double like[N][M];
static int res[N][FRIEND_N], res_n[N];

static int dummy2[DUMMY_SIZE];

static const int seed = 810;


// #################################
// RANDOM NUMBER GENERATOR FROM HERE
unsigned long long _rx = 0;
inline void srrand(int seed){
	_rx = seed % (1ll<<32);
}
inline int irand(){
	int ret = (_rx >> 16) & (32767);
	_rx = (_rx * 22695477 + 1) % (1ll<<32);
	return ret;
}
// real number from [-1  ...  1]
inline double rrand(){
	return 2 * double(irand() * 0x7FFF + irand()) / (0x40000000) - 1;
}
// RANDOM NUMBER GENERATOR UNTIL HERE
// ##################################

extern void FindFriend(double like[N][M]);

void Report(int p, int f){
	if(p < 0 || p >= N) return;
	if(f < 0 || f >= N) return;
	if(res_n[p] == FRIEND_N) return;
	if(p == f) return;
	for(int j = 0; j < res_n[p]; ++j) if(res[p][j] == f) return;
	res[p][res_n[p]++] = f;
}

static double calc_friendliness(int A, int B){
	double ret = 0;
	for(int i = 0; i < M; ++i) ret += like[A][i] * like[B][i];
	return ret;
}

double score(double avgd){
	if(avgd < 0.50) return 0;
	return 3678 * exp((avgd - 0.685) / 0.065);
}

int main(){
	srrand(seed);

	double ans = 0;

	for(int i = 0; i < N; ++i){
		double square_sum = 0;
		for(int j = 0; j < M; ++j){
			like[i][j] = rrand();
			square_sum += like[i][j] * like[i][j];
		}
		square_sum = sqrt(square_sum);
		for(int j = 0; j < M; ++j) like[i][j] /= square_sum;

		res_n[i] = 0;
	}

	FindFriend(like);

	for(int i = 0; i < DUMMY_SIZE; ++i) assert(!dummy1[i]);
	for(int i = 0; i < DUMMY_SIZE; ++i) assert(!dummy2[i]);

	for(int i = 0; i < N; ++i){
		double my_fr = 0;
		for(int j = 0; j < res_n[i]; ++j) my_fr += calc_friendliness(i, res[i][j]);
		for(int j = res_n[i]; j < FRIEND_N; ++j) my_fr += -1;
		ans += my_fr / FRIEND_N;
	}

	printf("RESULT %.0f\n", score(ans / N));
	return 0;
}