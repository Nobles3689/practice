//Beakjoon Online Judge #11050
#include <iostream>
using namespace std;

int fac(int a){
    if(a <=1)
        return 1;
    else
        return a*fac(a-1);
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    cout << fac(n)/(fac(n-k)*fac(k));
    return 0;


}