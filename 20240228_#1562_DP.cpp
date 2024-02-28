//Beakjoon Online Judge #1562
#include <bits/stdc++.h>
using namespace std;
#define divi 1000000000

int n;
int DP[10][100][4];

int stair_num(int bit, int num, int idx){
    int& tmp = DP[num][idx][bit];
    if(tmp) return tmp;
    if(idx >= n-1){
        if(bit == 3) return 1;
        else return 0;
    }

    if(num < 9){
        tmp += stair_num(bit | (num + 1 == 9 ? 2 : 0), num + 1, idx + 1);
        tmp %= divi;
    }
    if(num > 0){
        tmp += stair_num(bit | (num - 1 == 0 ? 1 : 0), num - 1, idx + 1);
        tmp %= divi;
    }
    return tmp;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int ans = 0;
    for(int i = 1; i<10; i++){
        ans+=stair_num(i == 9 ? 2 : 0, i, 0);
        ans%=divi;
    }
    cout << ans << '\n';
    return 0;


}