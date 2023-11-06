//Beakjoon Online Judge #10986
#include <iostream>
#include <vector>
using namespace std;
#define INF 1e6
typedef long long ll;
vector<ll> r(INF, 0);
vector<ll> s(INF);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    s[0] = 0;
    ll ans = 0;
    for(int i = 0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(i!=0){
            s[i] = (s[i-1] + tmp)%m;
        }else{
            s[i] = tmp%m;
        }
    }
    for(int i = 0; i<n; i++){
        r[s[i]]++;
    }
    
    for(int i = 0; i<m; i++){
        if(r[i]<2) continue;
        ans+=r[i]*(r[i]-1)/2;
    }
    ans+=r[0];
    cout << ans;
    return 0;

}