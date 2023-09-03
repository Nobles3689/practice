//Beakjoon Online Judge #1260
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool check[1001];

void DFS(vector<int> graph[], int start){
    queue<int> q;
    q.push(start);
    check[start] = true;
    cout << start << ' ';
    for(int i = 0; i<graph[start].size(); i++){
        if(!check[graph[start][i]]){
            DFS(graph, graph[start][i]);
        }
    }
    
}

void BFS(vector<int> graph[], int start){
    queue<int> q;
    check[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        cout << tmp << ' ';
        for(int i = 0; i<graph[tmp].size(); i++){
            int c = graph[tmp][i];
            if(!check[c]){
                check[c] = true;
                q.push(c);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int node, edge, start;
    cin >> node >> edge >> start;
    vector<int> graph[node+1];
    for(int i = 0; i<edge; i++){
        int t1, t2;
        cin >> t1 >> t2;
        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
    }
    for(int i = 1; i<=node; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    memset(check, false, sizeof(check));
    DFS(graph, start);
    cout << '\n';
    memset(check, false, sizeof(check));
    BFS(graph, start);
    return 0;
}