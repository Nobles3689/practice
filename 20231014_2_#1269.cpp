//Beakjoon Online judge #1269
#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    set<int> A;
    set<int> B;
    int res = 0;
    for(int i = 0; i<a; i++){
        int tmp;
        cin >> tmp;
        A.insert(tmp);
    }
    for(int i = 0; i<b; i++){
        int tmp;
        cin >> tmp;
        B.insert(tmp);
    }
    set<int>::iterator it;

    for(it = A.begin(); it != A.end(); it++){
        if(B.find(*it)==B.end()){
            res++;
        }
    }
    for(it = B.begin(); it != B.end(); it++){
        if(A.find(*it)==A.end()){
            res++;
        }
    }
    cout << res;
    return 0;
}