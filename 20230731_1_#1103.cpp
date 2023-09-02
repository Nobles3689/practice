//Beakjoon Online Judge #1003
#include <iostream>
using namespace std;

int main(){
    int zero[41];
    int one[41];
    fill_n(zero, 41, 0);
    fill_n(one, 41, 0);
    zero[0] = 1;
    one[1] = 1;

    for(int i = 2; i<41; i++){
        zero[i] = zero[i-1] + zero[i-2];
        one[i] = one[i-1] + one[i-2];
    }
    int num, tmp;

    cin >> num;
    for(int i = 0; i<num; i++){
        cin >> tmp;
        cout << zero[tmp] << ' ' << one[tmp] << '\n';
    }
    return 0;
}
//메모이제이션(memoization)