//Beakjoon Online Judge #1654
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll cnt(vector<int> &v, int mid){
    ll sum = 0;
    for(int i = 0; i<v.size(); i++){
        sum += v[i]/mid;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N;
    cin >> K >> N;
    vector<int> v(K);
    for(int i = 0; i<K; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll low = 1, high = v[K-1];
    ll mid = (high + low) / 2;

    ll ans = 0;

    while (low<=high)
    {
        ans = cnt(v, mid);
        if(ans>=N) low = mid + 1;
        else if(ans<N) high = mid - 1;
        mid = (high + low) / 2;
    }

    cout << mid;
    return  0;

    

}