//Beakjoon Online Judge #17298
#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;
    stack<int> l;
    for(int i = 0; i<num; i++){
        int tmp;
        cin >> tmp;
        l.push(tmp);
    }
    stack<int> s;
    stack<int> M;
    s.push(-1);
    int T = l.top();
    l.pop();
    for(int i = 0; i<num-1; i++){
        if(T>l.top()){
            M.push(T);
            s.push(T);
            T = l.top();
        }else{
            T = l.top();
            while (!M.empty())
            {
                if(M.top()>T) break;
                M.pop();
            }
            if(M.empty()) s.push(-1);
            else s.push(M.top());
        }
        l.pop();
    }
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}