//Beakjoon Online Judge #9935
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stack<char> s;
    string tmp;
    string tmp2;
    string boom;
    cin >> tmp >> boom;
    reverse(boom.begin(), boom.end());
    for(int i = 0; i<tmp.length(); i++){
        s.push(tmp[i]);
        int j = 0;
        if(s.size()<boom.length()) continue;
        else{
            while (j < boom.length())
            {
                if(s.top() == boom[j]){
                    j++; s.pop();
                }else break;
            }
            if(j < boom.length()){
                for(int k = j-1; k>=0; k--){
                    s.push(boom[k]);
                }
            }
        }
    }
    if(s.empty()){
        cout << "FRULA";
    }else{
        while (!s.empty())
        {
            tmp2+=s.top();
            s.pop();
        }
        reverse(tmp2.begin(), tmp2.end());
        cout << tmp2;
        
    }
    
    return 0;
    
}