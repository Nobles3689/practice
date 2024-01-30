//Beakjoon Online Judge #14503
#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int, int> robot;
int dir;
int cnt = 0;
int room[50][50];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool scan(int y, int x){
    for(int i = 0; i<4; i++){
        int ty = y + dy[i];
        int tx = x + dx[i];
        if(room[ty][tx] == 0) return true;
    }
    return false;
}

void clean(){
    while (true)
    {
        if(room[robot.first][robot.second] == 0){
            room[robot.first][robot.second] = 2;
            cnt++;
        }
        if(scan(robot.first, robot.second)){
            
            do{
                dir = (dir+3)%4;
            }while(room[robot.first+dy[dir]][robot.second+dx[dir]] != 0);
            robot.first+=dy[dir];
            robot.second+=dx[dir];
            
        }else{
            if(room[robot.first-dy[dir]][robot.second-dx[dir]] == 1) break;
            else{
                robot.first-=dy[dir];
                robot.second-=dx[dir];
            }
        }
    }
    
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    cin >> robot.first >> robot.second >> dir;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> room[i][j];
        }
    }
    clean();
    cout << cnt;
    return 0;

}