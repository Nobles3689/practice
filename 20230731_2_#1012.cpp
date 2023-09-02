//Beakjoon Online Judge #1012
#include <iostream>
#include <queue>
using namespace std;

int x_d[4] = {-1, 1, 0, 0};
int y_d[4] = {0, 0, -1, 1};
int row, col, cab;

void BFS(int farm[][50], int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    farm[x][y] = 2;

    while(!q.empty()){
        pair<int, int> a = q.front();
        q.pop();
        
        for(int i = 0; i<4; i++){
            int nx = a.first + x_d[i];
            int ny = a.second + y_d[i];
            if ( (0 <= nx && nx < row) && (0 <= ny && ny < col) 
            && farm[nx][ny]!=2 && farm[nx][ny] == 1 ){
                farm[nx][ny] = 2;
                q.push(make_pair(nx, ny));

            }

        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int c_Num;
    cin >> c_Num;
    for(int i = 0; i<c_Num; i++){
        int farm[50][50] = { 0, };
        
        cin >> row >> col >> cab;
        for(int j = 0; j<cab; j++){
            int x, y;
            cin >> x >> y;
            farm[x][y] = 1;
        }
        int worm = 0;
        for(int j = 0; j<row; j++){
            for(int k = 0; k<col; k++){
                if(farm[j][k]==1){
                    BFS(farm, j, k);
                    worm++;
                }
            }
        }
        cout << worm << '\n';

    }
    return 0;
}