//Beakjoon Online Judge #11725
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> link[100001];
bool visit[100001] = { 0, };
int ans[100001];


void BFS(int n){
    queue<int> q;
    visit[n] = true;
    q.push(n);

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();

        for(int i = 0; i<link[tmp].size(); i++){
            int c = link[tmp][i];
            if(!visit[c]){
                ans[c] = tmp;
                visit[c] = true;
                q.push(c);
            }
        }
    }
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;

    for(int i = 0; i<num-1; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        link[tmp1].emplace_back(tmp2);
        link[tmp2].emplace_back(tmp1);
    }

    BFS(1);
    for(int i = 2; i<=num; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}