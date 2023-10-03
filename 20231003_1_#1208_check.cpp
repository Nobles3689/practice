//Beakjoon Online Judge #1208
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(41);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num, goal;
    cin >> num >> goal;
    int mid = num / 2;
    vector<int> first;
    vector<int> second;
    for(int i = 0; i<num; i++){
        cin >> v[i];
    }

    for(int i = 0; i<(1 << mid); i++){
        int sum = 0;
        for(int j = 0; j<mid; j++){
            if(i & (1 << j)) sum += v[j];
        }
        first.push_back(sum);
    }
    for(int i = 0; i<(1 << (num - mid)); i++){
        int sum = 0;
        for(int j = 0; j<(num-mid); j++){
            if(i & (1 << j)) sum += v[mid + j];
        }
        second.push_back(sum);
    }
    sort(second.begin(), second.end());
    long long ans = 0;
    for(int i = 0; i<first.size(); i++){
        auto it = equal_range(second.begin(), second.end(), goal - first[i]);
        ans += it.second - it.first;
    }
    if(goal == 0) ans--;
    cout << ans;
    return 0;

}