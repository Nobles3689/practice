//Beakjoon Online Judge #11047
#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int coin, money;
    cin >> coin >> money;
    stack<int> c_s;
    for(int i = 0; i<coin; i++){
        int tmp;
        cin >> tmp;
        c_s.push(tmp);
    }
    int ans = 0;
    while (money>0)
    {
        int c_V = c_s.top();
        c_s.pop();
        ans+=money/c_V;
        money%=c_V;
    }
    cout << ans;
    return 0;
    
}