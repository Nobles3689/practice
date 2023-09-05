//Beakjoon Online Judge #11727
#include <iostream>
#include <vector>
using namespace std;

int DP(int n, vector<int> &v){
    if(n==1){
        if(v[1]==0)
            v[1] = 1;
        return v[1];
    }else if(n==2){
        if(v[2]==0)
            v[2] = 3;
        return v[2];
    }else{
        if(v[n]==0)
            v[n] = (DP(n-1, v)+(DP(n-2,v)*2))%10007;
        return v[n];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;
    vector<int> v(num+1, 0);
    cout << DP(num, v)%10007;
    return 0;

}