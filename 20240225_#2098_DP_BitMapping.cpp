//Beakjoon Online Judge #2098
#include <bits/stdc++.h>
using namespace std;
#define INF 1e8
int n, W[16][16], dp[16][65536];

int visited(int bits, int city){
    return bits | (1 << city);
}

int TSP(int now, int path){
    if(path == (1 << n) - 1){
        return (W[now][0] != 0)?W[now][0]:INF;
    }
    if(dp[now][path] != -1) return dp[now][path];
    dp[now][path] = INF;
    for(int i = 0; i<n; ++i){
        if(!(path & (1 << i)) && W[now][i] != 0){
            dp[now][path] = min(TSP(i, visited(path, i)) + W[now][i], dp[now][path]);
        }
    }
    return dp[now][path];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> W[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        fill_n(dp[i], size(dp[i]), -1);
    }
    cout << TSP(0, 1);
    return 0;

}