//Beakjoon Online Judge #1916
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000001

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
        if(tmp_dis > res[tmp_node]) continue;
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
    int city, bus;
    cin >> city >> bus;
    vector<pair<int, int>> graph[city+1];
    for(int i = 0; i<bus; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        graph[start].push_back({end, cost});
    }
    int start, goal;
    cin >> start >> goal;
    vector<int> res = dijkstra(start, city+1, graph);
    cout << res[goal];
    return 0;
}