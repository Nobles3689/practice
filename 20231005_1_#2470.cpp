//Beakjoon Online Judge #2470
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;
    vector<int> v(num);
    for(int i = 0; i<num; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int start = 0;
    int end = num-1;
    int min = 2000000001;
    pair<int, int> ans = {0, 0};
    for(int i = 0; i<num-1; i++){
        int low = i+1, high = num-1;
        while (low<=high)
        {
            int mid = (low+high)/2;
            int tmp = v[i] + v[mid];
            int abst = abs(tmp);
            if(min>abst){
                min = abst;
                ans = {v[i], v[mid]};
            }
            if(tmp<0){
                low = mid+1;
            }else if(tmp>0){
                high = mid-1;
            }else{
                cout << v[i] << ' ' << v[mid];
                return 0;
            }
        }    
    }
    cout << ans.first << ' ' << ans.second;
    return 0;
}