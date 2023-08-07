//Beakjoon Online Judge #11726
#include <iostream>
using namespace std;
int rec[1001];

int main(){
    int num;
    rec[0] = 0;
    rec[1] = 1;
    rec[2] = 2;
    for(int i = 3; i<1002; i++){
        rec[i] = (rec[i-1] + rec[i-2])%10007;
    }
    cin >> num;
    cout << rec[num];
    return 0;

}