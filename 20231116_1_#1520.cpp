//Beakjoon Online Judge #1520
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;
int n, m;
int xx[4] = {-1, 1, 0, 0};
int yy[4] = {0, 0, -1, 1};
vector<vector<int>> map(500, vector<int>(500));
vector<vector<int>> visit(500, vector<int>(500, 0));
vector<vector<bool>> check(500, vector<bool>(500, false));

int DFS(vector<vector<int>> &map, vector<vector<int>> &visit, pair<int, int> coor){
    int tx, ty;
    if(coor.first == n-1 && coor.second == m-1){
        return 1;
    }
    if(check[coor.first][coor.second]) return visit[coor.first][coor.second];
    check[coor.first][coor.second] = true;
    for(int i = 0; i<4; i++){
        tx = coor.first + xx[i];
        ty = coor.second + yy[i];
        if(tx>=0 && tx<n && ty >=0 && ty<m && map[coor.first][coor.second]>map[tx][ty]){
            visit[coor.first][coor.second] += DFS(map, visit, {tx, ty});
        }
    }
    
    return visit[coor.first][coor.second];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
        }
    }
    ans = DFS(map, visit, {0, 0});
    cout << ans;
    return 0;
}