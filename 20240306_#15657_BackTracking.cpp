//Beakjoon Online Judge #15657
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
int ans[8];

void bt(int cnt, int idx){
    if(cnt > m) return;

    if(cnt == m){
        for(int i = 0; i<m; i++){
            cout << ans[i] << ' ';
        }
        cout <<  '\n';
        return;
    }

    for(int i = idx; i<n; i++){
        ans[cnt] = a[i];
        bt(cnt+1, i);
    }    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());

    bt(0, 0);
    return 0;
}