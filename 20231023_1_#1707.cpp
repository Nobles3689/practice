//Beakjoon Online Judge #1707
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;




void BFS(vector<vector<int>> &graph, int visit[], int n){
    queue<int> q;
    q.push(n);
    int v = 1;
    visit[n] = v;
    while (!q.empty())
    {
        int tmp = q.front();
        v = visit[tmp]*-1;
        q.pop();

        for(int i = 0; i<graph[tmp].size(); i++){
            int c = graph[tmp][i];
            if(visit[c] == 0){
                visit[c] = v;
                q.push(c);
            }

        }
    }
    
}

bool def(vector<vector<int>> &graph, int visit[], int V){
    for(int i = 1; i<=V; i++){
        for(int j = 0; j<graph[i].size(); j++){
            if(visit[i]==visit[graph[i][j]]) return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for(int i = 0; i<tc; i++){
        int V, E;
        bool flag = true;
        cin >> V >> E;
        vector<vector<int>> graph(V+1);
        int visit[V+1] = {0,};
        for(int j = 0; j<E; j++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int j = 1; j<=V; j++){
            if(visit[j] == 0)
                BFS(graph, visit, j);
        }
        if(def(graph, visit, V)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}