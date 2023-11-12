//Beakjoon Online Judge #17386
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int ccw(pair<ll, ll>p1, pair<ll, ll>p2, pair<ll, ll>p3) {
    ll s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);
    cout << s << '\n';

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pair<ll, ll> L[4];
    for(int i = 0; i<4; i++){
        cin >> L[i].first >> L[i].second;
    }
    if((ccw(L[0], L[1], L[2])*ccw(L[0], L[1], L[3]) <= 0)&&(ccw(L[2], L[3], L[0])*ccw(L[2], L[3], L[1]) <= 0)){
        cout << 1;
    }else cout << 0;
    
    return 0;

}