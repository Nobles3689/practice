//Beakjoon Online Judge #17219
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, find;
    cin >> num >> find;
    map<string, string> pw;
    for(int i = 0; i<num; i++){
        string site, pass;
        cin >> site >> pass;
        pw.insert({site, pass});
    }
    for(int i = 0; i<find; i++){
        string site;
        cin >> site;
        cout << pw[site] << '\n';
    }
    return 0;
}