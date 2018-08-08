#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 1000000007;

int n;
char board[N][N];
int dp[2][N][N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%s", board[i] + 1);
    }
    dp[1][1][n] = (board[1][1] == board[n][n]);
    for(int t = 2; t <= n; t++){
        for(int i = 1; i <= n; i++){
            for(int k = 1; k <= n; k++){
                dp[t&1][i][k] = 0;
                int j = t + 1 - i;
                int l = 2 * n + 1 - t - k;
                if(j < 1 || j > n || l < 1 || l > n) continue;
                if(board[i][j] != board[k][l]) continue;
                for(int x = -1; x <= 0; x++)
                    for(int y = 0; y <= 1; y++)
                        dp[t&1][i][k] = (dp[t&1][i][k] + dp[~t&1][i+x][k+y]) % M;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = (ans + dp[n&1][i][i]) % M;
    printf("%d", ans);
}