//Beakjoon Online Judge #9095
#include <iostream>
using namespace std;
int ans[11] = {0, 1, 2, 4, };



void init(){
    for(int i = 4; i<11; i++){
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    }
}




int main(){
    int num;
    cin >> num;
    init();
    for(int i = 0; i<num; i++){
        int tmp;
        cin >> tmp;
        cout << ans[tmp] << '\n';
    }
    return 0;
}