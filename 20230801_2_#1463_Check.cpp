//Beakjoon Online Judge #1463
#include <iostream>
#include <algorithm>
using namespace std;

int Min[1000001];

int make1(int n){
    if(n<=1){
        return 0;
    }
    
    int& tmp = Min[n];

    if(tmp!=-1){
        return tmp;
    }

    if(n%6==0){
        tmp = min(min(make1(n/3), make1(n/2)), make1(n-1)) + 1;
        return tmp;

    }else if(n%3==0){
        tmp = min(make1(n/3), make1(n-1)) + 1;
        return tmp;
    }else if(n%2==0){
        tmp = min(make1(n/2), make1(n-1)) + 1;
        return tmp;
    }else{
        tmp = make1(n-1) + 1;
        return tmp;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    fill_n(Min, 1000001, -1);
    cin >> num;

    cout << make1(num);

    return 0;
    
}