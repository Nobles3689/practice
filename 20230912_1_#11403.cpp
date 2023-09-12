//Beakjoon Online Judge #11403
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 999999999

int dp[100][100] = { 0, };

void Floyd(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }
}
    

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> dp[i][j];
            if(dp[i][j]==0)
                dp[i][j] = INF;
        }
    }

    Floyd(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(dp[i][j] == INF)      
                cout << 0 << ' ';
            else
                cout << 1 << ' ';
        }
        cout << '\n';
    }
    
    
    return 0;
}