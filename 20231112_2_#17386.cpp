//Beakjoon Online Judge #17386
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pair<ll, ll> L[4];
    for(int i = 0; i<4; i++){
        cin >> L[i].first >> L[i].second;
    }
    pair<ll, ll> Line[6];
    Line[0] = {L[1].first-L[0].first, L[1].second-L[0].second};
    Line[1] = {L[2].first-L[0].first, L[2].second-L[0].second};
    Line[2] = {L[3].first-L[0].first, L[3].second-L[0].second};
    Line[3] = {L[3].first-L[2].first, L[3].second-L[2].second};
    Line[4] = {L[1].first-L[2].first, L[1].second-L[2].second};
    Line[5] = {L[0].first-L[2].first, L[0].second-L[2].second};
    
    ll v[4];
    v[0] = (Line[0].first*Line[1].second) - (Line[0].second*Line[1].first);
    v[1] = (Line[0].first*Line[2].second) - (Line[0].second*Line[2].first);
    v[2] = (Line[3].first*Line[4].second) - (Line[3].second*Line[4].first);
    v[3] = (Line[3].first*Line[5].second) - (Line[3].second*Line[5].first);
    ll res[2];
    for(int i = 0; i<4; i++){
        if(v[i]>0) v[i] = 1;
        else if(v[i] < 0) v[i] = -1;
        else v[i] = 0;
    }
    res[0] = v[0]*v[1];
    res[1] = v[2]*v[3];
    
    if((res[0]<=0)&&(res[1]<=0)) cout << 1;
    else cout << 0;
    return 0;

}