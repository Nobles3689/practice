//Baekjoon Online Judge #24511
#include <iostream>
#include <queue>
#include <stack>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num1, num2;
    cin >> num1;
    vector<int> v(num1);
    stack<int> s;
    queue<int> q;
    for(int i = 0; i<num1; i++){
        cin >> v[i];
    }
    for(int i = 0; i<num1; i++){
        int t;
        cin >> t;
        if(v[i] == 0) s.push(t);
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    
    
    cin >> num2;
    for(int i = 0; i<num2; i++){
        int t1;
        cin >> t1;
        q.push(t1);
        t1 = q.front();
        q.pop();
        cout << t1 << ' ';
    }

    
    return 0;
    
}