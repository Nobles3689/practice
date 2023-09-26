//Beakjoon Online Judge #27172
#include <iostream>
#include <vector>
using namespace std;

bool check[1000001] = {false, };

void cal(int player, vector<int> &v){
    vector<int> ans(1000001, 0);
    /*for(int i=0; i<player-1; i++){
        for(int j = i+1; j<player; j++){
            if(v[j]%v[i]==0){
                ans[i]++;
                ans[j]--;
            }else if(v[i]%v[j]==0){
                ans[j]++;
                ans[i]--;
            }
        }
    }*/

    for(int i = 0; i<player; i++){
        for(int j = v[i]*2; j<=1000000; j+=v[i]){
            if(check[j]){
                ans[v[i]]++;
                ans[j]--;
            }
        }
    }

    for(int i = 0; i<player; i++){
        cout << ans[v[i]] << ' ';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int player;
    cin >> player;
    vector<int> v(player);
    
    
    for(int i = 0; i<player; i++){
        cin >> v[i];
        check[v[i]] = true;
    }

    cal(player, v);
    return 0;
}