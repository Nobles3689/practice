//Beakjoon Online Judge #24445
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph(100001);
vector<int> visit(100001, 0);
int o = 1;

void BFS(int r){
    queue<int> q;
    q.push(r);
    visit[r] = o;
    int tmp;
    while (!q.empty())  
    {
        tmp = q.front();
        q.pop();
        for(int i = 0; i<graph[tmp].size(); i++){
            if(visit[graph[tmp][i]] == 0){
                q.push(graph[tmp][i]);
                o++;
                visit[graph[tmp][i]] = o;
            }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;
    for(int i = 0; i<m; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    for(int i = 1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }
    BFS(r);
    for(int i = 1; i<=n; i++){
        cout << visit[i] << '\n';
    }
    return 0;
}