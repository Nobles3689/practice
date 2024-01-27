//Beakjoon Online Judge #16234
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, L, R;
int board[50][50];
int visited[50][50];
vector<int> v;
int dy[4] = { -1, 1, 0, 0};
int dx[4] = { 0, 0, -1, 1};

int BFS(pii a, int cnt){
    queue<pii> q;
    q.push(a);
    visited[a.first][a.second] = cnt;
    pii tmp;
    int sum = board[a.first][a.second];
    int city_cnt = 1;
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        int tx, ty;
        for(int i = 0; i<4; i++){
            ty = tmp.first + dy[i];
            tx = tmp.second + dx[i];
            if(ty < 0 || ty >= n || tx < 0 || tx >= n){
                continue;
            }
            if(visited[ty][tx] == 0){
                int diff = abs(board[tmp.first][tmp.second] - board[ty][tx]);
                if(diff >= L && diff <= R){
                    q.push({ty, tx});
                    visited[ty][tx] = cnt;
                    sum += board[ty][tx];
                    city_cnt++;
                }
            }

        }

    }
    return sum/city_cnt;
}

void board_redraw(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(visited[i][j] != 0){
                board[i][j] = v[visited[i][j] - 1];
            }
        }
    }
}

int migration(){
    int res = 0;
    while (true)
    {   
        int cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(visited[i][j] == 0){
                    cnt++;
                    v.push_back(BFS({i, j}, cnt));
                    
                }
            }
        }
        if(cnt == (n*n)) break; 
        board_redraw();
        res++;
        v.clear();
        for(int i = 0; i<n; i++){
            memset(visited[i], 0, sizeof(int)*n);
        }

    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> L >> R;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> board[i][j];
        }
    }
    cout << migration();
    return 0;
}