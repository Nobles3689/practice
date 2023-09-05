//Beakjoon Online Judge #1541
#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    string tmp;
    cin >> tmp;
    string num = "";
    bool flag = false;
    for(int i = 0; i<=tmp.length(); i++){
        if(tmp[i]=='+'||tmp[i]=='-'||i==tmp.length()){
            if(flag)    ans-=stoi(num);
            else    ans+=stoi(num);
            num = "";
        }else{
            num+=tmp[i];
        }
        if(tmp[i]=='-'){
            flag = true;
        }
    }

    cout << ans;
    return 0;
    
}