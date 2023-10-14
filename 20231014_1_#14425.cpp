//Beakjoon Online Judge #14425
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    set<string> s;
    for(int i = 0; i<n; i++){
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    int cnt = 0;
    for(int i = 0; i<m; i++){
        string tmp;
        cin >> tmp;
        if(s.find(tmp)!=s.end()) cnt++;
    }
    cout << cnt;
    return 0;
}