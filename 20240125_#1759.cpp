//Beakjoon Online Judge #1759
#include <bits/stdc++.h>
using namespace std;

int L, C;
set<char> s;
char print_arr[15];

bool find(){
    int flag = 0;
    for(int i = 0; i<L; i++){
        if(print_arr[i] == 'a' || print_arr[i] == 'e' || print_arr[i] == 'i' || print_arr[i] == 'o' || print_arr[i] == 'u')
            flag++;
    }
    int remain = L - flag;


    return (flag != 0) && (remain >= 2);
}

void comb(int l, int c){
    if(l == L && find()){
        for(int i = 0; i<l; i++){
            cout << print_arr[i];
        }
        cout << '\n';
        return;
    }
    auto it = s.begin();
    for(int i = 0; i<c; i++){
        it++;
    }
    int flag = 0;
    for(it; it != s.end(); it++){
        flag++;
        print_arr[l] = *it;
        comb(l+1, c+flag);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    cin >> L >> C;
    for(int i = 0; i<C; i++){
        char tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    comb(0, 0);
    return 0;
}