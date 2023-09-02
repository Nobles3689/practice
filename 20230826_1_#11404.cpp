//Beakjoon Online Judge #11404 플로이드 와샬 알고리즘
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 999999999

int dp[101][101] = { 0, };

void Floyd(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            for(int k = 1; k<=n; k++){
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }
}
    

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e;
    cin >> v >> e;
    for(int i = 1; i<=v; i++){
        for(int j = 1; j<=v; j++){
            if(i==j)
                dp[i][j] = 0;
            else
                dp[i][j] = INF;
        }
    }

    for(int i = 0; i<e; i++){
        int start, goal, cost;
        cin >> start >> goal >> cost;
        dp[start][goal] = min(dp[start][goal], cost);
    }

    Floyd(v);
    for(int i = 1; i<=v; i++){
        for(int j = 1; j<=v; j++){
            if(dp[i][j]==INF)
                cout << 0 << ' ';
            else
                cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}