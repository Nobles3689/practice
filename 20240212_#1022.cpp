//Beakjoon Online Judge #1022
#include <bits/stdc++.h>
using namespace std;

int Student[32001];
vector<vector<int>> graph(32001);
int n, m;

void Cal(){
    queue<int> q;
    int flag = 0;
    while (flag<n)
    {   
        
        for(int i = 1; i<=n; i++){
            if(Student[i] == 0){
                q.push(i);
                Student[i] = -1;
            }
        }
        int tmp = q.front();
        q.pop();
        cout << tmp << ' ';
        flag++;
        for(int i = 0; i<graph[tmp].size(); i++){
            Student[graph[tmp][i]]--;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t1, t2;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> t1 >> t2;
        graph[t1].push_back(t2);
        Student[t2]++;
    }
    Cal();
    return 0;
}