//Beakjoon Online Judge #12015, #12738
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    vector<int> v(num);
    vector<int> a(num);

    for(int i = 0; i<num; i++){
        cin >> v[i];
    }
    int ans = 0;
    a[0] = v[0];

    for(int i = 1; i<num; i++){
        if(a[ans] < v[i]){
            a[++ans] = v[i];
        }else{
            int index = lower_bound(a.begin(), a.begin() + ans, v[i]) - a.begin();
            a[index] = v[i];
        }
    }

    cout << ans+1;
    return 0;
}