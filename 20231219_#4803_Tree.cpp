//Beakjoon Online Judge #4803
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph(501);


int search(int n){
    vector<bool> visit(n+1, false);
    int cnt = 0;
    for(int i = 1; i<=n; i++){
        if(!visit[i]){
            bool flag = true;
            queue<pair<int, int>> q;
            q.push({i, 0});
            visit[i] = true;
            
            pair<int, int> tmp;
            int s;
            while (!q.empty())
            {
                tmp = q.front();
                q.pop();
                s = graph[tmp.first].size();
                for(int j = 0; j<s; j++){
                    if(graph[tmp.first][j] == tmp.second) continue;

                    if(visit[graph[tmp.first][j]]){
                        flag = false;
                    }else{
                        q.push({graph[tmp.first][j], tmp.first});
                        visit[graph[tmp.first][j]] = true;
                    }
                    
                }
            }
            if(flag) cnt++;
            
            
        }
    }
    return cnt;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int case_num = 0;
    while (true)
    {
        int n, m;
        cin >> n >> m;
        if(n==0 && m==0) break;
        case_num++;
        
        for(int i = 0; i<m; i++){
            int s, e;
            cin >> s >> e;
            graph[s].push_back(e);
            graph[e].push_back(s);
        }

        int res = search(n);
        cout << "Case " << case_num << ": ";
        if(res==0){
            cout << "No trees.\n";
        }else if(res==1){
            cout << "There is one tree.\n";
        }else{
            cout << "A forest of " << res << " trees.\n";
        }
        for(int i = 0; i<=500; i++){
            graph[i].clear();
        }
    }
    return 0;
}