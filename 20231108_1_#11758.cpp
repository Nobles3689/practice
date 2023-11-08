//Beakjoon Online Judge #11758
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pair<int, int> p[3];
    for(int i = 0; i<3; i++){
        cin >> p[i].first >> p[i].second;
    }
    pair<int, int> grad[2];
    for(int i = 0; i<2; i++){
        grad[i].first = p[i+1].first - p[0].first;
        grad[i].second = p[i+1].second - p[0].second;
    }
    int tmp = (grad[0].first*grad[1].second) - (grad[0].second*grad[1].first);
    if(tmp == 0) cout << tmp;
    else if(tmp > 0) cout << 1;
    else cout << -1;
    return 0;
    
}