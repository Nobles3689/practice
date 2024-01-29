//Beakjoon Online Judge #9466
#include <bits/stdc++.h>
using namespace std;

int n;
int student[100001];
int matching[100001];
bool visited[100001];

void DFS(int n){


    if(visited[n]){
        if(matching[n] == 1) return;
        matching[n] = 1;
    }else{
        if(matching[n] != 0) return;
        matching[n] = -1;
    }
    visited[n] = true;
    DFS(student[n]);
    visited[n] = false;
    return;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    for(int t = 0; t<tc; t++){
        int cnt = 0;
        cin >> n;
        for(int i = 1; i<=n; i++){
            int tmp;
            cin >> tmp;
            student[i] = tmp;
        }
        for(int i = 1; i<=n; i++){
            if(matching[i] == 0){
                DFS(i);
            }
        }
        for(int i = 1; i<=n; i++){
            if(matching[i] == -1) cnt++;
        }
        cout << cnt << '\n';
        memset(student, 0, sizeof(int)*(n+1));
        memset(matching, 0, sizeof(int)*(n+1));
        memset(visited, false, sizeof(bool)*(n+1));
    }
    return 0;
}