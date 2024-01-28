//Beakjoon Online Judge #12100
#include <bits/stdc++.h>
using namespace std;

int n, res = 0;
int board[21][21];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void copy(int a[][21], int b[][21]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            a[i][j] = b[i][j];
        }
    }
}

void find(int a[][21]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            res = max(res, a[i][j]);
        }
    }
}

void move(int a[][21], int dist){
    bool is_merged[n][n] = { 0, };
    switch (dist)
    {
    case 0:
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){ 
                if(a[i][j] != 0){
                    for(int k = i; k > 0; k--){
                        if(a[k-1][j] != 0){
                            if(a[k-1][j] == a[k][j] && (!is_merged[k-1][j])){
                                a[k-1][j] *= 2;
                                is_merged[k-1][j] = true;
                                a[k][j] = 0;
                            }
                            break;
                        }
                        else{
                            a[k-1][j] = a[k][j];
                            a[k][j] = 0;
                            is_merged[k-1][j] = is_merged[k][j];
                            is_merged[k][j] = false;
                        }
                    }
                
                }
            
            }
        }
        break;
    case 1:
        for(int i = n-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                if(a[i][j] != 0){
                    for(int k = i; k < n-1; ++k){
                        if(a[k+1][j] != 0){
                            if(a[k+1][j] == a[k][j] && (!is_merged[k+1][j])){
                                a[k+1][j] *= 2;
                                is_merged[k+1][j] = true;
                                a[k][j] = 0;
                            }
                            break;
                        }
                        else{
                            a[k+1][j] = a[k][j];
                            a[k][j] = 0;
                            is_merged[k+1][j] = is_merged[k][j];
                            is_merged[k][j] = false;
                        }
                    }
                
                }
            }
        }
        break;
    case 2:
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){ 
                if(a[i][j] != 0){
                    for(int k = j; k > 0; k--){
                        if(a[i][k-1] != 0){
                            if(a[i][k-1] == a[i][k] && (!is_merged[i][k-1])){
                                a[i][k-1] *= 2;
                                is_merged[i][k-1] = true;
                                a[i][k] = 0;
                            }
                            break;
                        }
                        else{
                            a[i][k-1] = a[i][k];
                            a[i][k] = 0;
                            is_merged[i][k-1] = is_merged[i][k];
                            is_merged[i][k] = false;
                        }
                    }
                
                }
            
            }
        }
        break;
    case 3:
        for(int i = n-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                if(a[i][j] != 0){
                    for(int k = j; k < n-1; ++k){
                        if(a[i][k+1] != 0){
                            if(a[i][k+1] == a[i][k] && (!is_merged[i][k+1])){
                                a[i][k+1] *= 2;
                                is_merged[i][k+1] = true;
                                a[i][k] = 0;
                            }
                            break;
                        }
                        else{
                            a[i][k+1] = a[i][k];
                            a[i][k] = 0;
                            is_merged[i][k+1] = is_merged[i][k];
                            is_merged[i][k] = false;
                        }
                    }
                
                }
            }
        }
        break;
    default:
        break;
    }
    find(a);
}

void play_2048(int cnt, int prev_board[][21], int dist){
    if(cnt == 5) return;
    int tmp_board[21][21];
    copy(tmp_board, prev_board);
    move(tmp_board, dist);

    for(int a = 0; a<4; a++){
        play_2048(cnt+1, tmp_board, a);
    }
    


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i<4; i++){
        play_2048(0, board, i);
    }
    
    cout << res;
    return 0;
}
