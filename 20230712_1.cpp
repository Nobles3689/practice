//Beakjoon Online Judge #2839
#include <iostream>
using namespace std;
#define BIG 5
#define SMALL 3

int main(){
    int suger, bag;
    int flag;
    int result=5000;

    cin >> suger;
    flag = suger/BIG;
    for(int i = flag; i>-1; i--){
        int tmp1, tmp2;
        tmp1 = suger - (i*5);
        if((tmp1%SMALL)!=0){
            continue;
        }
        tmp2 = i+(tmp1/SMALL);
        if((tmp2<result)&&(tmp2!=0)){
            result = tmp2;
        }
    }
    if(result==5000){
        result = -1;
    }
    cout << result;
    return 0;
}