//Beakjoon Online Judge #4963
#include <bits/stdc++.h>
using namespace std;

int n, m;
int sea[50][50];
bool check[50][50];
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1};

void reset(){
    for(int i = 0; i<m; i++){
        memset(sea[i], 0, sizeof(int)*n);
        memset(check[i], false, sizeof(bool)*n);
    }
}

void DFS(int y, int x){
    int tx, ty;
    check[y][x] = true;
    for(int i = 0; i<8; i++){
        ty = y + dy[i];
        tx = x + dx[i];
        if(tx < 0 || tx >= n || ty < 0 || ty >= m){
            continue;
        }
        if(sea[ty][tx] == 1 && !check[ty][tx]){
            DFS(ty, tx);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true)
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cin >> sea[i][j];
            }
        }
        int cnt = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(sea[i][j] == 1 && !check[i][j]){
                    DFS(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        reset();
    }
    return 0;
    
}