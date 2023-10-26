//Beakjoon Online Judge #11066
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define INF 1e9

int cost[501];
int sum[500];
int DP[501][501];

void cal(int a, int b){
    int tmp;
    if(DP[a][b] != INF) return;
    if(a==b) DP[a][b] = 0;
    else{
        for(int i = a; i<=b; i++){
            cal(a, i);
            cal(i+1, b);
            tmp = DP[a][i] + DP[i+1][b];
            DP[a][b] = min(tmp, DP[a][b]);
        }
        DP[a][b] += sum[b] - sum[a-1];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for(int z = 0; z<tc; z++){
        memset(cost, 0, sizeof(cost));
        //memset(sum, 0, sizeof(sum));
        fill(&DP[0][0], &DP[500][501], INF);
        int cnum;
        cin >> cnum;
        for(int i = 1; i<=cnum; i++){
            cin >> cost[i];
            sum[i] = sum[i-1] + cost[i];
            
        }
        cal(1, cnum);
        cout << DP[1][cnum] << '\n';
    }
    return 0;
}