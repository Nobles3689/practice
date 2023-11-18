//Beakjoon Online Judge #24480
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph(100001);
vector<int> visit(100001, 0);
int o = 0;

void DFS(int r){
    o++;
    visit[r] = o;
    for(int i = 0; i<graph[r].size(); i++){
        if(visit[graph[r][i]] == 0) DFS(graph[r][i]);
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
    DFS(r);
    for(int i = 1; i<=n; i++){
        cout << visit[i] << '\n';
    }
    return 0;
}