//Beakjoon Online Judge #14500
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;
int n, m;
int xx[4] = {-1, 1, 0, 0};
int yy[4] = {0, 0, -1, 1};


void DFS(vector<vector<int>> &map, vector<vector<int>> &visit, int d, int sum, pair<int, int> coor){
    sum += map[coor.first][coor.second];
    visit[coor.first][coor.second] = 1;
    int tx, ty;
    if(d == 4){
        ans = max(ans, sum);
    }else{
        for(int i = 0; i<4; i++){
            tx = coor.first + xx[i];
            ty = coor.second + yy[i];
            if(tx>=0 && tx<n && ty >=0 && ty<m && visit[tx][ty] == 0)
                DFS(map, visit, d+1, sum, {tx, ty});
        }
    }
    visit[coor.first][coor.second] = 0;
}

void T(vector<vector<int>> &map, vector<vector<int>> &visit, pair<int, int> coor){
    int sum, tx, ty;
    for(int i = 0; i<4; i++){
        sum = map[coor.first][coor.second];
        for(int j = 0; j<4; j++){
            if(i==j)
                continue;
            tx = coor.first + xx[j];
            ty = coor.second + yy[j];
            if(tx>=0 && tx<n && ty>=0 && ty<m){
                sum+=map[tx][ty];
            }
        }
        ans = max(ans, sum);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> visit(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
            DFS(map, visit, 1, 0, {i, j});
            T(map, visit, {i, j});
        }
    }
    cout << ans;
    return 0;

}