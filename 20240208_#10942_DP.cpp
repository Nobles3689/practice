//Beakjoon Online Judge #10942
#include <bits/stdc++.h>
using namespace std;

int num[2001];
bool DP[2001][2001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    int a, b;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> num[i];
    }
    for(int i = 1; i<=n; i++){
        DP[i][i] = true;
    }
    for(int i = 1; i<n; i++){
        if(num[i] == num[i+1]) DP[i][i+1] = true;
    }
    for(int i = 2; i<=n-1; i++){
        for(int j = 1; j<=n-i; j++){
            int k = j+i;
            if(num[j] == num[k] && DP[j+1][k-1]) DP[j][k] = true;
        }
    }
    cin >> m;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        if(DP[a][b]) cout << "1\n";
        else cout << "0\n";
    }
    return 0;

}