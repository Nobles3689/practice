//Beakjoon Online Judge
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num, weight;
    cin >> num >> weight;
    if(weight==0){
        cout << 1;
        return 0;
    }
    vector<int> v(num);
    for(int i = 0; i<num; i++){
        cin >> v[i];
    }
    vector<long long> first;
    vector<long long> second;
    int mid = num/2;
    for(int i = 0; i<(1 << mid); i++){
        long long sum = 0;
        for(int j = 0; j<mid; j++){
            if(i & (1 << j)) sum += v[j];
        }
        first.push_back(sum);
    }
    for(int i = 0; i<(1 << (num - mid)); i++){
        long long sum = 0;
        for(int j = 0; j<(num-mid); j++){
            if(i & (1 << j)) sum += v[mid + j];
        }
        second.push_back(sum);
    }
    sort(second.begin(), second.end());
    long long ans = 0;
    for(int i = 0; i<first.size(); i++){
        auto it = upper_bound(second.begin(), second.end(), weight - first[i]);
        ans += it - second.begin();
    }
    cout << ans;
    return 0;
    
}