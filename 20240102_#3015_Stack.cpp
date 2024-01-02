//Beakjoon Online Judge #3015
#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    stack<pair<int, long long>> s;
    int tmp;
    long long cnt = 0;
    for(int i = 0; i<N; i++){
        cin >> tmp;
        while (!s.empty() && s.top().first < tmp)
        {
            
            cnt+=s.top().second;
            s.pop();
        }
        
        if(s.empty()) 
        {
            s.push({tmp, 1});
        }
        else if(s.top().first > tmp)
        {
            cnt++;
            s.push({tmp, 1});
        }
        else if(s.top().first == tmp)
        {
            int same = s.top().second + 1;
            s.pop();
            if(!s.empty()) cnt+=same;
            else cnt+=(same-1);
            
            s.push({tmp, same});
                
        }
        
    }
    cout << cnt;
    return 0;
    
}