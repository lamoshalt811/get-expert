#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>

const int SIGNAL_LEN = 5000;
const int PATTERN_LEN = 80;
const int OCCURENCE = 30;
const int NOISE_CNT = 2000;
const int DUMMY_SIZE = 3000;

static char pattern[PATTERN_LEN];
static char signal[SIGNAL_LEN];

static int dummy1[DUMMY_SIZE];

static int occur[OCCURENCE];
static int occur_chk[OCCURENCE];
static int found[OCCURENCE], fn;

static int dummy2[DUMMY_SIZE];

extern void FindPattern(char signal[5000], char pattern[80]);

void Report(int p){
	if(p < 0 || p + PATTERN_LEN - 1 >= SIGNAL_LEN) return;
	if(fn == OCCURENCE) return;
	found[fn++] = p;
}

static const int seed = 180810;

int main(){
	srand(seed);

	long long success = 0;
	long long total = 0;

	for(int trial = 0; trial < 500; ++trial){
		pattern[0] = 1;
		for(int i = 1; i < PATTERN_LEN; ++i)
			pattern[i] = (rand() & 1);

		// finds nonoverlapping random occurences;
		// uses combinatorics
		for(int i = 0, gap = SIGNAL_LEN - PATTERN_LEN * OCCURENCE; i < OCCURENCE; ++i){
			int c = OCCURENCE - i;
			double r = double(rand()) / RAND_MAX;
			double p = 1. * c / (gap + c);
			for(int k = 0; k <= gap; ++k){
				if(r <= p || k == gap){
					occur[i] = k;
					if(i) occur[i] += occur[i-1] + PATTERN_LEN;
					gap -= k;
					break;
				}
				r -= p;
				p *= (double(gap - k) /(gap + c - (k + 1)));
			}
		}

		for(int i = 0; i < OCCURENCE; ++i) assert(0 <= occur[i] && occur[i] < SIGNAL_LEN);
		for(int i = 1; i < OCCURENCE; ++i) assert(occur[i-1] + PATTERN_LEN <= occur[i]);

		for(int i = 0; i < SIGNAL_LEN; ++i) signal[i] = (rand() & 1);

		for(int i = 0; i < OCCURENCE; ++i){
			for(int j = 0; j < PATTERN_LEN; ++j)
				signal[occur[i] + j] = pattern[j];
		}

		for(int i = 0; i < NOISE_CNT; ++i){
			signal[rand() % SIGNAL_LEN] ^= 1;
		}

		fn = 0;
		FindPattern(signal, pattern);

		for(int i = 0; i < DUMMY_SIZE; ++i) assert(!dummy1[i]);
		for(int i = 0; i < DUMMY_SIZE; ++i) assert(!dummy2[i]);

		for(int i = 0; i < OCCURENCE; ++i) occur_chk[i] = 0;
		for(int i = 0; i < fn; ++i){
			int p = std::lower_bound(occur, occur + OCCURENCE, found[i]) - occur;
			if(0 <= p && p < OCCURENCE && occur[p] == found[i]){
				occur_chk[p] = 1;
			}
		}

		for(int i = 0; i < OCCURENCE; ++i) if(occur_chk[i]) ++success;
		total += OCCURENCE;
	}

	printf("RESULT %.0f\n", success / double(total) * 12950);
	return 0;
}