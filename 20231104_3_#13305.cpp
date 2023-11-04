//Beakjoon Online Judge #13305
#include <iostream>
#include <vector>
using namespace std;
#define INF 1e10
typedef long long ll;

vector<ll> dis(100000, 0);
vector<ll> oil(100001, 0);
vector<ll> tmp(100001, INF);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    for(int i = 1; i<num; i++){
        cin >> dis[i];  
    }
    ll min = INF;
    for(int i = 1; i<=num; i++){
        cin >> oil[i];
        if(oil[i]<tmp[i-1]) tmp[i] = oil[i];
        else tmp[i] = tmp[i-1];
    }
    ll ans = 0;
    for(int i = num-1; i>=1; i--){
        ans += tmp[i]*dis[i];
    }
    cout << ans;
    return 0;

}