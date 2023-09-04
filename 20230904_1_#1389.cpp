//Beakjoon Online Judge #1389
#include <iostream>
#include <algorithm>
#include <vector>
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
        cin >> start >> goal;
        dp[start][goal] = 1;
        dp[goal][start] = 1;
    }

    Floyd(v);
    vector<int> tmp(v+1);
    for(int i = 1; i<=v; i++){
        for(int j = 1; j<=v; j++){
            if(i!=j)
                tmp[i]+=dp[i][j];
        }
    }
    pair<int, int> ans = {0, INF};
    for(int i = 1; i<=v; i++){
        if(tmp[i]<ans.second){
            ans.first = i;
            ans.second = tmp[i];
        }
    }
    cout << ans.first;
    
    return 0;
}