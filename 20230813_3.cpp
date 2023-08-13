//Beakjoon Online Judge #14002, #14003
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
    vector<int> a;
    vector<pair<int, int>> ans1(num);
    vector<int> ans2;
    int intmin = - 1000000001;
    for(int i = 0; i<num; i++){
        cin >> v[i];
    }


    for(int i = 0; i<num; i++){
        int index = lower_bound(a.begin(), a.end(), v[i]) - a.begin();
        if(index == a.size()) a.emplace_back(v[i]);
        else{
            a[index] = v[i];
        }
        ans1[i] = {v[i], index};

        
    }

    
    int cnt = a.size()-1;
    for(int i = num-1; i>=0; i--){
        if(cnt == ans1[i].second){
            ans2.push_back(ans1[i].first);
            cnt--;
        }
    }

    cout << a.size() << '\n';
    for(int i = ans2.size()-1; i>=0; i--){
        cout << ans2[i] << ' ';
    }
    return 0;
}