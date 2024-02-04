//Beakjoon Online Judge #1013
#include <bits/stdc++.h>
using namespace std;


bool detect(string sig){
    int state = 0;
    int index = 0;

    while (index<sig.length())
    {
        switch (state)
        {
        case 0:
            if(sig[index] == '0') state = 7;
            else if(sig[index] == '1') state = 1;
            index++;
            break;
        case 1:
            if(sig[index] == '0') state = 2;
            else if(sig[index] == '1') state = -1;
            index++;
            break;
        case 2:
            if(sig[index] == '0') state = 3;
            else if(sig[index] == '1') state = -1;
            index++;
            break;
        case 3:
            if(sig[index] == '0') state = 3;
            else if(sig[index] == '1') state = 4;
            index++;
            break;
        case 4:
            if(sig[index] == '0') state = 7;
            else if(sig[index] == '1') state = 5;
            index++;
            break;
        case 5:
            if(sig[index] == '0') state = 6;
            else if(sig[index] == '1') state = 5;
            index++;
            break;
        case 6:
            if(sig[index] == '0') state = 3;
            else if(sig[index] == '1') state = 8;
            index++;
            break;
        case 7:
            if(sig[index] == '0') state = -1;
            else if(sig[index] == '1') state = 8;
            index++;
            break;
        case 8:
            if(sig[index] == '0') state = 7;
            else if(sig[index] == '1') state = 1;
            index++;
            break;

        default:
            return false;
            break;
        }
    }
    if(state == 4 || state == 5 || state == 8) return true;
    else return false;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    string sig;
    getline(cin, sig);
    for(int t = 0; t<tc; t++){
        getline(cin, sig);
        //for(int i = 0; i<sig.length(); i++) cout << sig[i];
        if(detect(sig)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}