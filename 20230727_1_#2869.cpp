//Beakjoon Online Judge #2869
#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a, b, v;
    cin >> a >> b >> v;
    v-=a;
    if(v<=0){
        cout << 1;
        return 0;
    }
    int pm = a-b;
    int result = (v/pm)+1;
    int rem = v%pm;
    if(rem!=0){
        result++;
    }
    cout << result;
    return 0;
}