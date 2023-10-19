//Beakjoon Online Judge #5073
#include <iostream>
#include <vector>
using namespace std;

bool cal(int a, int b, int c){
    if(a+b<=c||b+c<=a||c+a<=b){
        return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int sum = -1;
    while (sum!=0)
    {
        int a, b, c, cnt=0;;
        cin >> a >> b >> c;
        sum = a + b + c;
        if(sum==0) break;
        if(a==b) cnt++;
        if(b==c) cnt++;
        if(c==a) cnt++;
        if(!cal(a, b, c)) cnt = 4;
        
        switch (cnt)
        {
        case 0:
            cout << "Scalene\n";
            break;
        case 1:
            cout << "Isosceles\n";
            break;
        case 3:
            cout << "Equilateral\n";
            break;
        case 4:
            cout << "Invalid\n";
            break;
        }
        
    }
    return 0;
    
}