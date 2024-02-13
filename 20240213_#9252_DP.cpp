//Beakjoon Online Judge #9252
#include <bits/stdc++.h>
using namespace std;
char List[2][1001];
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
            List[i][j] = tmp[j-1];
        }
    }
    
    for(int i = 1; i<=L[1]; i++){
        for(int j = 1; j<=L[0]; j++){
            if (List[1][i] == List[0][j])
                DP[i][j] = DP[i-1][j-1] + 1;
			else
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    }

    cout << DP[L[1]][L[0]];
    if(DP[L[1]][L[0]] == 0) return 0;
    string ans = "";
    while (L[0]>0 && L[1]>0)
    {
        if(List[0][L[0]] == List[1][L[1]]){
            ans+=List[0][L[0]];
            L[0]--;
            L[1]--;
        }else if(DP[L[1]-1][L[0]] >= DP[L[1]][L[0]-1])
            L[1]--;
        else
            L[0]--;
    }
    reverse(ans.begin(), ans.end());
    
    cout << '\n' << ans;
    return 0;

}