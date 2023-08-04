//Baekjoon Online Judge #7576
#include <iostream>
#include <queue>
using namespace std;
int box[1000][1000];
vector<int> tx = {-1, 1, 0, 0};
vector<int> ty = {0, 0, -1, 1};
using coordinate = pair<int, int>;
using tom = pair<int, coordinate>;
queue<tom> q;


int tomato(int m, int n){
    int max = -1;
    
    while (!q.empty())
    {
        int a, x, y;
        a = q.front().first;
        x = q.front().second.first;
        y = q.front().second.second;
        if(a>max)
            max = a;
        q.pop();
        for(int i = 0; i<4; i++){
            int nx = x + tx[i];
            int ny = y + ty[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || box[nx][ny] != 0) {
                    continue;
            }
            q.push({a+1, {nx, ny}});
            box[nx][ny] = 1;
        }
        

    }

    return max;
    
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n, tmp;
    cin >> m >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> tmp;
            box[i][j] = tmp;
            if(tmp == 1){
                q.push({0, {i, j}});
            }
            
        }
    }
    int result = tomato(m, n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(box[i][j]==0){
                cout << -1;
                return 0;
            }
        }
    }

    cout << result;
    return 0;
}