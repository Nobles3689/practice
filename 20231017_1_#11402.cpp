//Beakjoon Online Judge #11401
#include <iostream>
using namespace std;

#define A 1000000007

long long pow(int n, int m){
    if(n == 0) return 0;
    if(m == 0) return 1;
    if(m%2!=0){
        return (pow(n, m-1)*n)%A;
    }
    long long tmp = pow(n, m/2)%A;
    return (tmp*tmp)%A;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    long long tmp_N = 1, tmp_K = 1;
    for(int i = 1; i<=N; i++){
        tmp_N*=i;
        tmp_N%=A;
    }
    for(int i = 1; i<=K; i++){
        tmp_K*=i;
        tmp_K%=A;
    }
    for(int i = 1; i<=(N-K); i++){
        tmp_K*=i;
        tmp_K%=A;
    }
    tmp_K = pow(tmp_K, A-2);
    long long ans = (tmp_N*tmp_K)%A;
    cout << ans;
    return 0;


}