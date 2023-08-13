//Beakjoon Online Judge #11053
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int DP[1000] = { 0, };


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    for(int i = 0; i<num; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    int t_max = 0;

    for(int i = 0; i<num; i++){
        DP[i] = 1;
        for(int j = 0; j<i; j++){
            if(v[i]>v[j]){
                DP[i] = max(DP[j]+1, DP[i]);
            }else{
                t_max = max(t_max, DP[j]);
            }
        }
        t_max = max(t_max, DP[i]);
    }

    cout << t_max;

    return 0;

}