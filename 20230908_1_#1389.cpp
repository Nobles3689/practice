//Beakjoon Online Judge #1389
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> &graph, vector<vector<int>> &dis, int start, int n){
    queue<int> q;
    q.push({start});
    dis[start][start] = 0;
    int tmp;
    int t_dis;
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        t_dis = dis[start][tmp];
        for(int i = 0; i<graph[tmp].size(); i++){
            if(dis[start][graph[tmp][i]]==-1){
                q.push(graph[tmp][i]);
                dis[start][graph[tmp][i]] = t_dis+1;
            }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<vector<int>> dis(n+1, vector<int>(n+1, -1));
    for(int i = 0; i<m; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    for(int i = 1; i<=n; i++){
        BFS(graph, dis, i, n);
    }
    vector<int> ans(n+1, 0);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(j!=i){
                ans[i]+=dis[i][j];
            }
        }
    }
    pair<int, int> min = {0, 10000};
    for(int i = 1; i<=n; i++){
        if(min.second>ans[i]){
            min.first = i;
            min.second = ans[i];
        }
    }

    cout << min.first;
    return 0;

}