//Beakjoon Online Judge #1074
#include <iostream>
#include <cmath>
using namespace std;
int visit[2][2];
int ex_n = 0;


int Vis(int n, pair<int, int> target, pair<int, int> start){
    if(n==1){
        int tmp = ex_n;
        for(int i = 0; i<2; i++){
            for(int j = 0; j<2; j++){
                visit[i][j] = tmp;
                tmp++;
            }
        }
        return visit[target.first-start.first][target.second-start.second];
    }else{
        int evg = pow(2, n-1);
        int evg_r = evg + start.first;
        int evg_c = evg + start.second;
        if(target.first<evg_r&&target.second<evg_c){
            return Vis(n-1, target, start);
        }else if(target.first>=evg_r&&target.second<evg_c){
            ex_n+=(pow(evg, 2)*2);
            return Vis(n-1, target, make_pair(evg_r, start.second));
        }else if(target.first<evg_r&&target.second>=evg_c){
            ex_n+=(pow(evg, 2));
            return Vis(n-1, target, make_pair(start.first, evg_c));
        }else{
            ex_n+=(pow(evg, 2)*3);
            return Vis(n-1, target, make_pair(evg_r, evg_c));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, r, c;
    cin >> N >> r >> c;
    cout << Vis(N, make_pair(r, c), make_pair(0, 0));

    return 0;

}

