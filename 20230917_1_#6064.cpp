//Beakjoon Online Judge #6064
#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b){
    if(b==0) return a;
    else return GCD(b, a%b);
}

int test(int m, int n, int x, int y){
    int ans = 1;
    int max = m*n/GCD(m, n);

    for(int i = x; i<=max; i+=m){
        int ty = i%n;
        if(ty == 0){
            ty = n;
        }
        if(ty == y){
            return i;
        }
    }
    return -1;

    /*
    int gcd = GCD(m, n);
    if(x==m && y==n){
        return m*n/gcd;
    }
    if(x==1 && y==1){
        return 1;
    }
    int minus = abs(x-y);
    if(minus%gcd != 0){
        return -1;
    }
    
    int tm = m/gcd;
    int tn = n/gcd;
    int tx = x%tm;
    int ty = y%tn;
    if(tx == 0 && ty == 0){
        return max(x, y);
    }
    long long tmp1, tmp2;
    for(int i = 0; i<tm; i++){
        tmp1 = tn*i;
        if(tmp1%tm == 1){
            break;
        }
    }
    for(int i = 0; i<tn; i++){
        tmp2 = tm*i;
        if(tmp2%tn == 1){
            break;
        }
    }
    long long ans = (tmp1*tx) + (tmp2*ty);
    return ans%(m*n/gcd);
    */
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t_case;
    cin >> t_case;
    for(int i = 0; i<t_case; i++){
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        cout << test(m, n, x, y) << '\n';
    }

    return 0;
}