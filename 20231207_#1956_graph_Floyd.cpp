//Beakjoon Online Judge #1956
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define INF 1e12

ll dp[401][401] = {0, };

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
        int s, g;
        ll c;
        cin >> s >> g >> c;
        dp[s][g] = min(dp[s][g], c);
    }

    Floyd(v);
    ll res = INF;
    for(int i = 1; i<=v; i++){
        for(int j = 1; j<=v; j++){
            if(i==j) continue;
            res = min(res, dp[i][j] + dp[j][i]);
        }
    }
    if(res >= INF) cout << -1;
    else cout << res;
    return 0;
}