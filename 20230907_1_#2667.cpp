//Beakjoon Online Judge #2667
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
int ans = 0;
int xx[4] = {-1, 1, 0, 0};
int yy[4] = {0, 0, -1, 1};



int BFS(vector<string> &map, vector<vector<int>> &check, int x, int y){
    ans++;
    queue<pair<int, int>> q;
    q.push({x, y});
    check[x][y] = 0;
    int nx, ny;
    int tx, ty;
    int dis = 0;
    while (!q.empty())
    {
        nx = q.front().first;
        ny = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            tx = nx + xx[i];
            ty = ny + yy[i];
            if(tx<0 || tx>=n || ty<0 || ty>=n){
                continue;
            }
            if(map[tx][ty] == '1' && check[tx][ty] == -1){
                q.push({tx, ty});
                check[tx][ty] = 1;
                dis++;
            }
        }
    }
    return dis+1;
}

vector<int> search(int n, vector<string> &map, vector<vector<int>> &check){
    vector<int> v;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(map[i][j] == '1' && check[i][j] == -1){
                v.push_back(BFS(map, check, i, j));
            }
        }
    }
    return v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<string> map(n);
    vector<vector<int>> check(n, vector<int>(n, -1));
    for(int i = 0; i<n; i++){
        cin >> map[i];
    }

    vector<int> v = search(n, map, check);
    sort(v.begin(), v.end());
    cout << ans << '\n';
    for(int i = 0 ; i<v.size(); i++){
        cout << v[i] << '\n';
    }

    return 0;


}