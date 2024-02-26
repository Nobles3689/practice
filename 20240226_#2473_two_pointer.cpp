//Beakjoon Online Judge #2473
#include <bits/stdc++.h>
using namespace std;
#define MAX 1e10
typedef long long ll;

vector<ll> liq;
int n;
ll tmp, ans[3], min_acid = MAX;

void mix(){
    int left, right;
    
    for(int i = 0; i < n-2; i++){
        left = i+1;
        right = n-1;
        while (left<right)
        {
            ll tmp_sum = liq[i] + liq[left] + liq[right];
            ll abs_tmp_sum = abs(tmp_sum);
            if(tmp_sum == 0){
                min_acid = 0;
                ans[0] = i;
                ans[1] = left;
                ans[2] = right;
                return;
            }
            if(abs_tmp_sum < min_acid){
                min_acid = abs_tmp_sum;
                ans[0] = i;
                ans[1] = left;
                ans[2] = right;
            }

            if(tmp_sum > 0){
                right--;
            }else{
                left++;
            }


        }
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> tmp;
        liq.push_back(tmp);
    }
    sort(liq.begin(), liq.end());
    mix();
    for(int i = 0; i<3; i++){
        cout << liq[ans[i]] << ' ';
    }
    return 0;

}