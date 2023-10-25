//Beakjoon Online Judge #17103
#include <iostream>
#include <vector>
using namespace std;

vector<bool> pri(1000001, true);

void ari(){
    pri[0] = false;
    pri[1] = false;
    for(int i = 2; i<=1000001; i++){
        if(pri[i]){
            for(int j = i*2; j<=1000001; j+=i){
                pri[j] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ari();
    int tc;
    cin >> tc;
    for(int i = 0; i<tc; i++){
        int num, cnt = 0;
        cin >> num;
        for(int i = 1; i<=num/2; i++){
            if(pri[i] && pri[num - i])
                cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}