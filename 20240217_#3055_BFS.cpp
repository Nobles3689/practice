//Beakjoon Online Judge #3055
#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<string> forest;
queue<pair<int, int>> water;
pair<int, int> Hedgehog;
int checked[50][50];
int water_time[50][50];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void water_flow(){
    pair<int, int> tmp;
    while (!water.empty())
    {
        tmp = water.front();
        water.pop();
        for(int i = 0; i<4; i++){
            int ty = tmp.first + dy[i];
            int tx = tmp.second + dx[i];
            if(ty < 0 || ty >= r || tx < 0 || tx >= c) continue;
            if(forest[ty][tx] == 'X' || forest[ty][tx] == 'D' || water_time[ty][tx] != 0) continue;
            water_time[ty][tx] = water_time[tmp.first][tmp.second] + 1;
            water.push({ty, tx});
        }
    }
}

int BFS(){
    queue<pair<int, int>> q;

    q.push(Hedgehog);
    checked[Hedgehog.first][Hedgehog.second] = 1;
    pair<int, int> tmp;
    int tmp_cnt;
    while (!q.empty())  
    {
        tmp = q.front();
        tmp_cnt = checked[tmp.first][tmp.second];
        q.pop();
        for(int i = 0; i<4; i++){
            int ty = tmp.first + dy[i];
            int tx = tmp.second + dx[i];
            if(ty < 0 || ty >= r || tx < 0 || tx >= c) continue;
            if(forest[ty][tx] == 'D') return tmp_cnt;
            if(forest[ty][tx] == 'X' || forest[ty][tx] == '*' || checked[ty][tx] != 0 || (tmp_cnt >= water_time[ty][tx] && water_time[ty][tx] !=0)) continue;
            //&& water_time[ty][tx] !=0 부분은 물이 아예 존재하지 않을때를 고려한 조건
            
            
            q.push({ty, tx});
            checked[ty][tx] = tmp_cnt+1;
        }
        
    }
    return -1;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    string tmp;
    getline(cin, tmp);
    for(int i = 0; i<r; i++){
        getline(cin, tmp);
        forest.push_back(tmp);
        for(int j = 0; j<c; j++){
            if(tmp[j] == '*'){
                water.push({i, j});
                water_time[i][j] = 0;
            }else if(tmp[j] == 'S'){
                Hedgehog = {i, j};
            }
        }
    }
    water_flow();
    int res = BFS();
    if(res == -1) cout << "KAKTUS";
    else cout << res;
    return 0;
}