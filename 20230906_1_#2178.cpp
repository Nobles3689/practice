//Beakjoon Online Judge #2178
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int n, m;
int tx[4] = {-1, 1, 0, 0};
int ty[4] = {0, 0, -1, 1};


int BFS(vector<string> &v, vector<vector<int>> &check){
    queue<pair<int, int>> q;
    q.push({0, 0});
    check[0][0] = 0;
    int x, y;
    int nx, ny;
    int ans;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            nx = x + tx[i];
            ny = y + ty[i];
            ans = check[x][y] + 1;
            if(nx == n-1 && ny == m-1){
                return ans+1;
            }
            if( nx<0 || nx>=n || ny<0 || ny>=m ){
                continue;
            }
            if( v[nx][ny] == '1' && check[nx][ny] == -1 ){
                q.push({nx, ny});
                check[nx][ny] = ans;
            }
        }
    }
    
    return -1;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> n >> m;
    vector<string> v(n);
    vector<vector<int>> check(n, vector<int>(m, -1));
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    int result;
    if(n==1&&m==1){
        result = 1;
    }else{
        result = BFS(v, check);
    }

    cout << result;
    return 0;
}