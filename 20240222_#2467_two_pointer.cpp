//Beakjoon Online Judge #2467
#include <bits/stdc++.h>
using namespace std;

int n, l[100000], lp = 0, rp, val, ans = 2000000001, l_ans = 0, r_ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    rp = n-1;
    for(int i = 0; i<n; i++){
        cin >> l[i];
    }
    
    while (lp<rp)
    {
        val = l[lp] + l[rp];
        if(abs(val) < ans){
            ans = abs(val);
            l_ans = l[lp];
            r_ans = l[rp];
            
        }

        if(val == 0) break;
        else if(val>0) rp--;
        else lp++;
    }
    cout << l_ans << ' ' << r_ans << '\n';
    return 0;
    
}