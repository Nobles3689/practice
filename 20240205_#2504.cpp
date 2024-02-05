//Beakjoon Online Judge #2504
#include <bits/stdc++.h>
using namespace std;

vector<int> tmp(31);
stack<char> tmp_s;
string s;
char ex;
int idx = 0;

void cal(){
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '['){
            tmp_s.push(s[i]);
            idx++;
            ex = s[i];

        }else if(s[i] == ')'){
            if(tmp_s.empty()){
                tmp[0] = 0;
                return;
            }
            if(tmp_s.top() != '('){
                tmp[0] = 0;
                return;
            }

            if(ex == '('){
                idx--;
                tmp[idx] += 2;
                ex = s[i];
                tmp_s.pop();
            }else if(ex == ')' || ex == ']'){
                int t = tmp[idx]*2;
                tmp[idx] = 0;
                idx--;
                tmp[idx] += t;
                ex = s[i];
                tmp_s.pop();
            }else{
                tmp[0] = 0;
                return;
            }

        }else if(s[i] == ']'){
            if(tmp_s.empty()){
                tmp[0] = 0;
                return;
            }
            if(tmp_s.top() != '['){
                tmp[0] = 0;
                return;
            }

            if(ex == '['){
                idx--;
                tmp[idx] += 3;
                ex = s[i];
                tmp_s.pop();
            }else if(ex == ')' || ex == ']'){
                int t = tmp[idx]*3;
                tmp[idx] = 0;
                idx--;
                tmp[idx] += t;
                ex = s[i];
                tmp_s.pop();
            }else{
                tmp[0] = 0;
                return;
            }
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    getline(cin, s);
    cal();
    cout << tmp[0];
    return 0;
}