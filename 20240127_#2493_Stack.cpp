//Beakjoon Online Judge #2493
#include <bits/stdc++.h>
using namespace std;
#define MAX_HIGHT 100000001

int n;
vector<int> tower;

void LASER(){
    stack<pair<int, int>> s;
    s.push({MAX_HIGHT, 0});
    for(int i = 1; i<=n; i++){
        while (s.top().first < tower[i])
        {
            s.pop();
        }
        cout << s.top().second << ' ';
        s.push({tower[i], i});
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    tower.push_back(MAX_HIGHT);
    for(int i = 0; i<n; i++){
        int tmp;
        cin >> tmp;
        tower.push_back(tmp);
    }
    LASER();
    return 0;
}