//Beakjoon Online Judge #1005
#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int cal(int target, vector<int> &cost, vector<vector<int>> &graph, vector<int> &dp){
    if(dp[target]==-1){
        int ans = 0;
        for(int i = 0; i<graph[target].size(); i++){
            ans = max(ans, cal(graph[target][i], cost, graph, dp));
        }
        ans+=cost[target];
        dp[target] = ans;
    }
    return dp[target];


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for(int z = 0; z<tc; z++){
        int buil, cost_n;
        cin >> buil >> cost_n;
        vector<int> cost_v(buil+1);
        vector<vector<int>> graph(buil+1);
        vector<int> dp(buil+1, -1);
        for(int i = 1; i<=buil; i++){
            cin >> cost_v[i];
        }
        for(int i = 0; i<cost_n; i++){
            int cond, goal;
            cin >> cond >> goal;
            graph[goal].push_back(cond);
        }
        int target;
        cin >> target;
        cout << cal(target, cost_v, graph, dp) << '\n';
    }
    return 0;
}