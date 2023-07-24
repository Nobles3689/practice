//Beakjoon Online Judge #1978
#include <iostream>
#include <cmath>
using namespace std;



int main(){
    int max = 1001;
    bool prim[max];
    for(int i = 2; i<max; i++){
        prim[i] = true;
    }
    prim[0] = false;
    prim[1] = false;


    for(int i = 2; i<sqrt(max)+1; i++){
        if (prim[i]==true){
            for(int j = 2; j*i<=max; j++){
                prim[i*j] = false;
            }
        }
    }
    int num, flag=0;
    cin >> num;
    for(int i = 0; i<num; i++){
        int tmp;
        cin >> tmp;
        if(prim[tmp]==true){
            flag++;
        }
    }
    cout << flag;
    return 0;
}