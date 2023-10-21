//Beakjoon Online Judge #3273
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int find_sum(vector<int> &v, int n, int x){
    if(n==1) return 0;

    int s = 0 , e = n - 1, cnt = 0;
    while (s<e)
    {   
        int sum = v[s] + v[e];
        if(sum>x) e--;
        else if(sum<x) s++;
        else{
            cnt++;
            s++;
            e--;
        }
    }
    return cnt;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    vector<int> v;
    cin >> n;
    for(int i = 0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> x;
    sort(v.begin(), v.end());
    cout << find_sum(v, n, x);
    return 0;

}