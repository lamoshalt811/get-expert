#include <stdio.h>
#include <algorithm>
#include <limits.h>
FILE *in = stdin, *out = stdout;
#define MaxV 100000//1000
#define MaxT 262143//2047
int V, E, T, Q;
int Big[3];
struct edge {
	int n, len;
} Edge[MaxV + 1][5];
int Cnt[MaxV + 1];
struct dis {
	int n;
	int d[3];
} Dis[MaxV + 1];
bool Used[MaxV + 1];
struct min {	
	int value;
	int index;
} Min[MaxT + 1];
bool Answer[MaxV + 1];
void Input(void) {
	int i, a, b, c;
	fscanf(in, "%d", &V);
	fscanf(in, "%d%d%d", &Big[0], &Big[1], &Big[2]);
	fscanf(in, "%d", &E);
	for (i = 1; i <= E; i++) {
		fscanf(in, "%d%d%d", &a, &b, &c);
		Edge[a][Cnt[a]].n = b;
		Edge[a][Cnt[a]].len = c;
		Cnt[a] ++;

		Edge[b][Cnt[b]].n = a;
		Edge[b][Cnt[b]].len = c;
		Cnt[b] ++;
	}
}
bool Compare_Dis(dis a, dis b) {
	if (a.d[0] == b.d[0]) {
		if (a.d[1] == b.d[1]) return a.d[2] < b.d[2];
		return a.d[1] < b.d[1];
	}
	return a.d[0] < b.d[0];
}
bool Compare_Dis0(dis a, dis b) {
	return a.d[0] < b.d[0];
}
bool Compare_Dis1(dis a, dis b) {
	return a.d[1] < b.d[1];
}
bool Compare_Dis2(dis a, dis b) {
	return a.d[2] < b.d[2];
}
void Renew_Min(int value, int index) {
	int n = T / 2 + index;
	Min[n].value = value;
	Min[n].index = index;
	for (n /= 2; n>0; n /= 2) {
		if (Min[n * 2].value < Min[n * 2 + 1].value) Min[n] = Min[n * 2];
		else Min[n] = Min[n * 2 + 1];
	}
}
void GetDis(void) {
	int b, i;
	int n, m, r;
	int len;
	for (i = 1; i <= V; i++) Dis[i].n = i;
	for (b = 0; b<3; b++) {
		for (i = 1; i <= T; i++) Min[i].value = INT_MAX;
		for (i = 1; i <= V; i++) Used[i] = false;
		Renew_Min(0, Big[b]);
		while (Min[1].value != INT_MAX) {
			n = Min[1].index;
			r = Min[1].value;
			Used[n] = true;
			Dis[n].d[b] = r;
			Renew_Min(INT_MAX, n);
			for (i = 0; i<Cnt[n]; i++) {
				m = Edge[n][i].n;
				len = Edge[n][i].len;
				if (!Used[m] && Min[T / 2 + m].value > r + len)
					Renew_Min(r + len, m);
			}
		}
	}
}
void ReLabeling() {
	int i, cnt;
	std::sort(Dis + 1, Dis + V + 1, Compare_Dis0);
	for (i = 1, cnt = 1; i<V; i++) {
		if (Dis[i].d[0] == Dis[i + 1].d[0]) Dis[i].d[0] = cnt;
		else Dis[i].d[0] = cnt++;
	}
	Dis[V].d[0] = cnt;
	std::sort(Dis + 1, Dis + V + 1, Compare_Dis1);
	for (i = 1, cnt = 1; i<V; i++) {
		if (Dis[i].d[1] == Dis[i + 1].d[1]) Dis[i].d[1] = cnt;
		else Dis[i].d[1] = cnt++;
	}
	Dis[V].d[1] = cnt;
	std::sort(Dis + 1, Dis + V + 1, Compare_Dis2);
	for (i = 1, cnt = 1; i<V; i++) {
		if (Dis[i].d[2] == Dis[i + 1].d[2]) Dis[i].d[2] = cnt;
		else Dis[i].d[2] = cnt++;
	}
	Dis[V].d[2] = cnt;
}
int FindMin(int right) {
	int left = T / 2 + 1;
	int r = INT_MAX;
	if (right <= T / 2) return INT_MAX;
	while (left <= right) {
		if (r>Min[left].value) r = Min[left].value;
		if (r>Min[right].value) r = Min[right].value;
		left = (left + 1) / 2;
		right = (right - 1) / 2;
	}
	return r;
}
void Check(void) {
	int i, p;
	for (i = 1; i <= T; i++) Min[i].value = INT_MAX;
	p = 1;
	for (i = 1; i <= V; i++) {
		if (FindMin(T / 2 + Dis[i].d[1] - 1) < Dis[i].d[2]) Answer[Dis[i].n] = false;
		else Answer[Dis[i].n] = true;
		if (i == V || Dis[i].d[0] != Dis[i + 1].d[0]) {
			for (; p <= i; p++) {
				if (Min[T / 2 + Dis[p].d[1]].value > Dis[p].d[2])
					Renew_Min(Dis[p].d[2], Dis[p].d[1]);
			}
		}
	}
}
void Process(void) {
	for (T = 1; T<V; T *= 2);
	T = T * 2 - 1;
	GetDis();
	ReLabeling();
	std::sort(Dis + 1, Dis + V + 1, Compare_Dis);
	Check();
}
void Output(void) {
	int i, n;
	fscanf(in, "%d", &Q);
	for (i = 1; i <= Q; i++) {
		fscanf(in, "%d", &n);
		if (n == 0) break;
		if (Answer[n] == true) fprintf(out, "YES\n");
		else fprintf(out, "NO\n");
	}
}
int main(void) {
	Input();
	Process();
	Output();
	return 0;
}