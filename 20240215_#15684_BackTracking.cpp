//Beakjoon Online Judge #15684
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> target;
bool ladder[32][11];
int n, m, h;
int ans = 5;

void init(){
    for(int i = 1; i<=h; i++){
        for(int j = 1; j<=n; j++){
            if(!ladder[i][j]) target.push_back({i, j});
        }
    }
}

bool check(){
    for(int i = 1; i<=n; i++){
        int now_line = i;
        for(int j = 1; j<=h; j++)
        {
            if(ladder[j][now_line]){
                now_line++;
            }else if(ladder[j][now_line-1]){
                now_line--;
            }
        }
        if(now_line != i) return false;
    }

    return true;
}

void cal(int cnt, int index){
    if(cnt>3) return;

    if(check()){
        ans = min(ans, cnt);
        return;
    }

    for(int i = index+1; i<target.size(); i++){
        int ty = target[i].first;
        int tx = target[i].second;
        if(ladder[ty][tx]) continue;

        if(!ladder[ty][tx-1] && !ladder[ty][tx+1]){
            ladder[ty][tx] = true;
            cal(cnt+1, i);
            ladder[ty][tx] = false;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> h;
    for(int i = 0; i<m; i++){
        int s, e;
        cin >> s >> e;
        ladder[s][e] = true;
    }
    init();
    cal(0, -1);
    if(ans == 5) ans = -1;
    cout << ans;
    return 0;
}