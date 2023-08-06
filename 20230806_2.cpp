//Beakjoon Online Judge #11659
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num1, num2;
    
    cin >> num1 >> num2;
    int s = 0;
    v.push_back(s);
    for(int i = 0; i<num1; i++){
        int tmp;
        cin >> tmp;
        s+= tmp;
        v.push_back(s);
    }
    for(int i = 0; i<num2; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        cout << v[tmp2]-v[tmp1-1] << '\n';
    }
    return 0;

}