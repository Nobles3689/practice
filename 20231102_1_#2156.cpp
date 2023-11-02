//Beakjoon Online Judge #2156
#include <iostream>
#include <vector>
using namespace std;

vector<int> glass(10001, 0);
vector<int> DP(10001, 0);

int cal(int num){
    for(int i = 3; i<=num; i++){
        DP[i] = max(max(DP[i-1], DP[i-2]+glass[i]), DP[i-3]+glass[i]+glass[i-1]);
    }
    return DP[num];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    
    for(int i = 1; i<=num; i++){
        cin >> glass[i];
    }
    DP[1] = glass[1];
    DP[2] = glass[1]+glass[2];
    cout << cal(num);
    return 0;

}