//Beakjoon Online Judge #1011
#include <bits/stdc++.h>
using namespace std;

int cal(int a, int b){
    double tmp = (b - a) * 4.0 - 3.0;
    tmp = sqrt(tmp);
    return (int)tmp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    for(int i=0; i<tc; i++){
        int a, b;
        cin >> a >> b;
        cout << cal(a, b) << '\n';
    }
    return 0;

}