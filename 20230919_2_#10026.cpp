//Beakjoon Online Judge #10026
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int num;
int xx[4] = {-1, 1, 0, 0};
int yy[4] = {0, 0, -1, 1};

int BFS(vector<string> &pic, vector<vector<int>> &visit, int flag){
    int ans = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    visit[0][0] = ans;
    int x, y;
    char tmp;
    int tx, ty;
    for(int a = 0; a<num; a++){
        for(int b = 0; b<num; b++){
            if(visit[a][b]==0){
                ans++;
                q.push({a, b});
                visit[a][b] = ans;
                while (!q.empty())
                {   
                    x = q.front().first;
                    y = q.front().second;
                    tmp = pic[x][y];
                    q.pop();
                    for(int i = 0; i<4; i++){
                        tx = x + xx[i];
                        ty = y + yy[i];
                        if(tx<0 || tx>=num || ty<0 || ty>=num){
                            continue;
                        }
                        if(flag == 0 || tmp == 'B'){
                            if(visit[tx][ty] == 0 && pic[tx][ty] == tmp){
                                q.push({tx, ty});
                                visit[tx][ty] = ans;
                            }
                        }else{
                            if(visit[tx][ty] == 0 && (pic[tx][ty] == 'R' || pic[tx][ty] == 'G')){
                                q.push({tx, ty});
                                visit[tx][ty] = ans;
                            }
                            
                        }
                        
                    }

                }
            }
        }
    }

    return ans;
    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> num;
    vector<string> pic(num);
    for(int i = 0; i<num; i++){
        cin >> pic[i];
    }
    vector<vector<int>> normal(num, vector<int>(num, 0));
    vector<vector<int>> c_blind(num, vector<int>(num, 0));
    cout << BFS(pic, normal, 0) << ' ' << BFS(pic, c_blind, 1);
    return 0;
}