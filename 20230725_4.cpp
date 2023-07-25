//Beakjoon Online Judge #2609
#include <iostream>
using namespace std;

int GCD(int a, int b){
    if(b==0) return a;
    else return GCD(b, a % b);
}


int main(){
    int a, b;
    cin >> a >> b;
    int gcd = GCD(a, b), lcm;
    lcm = (a * b) / gcd;
    cout << gcd << '\n' << lcm;
    return 0;
}