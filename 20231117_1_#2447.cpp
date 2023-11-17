//Beakjoon Online Judge #2447
#include <iostream>
#include <vector>
using namespace std;

void star(int n, int m, int num){
    if((n/num) % 3 == 1 && (m/num) % 3 == 1) cout << ' ';
    else{
        if(num == 1){
            cout << '*';
        }else star(n, m, num/3);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    for(int i = 0; i<num; i++){
        for(int j = 0; j<num; j++){
            star(i, j, num);
        }
        cout << '\n';
    }
    return 0;

}