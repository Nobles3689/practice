//Beakjoon Online Judge #14940
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int map[1000][1000] = { 0, };
bool visited[1000][1000] = { false, };
int res[1000][1000];
using coordinate = pair<int, int>;
using dat = pair<int, coordinate>;
queue<dat> q;
vector<int> tx = {-1, 1, 0, 0};
vector<int> ty = {0, 0, -1, 1};
int n, m;
int ox, oy;

void BFS(){
    q.push({0 ,{ox, oy}});
    visited[ox][oy] = true;
    res[ox][oy] = 0;
    while (!q.empty())
    {
        dat tmp = q.front();
        q.pop();
        for(int i = 0; i<4; i++){
            int a = tmp.first;
            int nx = tmp.second.first + tx[i];
            int ny = tmp.second.second + ty[i];
            if(nx < 0 || nx > n || ny < 0 || ny > m || visited[nx][ny]){
                continue;
            }else{
                if(map[nx][ny]==0){
                    res[nx][ny] = 0;
                }else{
                    q.push({a+1, {nx, ny}});
                    visited[nx][ny] = true;
                    res[nx][ny] = a+1;
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(map[i][j]!=0&&!visited[i][j]){
                res[i][j] = -1;
            }
        }
    }
    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j]==2){
                ox = i;
                oy = j;
            }
        }
    }

    BFS();

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }


}