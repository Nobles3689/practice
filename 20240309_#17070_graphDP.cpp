//Beakjoon Online Judge #17070
#include <bits/stdc++.h>
using namespace std;

int N;
int house[17][17], DP[17][17];
int dy[3] = {0, 1, 1}, dx[3] = {1, 1, 0};

void move(int state, int eop_y, int eop_x){
    bool flag[4];
    for(int i = 0; i<3; i++){
        int ty = eop_y + dy[i],
        tx = eop_x + dx[i];
        if(ty > N || tx > N){
            flag[i] = false;
            continue;
        }

        if(house[ty][tx] == 0){
            flag[i] = true;
        }else{
            flag[i] = false;
        }
    }
    if(flag[0] && flag[1] && flag[2]) flag[3] = true;
    else flag[3] = false;
    

    if(state != 2 && flag[0]){
        move(0, eop_y, eop_x+1);
        DP[eop_y][eop_x+1]++;
    }
    if(flag[3]){
        move(1, eop_y+1, eop_x+1);
        DP[eop_y+1][eop_x+1]++;
    }
    if(state != 0 && flag[2]){

        move(2, eop_y+1, eop_x);
        DP[eop_y+1][eop_x]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            cin >> house[i][j];
        }
    }
    move(0, 1, 2);
    cout << DP[N][N];
    return 0;
}