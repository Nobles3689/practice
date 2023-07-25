//Beakjoon Online Judge #4153
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int sum = -1;
    while(true){
        int A, B, C, tmp, flag = 0;
        cin >> A >> B >> C;
        tmp = A + B + C;
        if(tmp == 0){
            break;
        }
        tmp = A;
        if(B>tmp){
            tmp = B;
            flag = 1;
        }
        if(C>tmp){
            flag = 2;
        }

        if(flag == 0){
            if(pow(A,2) == pow(B,2) + pow(C,2)){
                cout << "right\n";
            }else{
                cout << "wrong\n";
            }
        }else if(flag == 1){
            if(pow(B,2) == pow(A,2) + pow(C,2)){
                cout << "right\n";
            }else{
                cout << "wrong\n";
            }
        }else if(flag == 2){
            if(pow(C,2) == pow(A,2) + pow(B,2)){
                cout << "right\n";
            }else{
                cout << "wrong\n";
            }
        }
    }
    return 0;
}