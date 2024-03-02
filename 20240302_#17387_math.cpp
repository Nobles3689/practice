//Beakjoon Online Judge #17387
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll, ll> L[2][2];

int ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3){
    ll tmp = p1.first*p2.second + p2.first*p3.second + p3.first*p1.second;
    tmp -= (p1.second*p2.first + p2.second*p3.first + p3.second*p1.first);
    if(tmp > 0) return 1;
    else if(tmp < 0) return -1;
    else return 0;
}

bool cross(){


    int ccw1 = ccw(L[0][0], L[0][1], L[1][0]) * ccw(L[0][0], L[0][1], L[1][1]),
    ccw2 = ccw(L[1][0], L[1][1], L[0][0]) * ccw(L[1][0], L[1][1], L[0][1]);

    if(ccw1 == 0 && ccw2 == 0){
        if(L[0][0] > L[0][1]) swap(L[0][1], L[0][0]);
        if(L[1][0] > L[1][1]) swap(L[1][0], L[1][1]);

        return L[1][0] <= L[0][1] && L[0][0] <= L[1][1];
    }

    return ccw1 <= 0 && ccw2 <= 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            cin >> L[i][j].first >> L[i][j].second;
        }
    }
    if(cross()) cout << 1 << '\n';
    else cout << 0 << '\n';
    return 0;
}