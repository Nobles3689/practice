//Beakjoon Online Judge #21736
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int xx[4] = {-1, 1, 0, 0};
int yy[4] = {0, 0, -1, 1};

int BFS(vector<string> &graph, vector<vector<int>> &visit, pair<int, int> start){
    int ans = 0;
    queue<pair<int, int>> q;
    q.push(start);
    visit[start.first][start.second] = 1;
    int x, y;
    int tx, ty;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            tx = x + xx[i];
            ty = y + yy[i];
            if(tx<0 || tx>=n || ty<0 || ty>=m){
                continue;
            }
            if(graph[tx][ty] != 'X' && visit[tx][ty] == 0){
                q.push({tx, ty});
                visit[tx][ty] = 1;
                if(graph[tx][ty] == 'P'){
                    ans++;
                }
            }
        }
    }
    return ans;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> n >> m;
    vector<string> graph(n);
    vector<vector<int>> visit(n, vector<int>(m, 0));
    pair<int, int> s_coor;
    for(int i = 0 ; i<n; i++){
        cin >> graph[i];
        for(int j = 0; j<graph[i].size(); j++){
            if(graph[i][j]=='I'){
                s_coor = {i, j};
            }
        }
    }
    int ans = BFS(graph, visit, s_coor);
    if(ans<=0){
        cout << "TT";
    }else{
        cout << ans;
    }
    return 0;
    

}