//Baekjoon Online Judge #2798
#include <iostream>
using namespace std;

int main(){
    int x, y, m = 0, result=0;
    int n[100];
    cin >> x >> y;
    for(int i = 0; i<x; i++){
        cin >> n[i];
    }
    for(int i = 0; i<x-2; i++){
        for(int j = i+1; j<x-1; j++){
            for(int k = j+1; k<x; k++){
                m = n[i] + n[j] + n[k];
                if(m<=y && m>result){
                    result = m;
                }

            }
        }
    }
    cout << result;
    return 0;
}