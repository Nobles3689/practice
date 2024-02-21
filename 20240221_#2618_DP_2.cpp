//Beakjoon Online Judge #2618
#include <bits/stdc++.h>
using namespace std;
int n, w, dp[1001][1001], c[1001][1001], e[1001][2];
int dis(int d, int a, int b){
    return abs((a?e[a][0]:d)-e[b][0])+abs((a?e[a][1]:d)-e[b][1]);
}

int cal_dp(int i, int j){
    int k = max(i,j)+1;
    if(k>w) return 0;
    if(c[i][j]) return dp[i][j];
    int dis1 = cal_dp(k, j) + dis(1, i, k);
    int dis2 = cal_dp(i, k) + dis(n, j, k);
    if(dis1 < dis2){ c[i][j] = 1; dp[i][j] = dis1; }
    else{ c[i][j] = 2; dp[i][j] = dis2; }
    return dp[i][j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> w;
    for(int i = 1; i<=w; i++){
        cin >> e[i][0] >> e[i][1];
    }
    cout << cal_dp(0, 0) << '\n';
    
    int i = 0, j = 0;
    for(int k = 1; k<=w; k++){
        if(c[i][j] == 1){ cout << "1\n"; i=k; }
        else if(c[i][j] = 2){ cout << "2\n"; j=k; }
    }
    return 0;
}