//Beakjoon Online Judge #9461
#include <iostream>
#include <vector>
using namespace std;

long long dp[101] = { 0 ,};

void init(){

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for(int i = 4; i<101; i++){
        dp[i] = dp[i-2] + dp[i-3];
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();

    int flag;
    cin >> flag;
    for(int i = 0; i<flag; i++){
        int num;
        cin >> num;
        cout << dp[num] << '\n';
    }
    return 0;
}