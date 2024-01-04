//Beakjoon Online Judge #1725
#include <iostream>
#include <stack>
using namespace std;

int hight[100002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    stack<int> s;
    for(int i = 1; i<=N; i++){
        cin >> hight[i];
    }
    s.push(0);
    int ans = 0;
    for(int i = 1; i<=N+1; i++){
        while (!s.empty() && hight[s.top()] > hight[i])
        {
            int tmp = s.top();
            s.pop();
            ans = max(ans, hight[tmp] * (i-s.top()-1));
        }
        s.push(i);
        
    }
    cout << ans;
    return 0;
}