#include <iostream>
using namespace std;

int main(){
    char i[4];
    cin >> i;
    for(int j = 0; j<4; j++)
        cout << i[j]-'0' << endl;
    return 0;
}

