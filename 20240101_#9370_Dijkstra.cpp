//Beakjoon Online Judge #9370
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 9999999

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
    int testCase;
    cin >> testCase;

    for(int i = 0; i<testCase; i++)
    {    
        int n, m, t;// 각각 교차로(노드), 도로(간선), 목적지 후보의 개수
        cin >> n >> m >> t;
        int s, g, h;// 출발지, 최단경로가 g, h사이의 간선을 지나야함
        cin >> s >> g >> h;
        vector<pair<int, int>> graph[n];
        vector<int> goal;
        int stopover_cost, cost, stopover;
        for(int j = 0; j<m; j++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            if((a == g && b == h) || (a == h && b == g)) stopover_cost = d;
            graph[a-1].push_back({b-1, d});
            graph[b-1].push_back({a-1, d});
        }
        for(int j = 0; j<t; j++){
            int tmp;
            cin >> tmp;
            goal.push_back(tmp);
        }
        sort(goal.begin(), goal.end());
        vector<int> res1 = dijkstra(s-1, n, graph);
        if(res1[g-1] > res1[h-1]){
            cost = res1[h-1];
            stopover = g;
        }else{
            cost = res1[g-1];
            stopover = h;
        }
        vector<int> res2 = dijkstra(stopover-1, n, graph);
        for(int j = 0; j<t; j++){
            if(res1[goal[j]-1] == cost + stopover_cost + res2[goal[j]-1]){
                cout << goal[j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}