//Beakjoon Online Judge #11444
#include <iostream>
#include <vector>
using namespace std;
#define ANS 1000000007

typedef vector<vector<long long>> matrix;

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

void fib(long long num, matrix& a, matrix& mat){
    long long tmp = num;
    while (tmp>0)
    {
        if(tmp % 2 == 1)
            a = mat_mult(a, mat);
        mat = mat_mult(mat, mat);
        tmp /= 2;
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
    fib(num, a, mat);

    cout << a[0][1];
    return 0;
}