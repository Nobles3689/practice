//Beakjoon Online Judge
#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9

pair<int, int> mat[501];
int DP[501][501];

int calDP(int a, int b){
    if(DP[a][b] != INF) return DP[a][b];
    if(a>=b) return 0;
    for(int i = a; i<b; i++){
        DP[a][b] = min(DP[a][b], calDP(a, i) + calDP(i+1, b) + (mat[a].first * mat[i].second * mat[b].second));
    }
    return DP[a][b];
}

int cal(int i){
    if(i==1) return 0;
    return calDP(0, i-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    fill(&DP[0][0], &DP[500][501], INF);
    for(int i = 0; i<num; i++){
        cin >> mat[i].first >> mat[i].second;
        //if(i>0) DP[i-1][i] = mat[i-1].first * mat[i].first * mat[i].second;
    }
    cout << cal(num);
    return 0;

}