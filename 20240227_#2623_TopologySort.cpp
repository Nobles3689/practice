//Beakjoon Online Judge #2623
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> inDegree;
queue<int> ans;

int TopologySort(){
    queue<int> q;
    for(int i = 1; i<=n; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    for(int i = 0; i<n; i++){
        if(q.empty()) return 0;

        int tmp = q.front();
        q.pop();
        ans.push(tmp);
        for(int j = 0; j<graph[tmp].size(); j++){
            inDegree[graph[tmp][j]]--;
            if(inDegree[graph[tmp][j]] == 0) q.push(graph[tmp][j]);
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    graph.resize(n+1, vector<int>());
    inDegree.resize(n+1);
    for(int i = 0; i<m; i++){
        int tmp;
        cin >> tmp;
        int ex = 0, t;
        for(int j = 0; j<tmp; j++){
            cin >> t;
            if(ex != 0){
                graph[ex].emplace_back(t);
                inDegree[t]++;
            }
            ex = t;
        }
    }
    if(TopologySort()){
        while (!ans.empty())
        {
            cout << ans.front() << '\n';
            ans.pop();
        }
    }else{
        cout << "0\n";
    }
    return 0;
}