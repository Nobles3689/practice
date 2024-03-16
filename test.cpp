#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "HelloThisisMixedUpChallengeofCrypandRev";
    for(int i = 0; i<s.length(); i++){
        if(isupper(s[i]))
            cout << (char)((s[i]-44)%26+65);
        if(islower(s[i]))
            cout << (char)((s[i]-81)%26+97);
    }
    return 0;
}

