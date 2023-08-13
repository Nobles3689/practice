//Beakjoon Online Judge #12015
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    vector<int> v(num);
    vector<int> a;
    unordered_map<int, int> ans1;
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
        ans1[v[i]] = (index == 0) ? intmin : a[index-1];
    }

    
    int tmp = a.back();
    while (tmp!=intmin)
    {
        ans2.emplace_back(tmp);
        tmp = ans1[tmp];
    }
    cout << a.size() << '\n';
    for(int i = ans2.size()-1; i>=0; i--){
        cout << ans2[i] << ' ';
    }
    return 0;
}