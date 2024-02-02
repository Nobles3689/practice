//Beakjoon Online Judge #2133
#include <bits/stdc++.h>
using namespace std;

int DP[31];

void cal(int n){
    if(n%2 == 1) return;
    DP[0] = 1;
    DP[1] = 0;
    for(int i = 2; i<=n; i+=2){
        DP[i] = DP[i-2] * 3;
        for(int j = i-4; j>=0; j-=2){
            DP[i] += 2 * DP[j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cal(n);
    cout << DP[n];
    return 0;
}