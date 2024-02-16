//Beakjoon Online Judge #1937
#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
int forest[500][500];
int DP[500][500];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };


int panda(int y, int x){
    if(DP[y][x] != 0) return DP[y][x];
    DP[y][x] = 1;

    int ty, tx;
    for(int i = 0; i<4; i++){
        ty = y + dy[i];
        tx = x + dx[i];
        if(ty < 0 || ty >= n || tx < 0 || tx >= n){
            continue;
        }
        if(forest[y][x] < forest[ty][tx]){
            DP[y][x] = max(panda(ty, tx)+1, DP[y][x]);
        }
    }
    if(DP[y][x] > ans) ans = DP[y][x];
    return DP[y][x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            cin >> forest[i][j];
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            panda(i, j);
        }
            
    }
    cout << ans;
    return 0;
}