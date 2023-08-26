//Beakjoon Online Judge #1918
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
stack<char> s;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string tmp;
    cin >> tmp;
    int flag = 0;
    for(int i = 0; i<tmp.length(); i++){
        if(tmp[i]=='+'){
            while (!s.empty())
            {
                if(s.top()!='('){
                    cout << s.top();
                    s.pop();
                }else{
                    break;
                }
            }
            s.push(tmp[i]);
            
        }else if(tmp[i]=='-'){
            while (!s.empty())
            {
                if(s.top()!='('){
                    cout << s.top();
                    s.pop();
                }else{
                    break;
                }
            }
            s.push(tmp[i]);
            
        }else if(tmp[i]=='*'){
            while (!s.empty())
            {
                if(s.top()=='*'||s.top()=='/'){
                    cout << s.top();
                    s.pop();
                }else{
                    break;
                }
            }
            s.push(tmp[i]);

        }else if(tmp[i]=='/'){
            while (!s.empty())
            {
                if(s.top()=='*'||s.top()=='/'){
                    cout << s.top();
                    s.pop();
                }else{
                    break;
                }
            }
            s.push(tmp[i]);
            
        }else if(tmp[i]=='('){
            s.push(tmp[i]);
        }else if(tmp[i]==')'){
            while (s.top()!='(')
            {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }else{
            cout << tmp[i];
        }
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    
    return 0;

}