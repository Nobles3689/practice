//Beakjoon Online Judge #13460
#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, pair<int,int>> pii;


int n, m;
vector<string> board;
bool visited[10][10][10][10];
int dy[4] = { -1, 1, 0, 0};
int dx[4] = { 0, 0, -1, 1};
pair<int, int> r_coord, b_coord;

void move(int& ry, int& rx, int& distance, int& i)
{
	while (board[ry + dy[i]][rx + dx[i]] != '#' && board[ry][rx] != 'O')
	{
		rx += dx[i];
		ry += dy[i];
		distance += 1;
	}
}


int bfs(){
    queue<pii> q;
    queue<int> cnt_q;
    q.push({r_coord, b_coord});
    cnt_q.push(0);
    visited[r_coord.first][r_coord.second][b_coord.first][b_coord.second] = true;
    pii tmp;
    int tmp_cnt;
    while (!q.empty())
    {
        tmp = q.front();
        tmp_cnt = cnt_q.front();
        q.pop();
        cnt_q.pop();
        if(tmp_cnt >= 10) break;
        for(int i = 0; i<4; i++){
            int drx = tmp.first.second,
            dry = tmp.first.first,
            dbx = tmp.second.second,
            dby = tmp.second.first;
            int r_cnt = 0, b_cnt = 0, cnt = tmp_cnt + 1;

            move(dry, drx, r_cnt, i);
            move(dby, dbx, b_cnt, i);

            if(board[dby][dbx] == 'O') continue;
            if(board[dry][drx] == 'O'){
                return cnt;
            }

            if(dry == dby && drx == dbx){
                if(r_cnt > b_cnt){
                    dry -= dy[i];
                    drx -= dx[i];
                }else{
                    dby -= dy[i];
                    dbx -= dx[i];
                }
            }
            if(visited[dry][drx][dby][dbx]) continue;
            visited[dry][drx][dby][dbx] = true;
            q.push({{dry, drx}, {dby, dbx}});
            cnt_q.push(cnt);
            
            
            
        }
    }
    return -1;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    string tmp;
    getline(cin, tmp);
    for(int i = 0; i<n; i++){
        getline(cin, tmp);
        board.push_back(tmp);
        for(int j = 0; j<m; j++){
            if(board[i][j] == 'R'){
                r_coord = {i, j};
                board[i][j] = '.';
            }else if(board[i][j] == 'B'){
                b_coord = {i, j};
                board[i][j] = '.';
            }
        }
    }
    cout << bfs();
    return 0;


}