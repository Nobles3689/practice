//Beakjoon Online Judge #2559
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF -1e8

vector<int> v(100000);
vector<int> DP(100000);

int cal(int n, int v){
    int m = INF;
    for(int i = 0; i<(n - v + 1); i++){
        m = max(m, DP[i+v] - DP[i]);
    }
    return m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    v[0] = 0;
    DP[0] = 0;
    for(int i = 1; i<=N; i++){
        cin >> v[i];
        if(i == 0) DP[i] = v[i];
        else DP[i] = DP[i-1] + v[i];
    }
    cout << cal(N, K);
    return 0;

}