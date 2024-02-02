//Beakjoon Online Judge #1655
#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> max_pq;
priority_queue<int> min_pq;


void insert(int a){
    if(a > min_pq.top()){
        max_pq.push(a);
    }else{
        min_pq.push(a);
    }


    if(max_pq.size() > min_pq.size()){
        min_pq.push(max_pq.top());
        max_pq.pop();
    }else if(min_pq.size() - 1 > max_pq.size()){
        max_pq.push(min_pq.top());
        min_pq.pop();
    }

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    max_pq.push(10001);
    min_pq.push(-10001);
    for(int i = 0; i<n; i++){
        int tmp;
        cin >> tmp;
        insert(tmp);
        cout << min_pq.top() << '\n';
        

    }
    return 0;
}