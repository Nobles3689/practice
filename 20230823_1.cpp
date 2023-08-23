//Beakjoon Online Judge #1753
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
    int v, e, k;
    cin >> v >> e >> k;
    vector<pair<int, int>> graph[v];
    for(int i = 0; i<e; i++){
        int start, goal, cost;
        cin >> start >> goal >> cost;
        graph[start-1].push_back({goal-1, cost});
    }
    vector<int> res = dijkstra(k-1, v, graph);


    for(int i = 0; i<v; i++){
        if(res[i]==INF)
            cout << "INF\n";
        else
            cout << res[i] << '\n';
    }
    return 0;
}