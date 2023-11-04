//Beakjoon Online Judge #1904
#include <iostream>
#include <vector>
using namespace std;

vector<int> DP(1000000, 0);

int cal(int n){
    DP[0] = 1; DP[1] = 1;
    for(int i = 2; i<=n; i++){
        DP[i] = DP[i-1] + DP[i-2];
        DP[i]%=15746;
    }
    return DP[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    cout << cal(num);
    return 0;
}