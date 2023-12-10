//Beakjoon Online Judge #11729
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



void hanoi(int n, int a, int b, int c){
    if(n==1) cout << a << ' ' << c << '\n';
    else{
        hanoi(n-1, a, c, b);
        cout << a << ' ' << c << '\n';
        hanoi(n-1, b, a, c);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int cnt = pow(2, N) - 1;
    cout << cnt << '\n';
    hanoi(N, 1, 2, 3);
    return 0;
    
}