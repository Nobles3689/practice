//Beakjoon Online Judge #1238
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 999999

vector<int> dijkstra(int start, int n, vector<pair<int, int>> graph[]){
    vector<int> res(n, INF);
    priority_queue<pair<int, int>> q;
    res[start] = 0;
    q.push({0, start});

    while (!q.empty())
    {
        int tmp_dis = -q.top().first;
        int tmp_node = q.top().second;
        q.pop();

        for(int i = 0; i<graph[tmp_node].size(); i++){
            int n_node = graph[tmp_node][i].first;
            int n_dis = tmp_dis + graph[tmp_node][i].second;

            if(n_dis<res[n_node]){
                res[n_node] = n_dis;
                q.push({-n_dis, n_node});
            }
        }
    }
    return res;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x;
    cin >> n >> m >> x;
    vector<pair<int, int>> graph[n];
    for(int i = 0; i<m; i++){
        int start, goal, cost;
        cin >> start >> goal >> cost;
        graph[start-1].push_back({goal-1, cost});
    }
    vector<int> res[n];
    for(int i = 0; i<n; i++){
        res[i] = dijkstra(i, n, graph);
    }

    vector<int> ans = res[x-1];
    for(int i = 0; i<n; i++){
        ans[i]+=res[i][x-1];
    }
    sort(ans.begin(), ans.end());

    cout << ans[n-1];
    return 0;
}