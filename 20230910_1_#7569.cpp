//Beakjoon Online Judge #7569
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, h;
int tx[6] = {-1, 1, 0, 0, 0, 0};
int ty[6] = {0, 0, -1, 1, 0, 0};
int tz[6] = {0, 0, 0, 0, -1, 1};

int BFS(vector<vector<vector<int>>> &box, queue<pair<pair<int, int>, pair<int, int>>> &q){
    int x, y, z;
    int date;
    int nx, ny, nz, ndate, ans = 1;
    while (!q.empty())
    {
        x = q.front().second.first;
        y = q.front().second.second;
        z = q.front().first.second;
        date = q.front().first.first;
        q.pop();
        for(int i = 0; i<6; i++){
            nx = x + tx[i];
            ny = y + ty[i];
            nz = z + tz[i];
            ndate = date+1;
            if(nx<0 || nx>=n || ny<0 || ny>=m || nz<0 || nz>=h){
                continue;
            }
            if(box[nz][nx][ny] == 0){
                q.push({{ndate, nz}, {nx, ny}});
                box[nz][nx][ny] = ndate;
                if(ans<ndate){
                    ans = ndate;
                }
            }
        }
    }
    return ans;
    
}

bool check(vector<vector<vector<int>>> &box){
    for(int i = 0; i<h; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++){
                if(box[i][j][k] == 0){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> m >> n >> h;
    vector<vector<vector<int>>> box(h, vector<vector<int>>(n, vector<int>(m)));
    queue<pair<pair<int, int>, pair<int, int>>> q;
    for(int i = 0; i<h; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1){
                    q.push({{1, i}, {j, k}});
                }
            }
        }
    }
    int ans = BFS(box, q) - 1;
    if(check(box)){
        cout << ans;
    }else{
        cout << -1;
    }

    return 0;


}