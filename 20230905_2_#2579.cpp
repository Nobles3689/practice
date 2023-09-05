//Beakjoon Online Judge #2579
#include <iostream>
#include <vector>
using namespace std;



int DP(vector<int> &v, vector<int> &dp, int n){
    if(n==0){
        return 0;
    }else if(n==1){
        if(dp[1]==0)
            dp[1] = v[1]; 
        return dp[1];
    }else if(n==2){
        if(dp[2]==0)
            dp[2] = v[1] + v[2];
        return dp[2];
    }else{
        if(dp[n]==0){
            int tmp1 = DP(v, dp, n-2);
            int tmp2 = DP(v, dp, n-3) + v[n-1];
            dp[n] = max(tmp1, tmp2) + v[n];

        }
        return dp[n];
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    vector<int> v(num+1);
    vector<int> dp(num+1, 0);
    for(int i = 1; i<=num; i++){
        cin >> v[i];
    }

    cout << DP(v, dp, num);
    return 0;
    

}
