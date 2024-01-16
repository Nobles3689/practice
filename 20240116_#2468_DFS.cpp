//Beakjoon Online Judge #2468
#include <iostream>
#include <string.h>
using namespace std;

struct Coord
{
    int x = 0;
    int y = 0;
};

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int n, low = 101, high = 0, ans = 0;
int map[102][102];
bool check[102][102];

void DFS(Coord coord, int level){
    int tx, ty;
    check[coord.y][coord.x] = true;
    for(int i = 0; i<4; i++){
        tx = coord.x + dx[i];
        ty = coord.y + dy[i];
        if(tx <= 0 || ty <= 0 || tx > n || ty > n){
            continue;
        }
        if(!check[ty][tx] && map[ty][tx] > level){
            DFS({tx, ty}, level);
        }
    }
}

void reset(){
    for(int j = 1; j<=n; j++){
        for(int k = 1; k<=n; k++){
            check[j][k] = false;
        }
    }
}

void cal(){
    int cnt;
    for(int i = low-1; i<=high; i++){
        cnt = 0;
        for(int j = 1; j<=n; j++){
            for(int k = 1; k<=n; k++){
                if(!check[j][k]){
                    if(map[j][k] > i){
                        DFS({k, j}, i);
                        cnt++;
                    }
                } 
            }
        }
        if(ans < cnt) ans = cnt;
        reset();
    }
}

void init(){
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> map[i][j];
            if(map[i][j] > high){
                high = map[i][j];
            }
            if(map[i][j] < low){
                low = map[i][j];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    cal();
    cout << ans;
    return 0;

}