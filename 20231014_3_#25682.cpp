//Beakjoon Online Judge #25683
#include <iostream>
#include <vector>
using namespace std;

int board[2001][2001] = { 0, };
int sumB[2001][2001] = {0, };
int sumW[2001][2001] = {0, };
int n, m, k;

void calB(){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            sumB[i][j] = sumB[i-1][j] + sumB[i][j-1] - sumB[i-1][j-1];
            if((i+j)%2==0){
                if(board[i][j]!=-1)
                    sumB[i][j]++;
            }else{
                if(board[i][j]==-1)
                    sumB[i][j]++;
            }
        }
    }

}
void calW(){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            sumW[i][j] = sumW[i-1][j] + sumW[i][j-1] - sumW[i-1][j-1];
            if((i+j)%2==0){
                if(board[i][j]!=1)
                    sumW[i][j]++;
            }else{
                if(board[i][j]==1)
                    sumW[i][j]++;
            }
        }
    }
}

int cal(){
    calB();
    calW();
    int tmpB, tmpW;
    int res = 4000000;
    for(int i = k; i<=n; i++){
        for(int j = k; j<=m; j++){
            tmpB = sumB[i][j] - sumB[i-k][j] - sumB[i][j-k] + sumB[i-k][j-k];
            tmpW = sumW[i][j] - sumW[i-k][j] - sumW[i][j-k] + sumW[i-k][j-k];
            res = min(res, min(tmpB, tmpW));
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            char tmp;
            cin >> tmp;
            if(tmp == 'B') board[i][j] = -1;
            else board[i][j] = 1;
        }
    }
    cout << cal();
    return 0;

}