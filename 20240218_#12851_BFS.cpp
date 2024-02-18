//Beakjoon Online Judge #12851
#include <bits/stdc++.h>
using namespace std;

int ans = -1;
int cnt = 0;

void BFS(int n, int k){
    queue<pair<int, int>> q;
    bool checked[100001] = {0, };
    q.push({n, 0});
    pair<int, int> tmp;
    
    while (!q.empty())  
    {
        tmp = q.front();
        q.pop();
        if(tmp.first == k){
            if(ans == -1){
                ans = tmp.second;
                cnt++;
                continue;
            }else if(ans == tmp.second){
                cnt++;
                continue;
            }else if(ans < tmp.second) break;
        }
        checked[tmp.first] = true;

        if(tmp.first-1 >= 0 && !checked[tmp.first-1]){
            q.push({tmp.first-1, tmp.second+1});
        }
        if(tmp.first+1 <= 100000 && !checked[tmp.first+1]){
            q.push({tmp.first+1, tmp.second+1});
        }
        if(tmp.first*2 <= 100000 && !checked[tmp.first*2]){
            q.push({tmp.first*2, tmp.second+1});
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    BFS(N, K);
    cout << ans << '\n' << cnt;
    return 0;

}