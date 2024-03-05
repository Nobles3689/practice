//Beakojoon Online Judge #2533
#include <bits/stdc++.h>
using namespace std;

int n, u, v;
vector<vector<int>> tree;
int dp[1000001][2];
bool visited[1000001];

void SNS(int node){
    visited[node] = true;
    dp[node][0] = 1;
    for(int i = 0; i<tree[node].size(); i++){
        int tmp = tree[node][i];
        if(visited[tmp]) continue;
        SNS(tmp);
        dp[node][1] += dp[tmp][0];
        dp[node][0] += min(dp[tmp][0], dp[tmp][1]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    tree = vector<vector<int>>(n+1, vector<int>());
    for(int i = 0; i<n-1; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    SNS(1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}