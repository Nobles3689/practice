//Beakjoon Online Judge #1193
#include <iostream>
using namespace std;

int main(){
    int num;
    int i = 1;
    cin >> num;
    while (num>i)
    {
        num-=i;
        i++;
    }
    int flag = i%2;
    int deno, numer;

    if(flag==0){
        deno = i + 1 - num;
        numer = num;
    }else if(flag == 1){
        numer = i + 1 - num;
        deno = num;
    }

    cout << numer << '/' << deno;
    return 0;
    
}
