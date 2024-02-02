//Beakjoon Online Judge #11000
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<int, vector<int>, greater<int>> t_pq;
    t_pq.push(0);
    
    for(int i = 0; i<n; i++){
        int s, t;
        cin >> s >> t;
        pq.push({s, t});
    }

    while (!pq.empty())
    {
        if(t_pq.top()<=pq.top().first){
            t_pq.pop();
        }
        t_pq.push(pq.top().second);
        pq.pop();
    }
    cout << t_pq.size();
    return 0;
    
}