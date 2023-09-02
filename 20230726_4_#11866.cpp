//Beakjoon Online Judge #11866
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for(int i = 1; i<n+1; i++){
        q.push(i);
    }
    cout << '<';
    while (!q.empty())
    {
        int tmp;
        for(int i = 0; i<k-1; i++){
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        tmp = q.front();
        q.pop();
        if(q.empty()) cout << tmp << '>';
        else cout << tmp << ", ";
    }
    return 0;
    
}
