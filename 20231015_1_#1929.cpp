//Beakjoon Online Judge #1929
#include <iostream>
#include <vector>
using namespace std;

vector<bool> v(1000001, true);

void cal(){
    v[0] = false;
    v[1] = false;
    for(int i = 2; i<=1000001; i++){
        if(v[i]){
            for(int j = i*2; j<=1000001; j+=i){
                v[j] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cal();
    int m, n;
    cin >> m >> n;
    for(int i = m; i<=n; i++){
        if(v[i]) cout << i << '\n';
    }
    return 0;

}