//Beakjoon Online Judge #9251
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
char list[2][1000];
int L[2];
int DP[1000][2] = {0, };//이전까지 값저장(다이나믹 프로그래밍)
queue<pair<char, int>> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i<2; i++){
        string tmp;
        cin >> tmp;
        L[i] = tmp.length();
        for(int j = 0; j<L[i]; j++){
            list[i][j] = tmp[j];
        }
    }
    
    for(int i = 0; i<L[1]; i++){
        int tmp = 0;
        for(int j = 0; j<L[0]; j++){

            if (list[1][i] == list[0][j])
			{
				if (j == 0)
					DP[j][0] = 1;
				else
					DP[j][0] = DP[j - 1][1] + 1;
			}
			else
				DP[j][0] = max(DP[j][0], DP[j - 1][0]);

        
        }
        
        
        for(int j = 0; j<L[0]; j++){
            DP[j][1] = DP[j][0];
        }
    }
    int ans = 0;
    for(int j = 0; j<L[0]; j++){
        ans = max(ans, DP[j][0]);
    }
    
    cout << ans;
    







    return 0;

}