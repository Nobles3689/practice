//Beakjoon Online Judge #4673
#include <bits/stdc++.h>
using namespace std;

bool checked[10050];

int self_num(int n){
    string tmp = to_string(n);
    int ret = n;
    for(int i = 0; i<tmp.length(); i++){
        ret+=(tmp[i]-48);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tmp;
    for(int i = 1; i<=10000; i++){
        tmp = self_num(i);
        if(!checked[tmp]) checked[tmp] = true;
    }

    for(int i = 1; i<=10000; i++){
        if(!checked[i]) cout << i << '\n';
    }

    return 0;
}
