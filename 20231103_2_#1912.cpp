//Beakjoon Online Judge #1912
#include <iostream>
#include <vector>
using namespace std;
#define LOW -100000000
vector<int> v(100001, 0);
vector<int> DP(100001, 0);

int cal(int n){
    int M = LOW;
    int tmp;
    for(int i = 1; i<=n; i++){
        DP[i] = max(v[i], DP[i-1] + v[i]);
        M = max(M, DP[i]);
    }
    return M;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    for(int i = 1; i<=num; i++){
        cin >> v[i];
    }
    cout << cal(num);
    return 0;
}