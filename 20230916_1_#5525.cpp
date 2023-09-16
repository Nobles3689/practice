//Beakjoon Online Judge #5525
#include <iostream>
#include <queue>
#include <string>
using namespace std;

string init(int n){
    string s = "I";
    for(int i = 0; i<n; i++){
        s+="OI";
    }
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string s;
    cin >> n >> m >> s;
    //string pn = init(n);
    queue<int> q;
    int ans = 0;
    /*for(int i=0; i<=s.size()-pn.size();){
        size_t index = s.find(pn, i);
        if(index != string::npos){
            i = (int)index + 1;
            ans++;
        }else{
            break;
        }
    }*/
    int tmp = 0;
    for(int i = 0; i<m-2;){
        if(s[i]=='I' && s[i+1]=='O' && s[i+2]=='I'){
            tmp++;           
            i+=2;
            q.push(tmp);
        }else{
            if(tmp != 0)
                tmp = 0;
            i++;
        }
    }
    int ex = 0;
    while (!q.empty())
    {   
        
        int t = q.front();
        q.pop();
        if(t == 1){
            int cal = ex - n + 1;
            
            if(cal > 0){
                ans += cal;
            }
        }
        ex = t;
    }
    if((ex - n + 1)>0){
        ans += ex - n + 1;
    }
    
    cout << ans;
    return 0;
}