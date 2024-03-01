//Beakjoon Online Judge #9328
#include <bits/stdc++.h>
using namespace std;


int h, w;
bool key_v[26];
bool visited[102][102];
char building[102][102];
const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };
int ans = 0;


void Qclear(queue<pair<int, int>> &q){
    queue<pair<int, int>> e;
    swap(q, e);
}

void BFS(){
    queue<pair<int,int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i<4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];

            if(ty < 0 || ty > h + 1 || tx < 0 || tx > w + 1) continue;

            if(building[ty][tx] == '$'){
                ans++;
                building[ty][tx] = '.';
            }

            if(building[ty][tx] >= 'A' && building[ty][tx] <= 'Z'){
                if(key_v[building[ty][tx] - 'A']) building[ty][tx] = '.';
            }

            if(building[ty][tx] >= 'a' && building[ty][tx] <= 'z'){
                key_v[building[ty][tx] - 'a'] = true;
                building[ty][tx] = '.';
                Qclear(q);
                for(int j = 0; j<=h+1; j++){
                    memset(visited[j], false, (w+2)*sizeof(bool));
                }
                q.push({0, 0});
                visited[0][0] = true;
                break;
            }

            if(building[ty][tx] == '.' && !visited[ty][tx]){
                q.push({ty, tx});
                visited[ty][tx] = true;
            }
        }

    }
    
    
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while (tc>0)
    {  
        cin >> h >> w;
        string tmp;
        for(int i = 0; i<=h+1; i++){
            building[i][0] = '.';
            building[i][w+1] = '.';
        }
        for(int i = 0; i<=w+1; i++){
            building[0][i] = '.';
            building[h+1][i] = '.';
        }

        for(int i = 1; i<=h; i++){
            cin >> tmp;
            for(int j = 1; j<=w; j++){
                building[i][j] = tmp[j-1];
            }
        }
        cin >> tmp;
        if(tmp[0] != '0'){
            for(int i = 0; i<tmp.length(); i++){
                key_v[tmp[i] - 97] = true;
            }
        }
        
        BFS();
        cout << ans << '\n';
        ans = 0;
        for(int j = 0; j<=h+1; j++){
            memset(visited[j], false, (w+2)*sizeof(bool));
        }
        for(int i = 0; i<26; i++) key_v[i] = false;
        tc--;
        
    }
    
    return 0;
}
