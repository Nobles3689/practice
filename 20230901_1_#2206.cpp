//Beakjoon Online Judge #2206
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> coor;

int tx[4] = {-1, 1, 0, 0};
int ty[4] = {0, 0, -1, 1};



int BFS(vector<string>& map, vector<vector<vector<int>>>& check, int n, int m){
    queue<pair<coor, int>> q;
    q.push({{0, 0}, 0});
    int x, y;
    int nx, ny;
    int dis;
    int broken;
    while (!q.empty())
    {
        x = q.front().first.first;
        y = q.front().first.second;
        broken = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            nx = x + tx[i];
            ny = y + ty[i];
            dis = check[broken][x][y] + 1;
            if(nx == n-1 && ny == m-1){
                return dis + 1;
            }
            if(nx<0 || nx>=n || ny<0 || ny>=m){
                continue;
            }
            if(map[nx][ny] == '1' && broken == 0 && check[0][nx][ny] == -1){
                q.push({{nx, ny}, 1});
                check[1][nx][ny] = dis;
            }else if(map[nx][ny] == '0' && check[broken][nx][ny] == -1){
                q.push({{nx, ny}, broken});
                check[broken][nx][ny] = dis;
            }
        }

    }
    return -1;
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    string tmp;
    for(int i = 0; i<n; i++){
        cin >> tmp;
        map[i] = tmp;
    }
    vector<vector<vector<int>>> check(2, vector<vector<int>>(n, vector<int>(m, -1)));
    check[0][0][0] = 0;
    if(n==1&&m==1){
        cout << 1;
    }else{
        cout << BFS(map, check, n, m);
    }
    
    return 0;
    
}