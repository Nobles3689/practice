//Beakjoon Online Judge #15683
#include <bits/stdc++.h>
using namespace std;

int n, m;
int res = 65;
int office[8][8];

vector<pair<int, int>> CCTV;
vector<pair<int, int>> No5;

void print(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << office[i][j] << ' ';
        }
        cout << '\n';
    }
}

void copy(int prev_office[8][8], int t_office[8][8]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            t_office[i][j] = prev_office[i][j];
        }
    }
}

void sight(int y, int x, int dir, int t_office[8][8]){
    switch (dir)
    {
    case 0:
        for(int i = x; i<m; i++){
            if(t_office[y][i] == 6) break;
            else if(t_office[y][i] == 0) t_office[y][i] = -1;
        }
        break;
    case 1:
        for(int i = y; i<n; i++){
            if(t_office[i][x] == 6) break;
            else if(t_office[i][x] == 0) t_office[i][x] = -1;
        }
        break;
    case 2:
        for(int i = x; i>=0; i--){
            if(t_office[y][i] == 6) break;
            else if(t_office[y][i] == 0) t_office[y][i] = -1;
        }
        
        break;
    case 3:
        for(int i = y; i>=0; i--){
            if(t_office[i][x] == 6) break;
            else if(t_office[i][x] == 0) t_office[i][x] = -1;
        }
        break;
    }
}



void set5(){
    for(int i = 0; i<No5.size(); i++){
        int y = No5[i].first;
        int x = No5[i].second;
        for(int j = 0; j<4; j++){
            sight(y, x, j, office);
        }
    }
}

int Blind_spot(int t_office[][8]){
    int b_spot = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(t_office[i][j] == 0) b_spot++;
        }
    }
    return b_spot;
}

void cal(int cnt, int prev_office[][8], int dist){
    if(cnt == CCTV.size()){
        res = min(res, Blind_spot(prev_office));
        return;
    }
    int tmp_office[8][8];
    copy(prev_office, tmp_office);
    switch (tmp_office[CCTV[cnt].first][CCTV[cnt].second])
    {
    case 1:
        sight(CCTV[cnt].first, CCTV[cnt].second, dist, tmp_office);
        break;
    case 2:
        sight(CCTV[cnt].first, CCTV[cnt].second, dist, tmp_office);
        sight(CCTV[cnt].first, CCTV[cnt].second, (dist+2)%4, tmp_office);
        break;
    case 3:
        sight(CCTV[cnt].first, CCTV[cnt].second, dist, tmp_office);
        sight(CCTV[cnt].first, CCTV[cnt].second, (dist+1)%4, tmp_office);
        break;
    case 4:
        sight(CCTV[cnt].first, CCTV[cnt].second, dist, tmp_office);
        sight(CCTV[cnt].first, CCTV[cnt].second, (dist+1)%4, tmp_office);
        sight(CCTV[cnt].first, CCTV[cnt].second, (dist+2)%4, tmp_office);
        break;
    }

    sight(CCTV[cnt].first, CCTV[cnt].second, dist, tmp_office);

    for(int a = 0; a<4; a++){
        cal(cnt+1, tmp_office, a);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> office[i][j];
            if(office[i][j] != 0 && office[i][j] != 6){
                if(office[i][j] == 5) No5.push_back({i, j});
                else CCTV.push_back({i, j});
            }
        }
    }
    set5();
    for(int i = 0; i<4; i++){
        cal(0, office, i);
    }
    cout << res;
    return 0;
}