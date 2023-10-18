//Beakjoon Online Judge #10830
#include <iostream>
#include <vector>
using namespace std;
#define P 1000


vector<vector<int>> mult(int n, vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> tmp(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                tmp[i][j] += (a[i][k]*b[k][j])%1000;
            }
            tmp[i][j]%=1000;
        }
    }
    return tmp;
}



vector<vector<int>> pow(int n, long long b, vector<vector<int>> a){
    if(b == 1) return a;
    if(b%2!=0){
        return mult(n, pow(n, b-1, a), a);
    }
    vector<vector<int>> tmp = pow(n, b/2, a);
    return mult(n, tmp, tmp);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N; long long B;
    
    cin >> N >> B;
    vector<vector<int>> A(N, vector<int>(N));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> A[i][j];
        }
    }
    vector<vector<int>> ans = pow(N, B, A);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cout << ans[i][j]%1000 << ' ';
        }
        cout << '\n';
    }
    return 0;
}