//Beakjoon Online Judge #1644
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 4000000

bool prim[MAX+1] = {false, };

void init(){
    prim[0] = true;
    prim[1] = true;
    for(int i = 2; i<=sqrt(MAX); i++){
        if(!prim[i]){
            for(int j = 2*i; j<=MAX; j+=i){
                prim[j] = true;
            }
        }
    }
}

int prim_find(int num){
    int res = 0, sum = 0;
    for(int i = 0; i<=num; i++){
        if(!prim[i]){
            sum+=i;
            if(sum == num){
                res++;
                continue;
            }
            for(int j = i+1; j<=num; j++){
                if(sum == num){
                    res++;
                    break;
                }
                if(!prim[j]){
                    sum+=j;
                    if(sum>num){
                        break;
                    }
                }
            }
            sum = 0;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int num;
    cin >> num;
    cout << prim_find(num);
    return 0;
}