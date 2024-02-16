//Beakjoon Online Judge #1937
//최댓값 수정시 최대값이 나오는 경로를 다시 한번씩 방문해서 수정해야하기에 시간초과 발생
#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
int forest[500][500];
int DP[500][500];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };


void panda(int y, int x, int cnt){
    if(DP[y][x] >= cnt) return;
    DP[y][x] = cnt;
    if(cnt > ans) ans = cnt;
    int ty, tx;
    for(int i = 0; i<4; i++){
        ty = y + dy[i];
        tx = x + dx[i];
        if(ty < 0 || ty >= n || tx < 0 || tx >= n){
            continue;
        }
        if(forest[y][x] > forest[ty][tx]){
            panda(ty, tx, cnt+1);
        }
    }
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
            if(DP[i][j] == 0)
                panda(i, j, 1);
        }
            
    }
    cout << ans;
    return 0;
}