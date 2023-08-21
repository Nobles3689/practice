//Beakjoon Online Judge #9251
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
char list[2][1001];
int L[2];
int DP[1001][1001];//이전까지 값저장(다이나믹 프로그래밍)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i<2; i++){
        string tmp;
        cin >> tmp;
        L[i] = tmp.length();
        for(int j = 1; j<=L[i]; j++){
            list[i][j] = tmp[j-1];
        }
    }
    
    for(int i = 1; i<=L[1]; i++){
        for(int j = 1; j<=L[0]; j++){
            if (list[1][i] == list[0][j])
                DP[i][j] = DP[i-1][j-1] + 1;
			else
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    }
    
    cout << DP[L[1]][L[0]];

    return 0;

}