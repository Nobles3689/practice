//Beakjoon Online Judge #10844
#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000000

int DP[100][10] = {0, };

int cal(int n){
    for(int j = 1; j<=9; j++){
        DP[0][j] = 1;        
    }
    for(int i = 1; i<n; i++){
        DP[i][0] = DP[i-1][1];
        for(int j = 1; j<9; j++){
            DP[i][j] = (DP[i-1][j+1] + DP[i-1][j-1]) % INF;
        }
        DP[i][9] = DP[i-1][8];
    }
    int sum = 0;
    for(int j = 0; j<=9; j++){
        sum+=DP[n-1][j];  
        sum%=INF;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    cout << cal(num);
    return 0;
}