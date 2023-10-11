//Beakjoon Online Judge #1504
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 999999

pair<int, int> list[5] = { {0,2}, {0,3}, {2,3}, {1,2}, {1,3} };

vector<int> dijkstra(int start, int n, vector<pair<int, int>> graph[]){
    vector<int> res(n+1, INF);
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
    int node, edge;
    cin >> node >> edge;
    vector<pair<int, int>> graph[node+1];
    for(int i = 0; i<edge; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }
    int stopover_1, stopover_2;
    cin >> stopover_1 >> stopover_2;
    vector<int> tmp[4];
    tmp[0] = dijkstra(1, node, graph);
    tmp[1] = dijkstra(node, node, graph);
    tmp[2] = dijkstra(stopover_1, node, graph);
    tmp[3] = dijkstra(stopover_2, node, graph);
    vector<int> res(6, INF);

    for(int i = 1; i<=node; i++){
        for(int j = 0; j<5; j++){
            res[j] = min(res[j], tmp[list[j].first][i] + tmp[list[j].second][i]);
        }
    }
    
    res[5] = min(res[0]+res[2]+res[4], res[1]+res[2]+res[3]);
    if(res[0]>=INF||res[1]>=INF||res[2]>=INF||res[3]>=INF||res[4]>=INF){
        res[5] = -1;
    }
    
    cout << res[5];
    
    
    return 0;
}