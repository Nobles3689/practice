//Beakjoon Online Judge #15649
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int list[8] = { 1, 2, 3, 4, 5, 6, 7, 8};
bool visit[8];
vector<int> ans;

void backtrack(){
    if(ans.size() == m){
        for(int i=0; i<m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i<n; i++){
        if(!visit[i])
        {
            ans.push_back(list[i]);
            visit[i] = true;
            backtrack();
            ans.pop_back();
            visit[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    backtrack();
    return 0;
}