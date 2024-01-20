//Beakjoon Online Judge #2573
#include <bits/stdc++.h>
using namespace std;

int n, m;
int sea[300][300];
int sea_copy[300][300];
bool checked[300][300];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };


void copy(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            sea[i][j] = sea_copy[i][j];
        }
    }
}

void DFS(int y, int x){
    int tx, ty;
    checked[y][x] = true;
    for(int i = 0; i<4; i++){
        ty = y + dy[i];
        tx = x + dx[i];
        if(!checked[ty][tx] && sea[ty][tx] != 0){
            DFS(ty, tx);
        }
    }
}


void malt_cal(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int malt = 0;
            if(sea[i][j] != 0){
                
                for(int k = 0; k<4; k++){
                    if(sea[i+dy[k]][j+dx[k]] == 0) malt++;
                }
                if(sea[i][j] < malt){
                    sea_copy[i][j] = 0;
                }else{
                    sea_copy[i][j] = sea[i][j] - malt;
                }
            }
        }
    }
    copy();
}

int cal(){
    int years = 0;
    while (1)
    {   
        for(int z = 0; z<n; z++)
            memset(checked[z], false, sizeof(bool) * m);
        int cnt = -1;
        for(int i = 1; i<n-1; i++){
            for(int j = 1; j<m-1; j++){
                if(sea[i][j] != 0 && !checked[i][j]){
                    DFS(i,j);
                    cnt++;
                }
            }
        }
        if(cnt == -1){
            years = 0;
            break;
        }else if(cnt == 0){
            malt_cal();
            years++;
        }else{
            break;
        }
    }
    return years;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> sea[i][j];
        }
    }
    cout << cal();
    return 0;
}