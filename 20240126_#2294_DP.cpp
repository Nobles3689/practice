//Beakjoon Online Judge #2294
#include <bits/stdc++.h>
using namespace std;

vector<int> coins;
int DP[10001];
int n, k;

void cal(int value, int coin_num){
    if(value > k) return;
    if(coin_num < DP[value]) DP[value] = coin_num;
    else return;
    if(value == k) return;
    for(int i = 0; i<coins.size(); i++){
        cal(value+coins[i], coin_num+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    fill_n(DP, k+1, 11000);
    for(int i = 0; i<n; i++){
        int tmp;
        cin >> tmp;
        coins.push_back(tmp);
    }
    cal(0, 0);
    if(DP[k] == 11000) DP[k] = -1;
    cout << DP[k];
    return 0;
}