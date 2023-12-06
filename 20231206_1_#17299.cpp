//Beakjoon Online Judge #17299
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
vector<int> cnt(1000001, 0);
stack<int> s;
stack<int> ss;
stack<int> res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i<n; i++){
        int tmp;
        cin >> tmp;
        s.push(tmp);
        cnt[tmp]++;
    }

    for(int i = 0; i<n; i++){
        int ex = s.top();
        s.pop();
        while (!ss.empty()&&cnt[ss.top()]<=cnt[ex])
        {
            ss.pop();
        }
        if(ss.empty()){
            res.push(-1);
        }else{
            res.push(ss.top());
        }
        ss.push(ex);
        
    }
    while (!res.empty())
    {
        cout << res.top() << ' ';
        res.pop();
    }
    return 0;
}
