//Beakjoon Online Judge #11054
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    vector<int> v(num);
    vector<int> a(num, 1);
    vector<int> b(num, 1);
    for(int i = 0; i<num; i++){
        cin >> v[i];
    }
    
    
    for(int i = 0; i<num; i++){
        for(int j = i+1; j<num; j++){
            if(v[j]>v[i]) a[j] = max(a[j], a[i] + 1);
        }    
    }
    for(int i = num-1; i>=0; i--){
        for(int j = i-1; j>=0; j--){
            if(v[j]>v[i]) b[j] = max(b[j], b[i] + 1);
        }    
    }


    int res = 0;
    for(int i = 0; i<num; i++){
        res = max(res, a[i] + b[i] - 1);
    }

    cout << res;
    return 0;

}