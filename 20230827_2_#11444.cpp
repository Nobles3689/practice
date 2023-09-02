//Beakjoon Online Judge #11444 분할정복을 이용한 거듭제곱(피보나치 수)
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;
#define ANS 1000000007

typedef vector<vector<long long>> matrix;
vector<matrix> power;
vector<int> bin;

matrix mat_mult(matrix& a, matrix& b){
    matrix tmp = {{0, 0}, {0, 0}};

    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            for(int k = 0; k<2; k++){
                tmp[i][j] += a[i][k]*b[k][j];
                tmp[i][j] %= ANS;
            }
        }
    }

    return tmp;
}

void init_p(long long n){
    n--;
    while (n != 0)
    {
        if(n%2 == 1)
            bin.push_back(1);
        else
            bin.push_back(0);
        n/=2;
    }
    //reverse(bin.begin(), bin.end());
    power.push_back({{1, 1}, {1, 0}});
    for(int i = 0; i<bin.size(); i++){
        power.push_back(mat_mult(power[i], power[i]));
    }
    
    
}

void fib(long long num, matrix& a){
    init_p(num);
    for(int i = 0; i<bin.size(); i++){
        if(bin[i])
            a = mat_mult(power[i], a);
    }
    
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long num;
    cin >> num;

    matrix a = {{1,0}, {0,1}};
    matrix mat = {{1, 1}, {1, 0}};
    fib(num, a);

    cout << a[0][0];
    return 0;
}