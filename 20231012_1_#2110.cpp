//Beakjoon Online Judge #2110
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int src(int house, int router, vector<int> &v){
    int low = 1;
    int high = v[house-1] - v[0];
    int mid, ans, cnt, tmp;
    while (low<=high)
    {
        cnt = 1;
        mid = (high + low) / 2;
        tmp = v[0];
        for(int i = 1; i<v.size(); i++){
            if(v[i] - tmp >= mid){
                tmp = v[i];
                cnt++;
            }
        }
        if(cnt < router){
            high = mid - 1;
        }else{
            low = mid + 1;
            ans = mid;
        }
    }
    
    return ans;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int house, router;
    cin >> house >> router;
    vector<int> v(house);
    for(int i = 0; i<house; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << src(house, router, v);
    return 0;
}
/*
//Beakjoon Online Judge #2110
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int src(int house, int router, vector<int> &v){
    int low = 1;
    int high = v[house-1] - v[0];
    int mid;
    if(house == router){    
        return 1; 
    }
    //이게 1이 아님 -> 집의 좌표는 0부터 1000000000까지 나올수 있는데 집의 개수는 최대 200000개
    if(router == 2){
        return v[house-1] - v[0];
    }
    int ans = 0;
    while (low<=high)
    {
        mid = (high + low) / 2;
        int tmp = v[0];
        int cnt = 1;
        for(int i = 1; i<v.size(); i++){
            if(v[i] - tmp >= mid){
                tmp = v[i];
                cnt++;
            }
        }

        if(cnt>=router){
            low = mid + 1;
            ans = mid;
        }else{
            high = mid - 1;
        }
    }
    return ans;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int house, router;
    cin >> house >> router;
    vector<int> v(house);
    for(int i = 0; i<house; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << src(house, router, v);
    return 0;
}
*/