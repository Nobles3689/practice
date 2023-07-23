//Beakjoon Online Judge #1181
#include <iostream>
#include <string>
#include <set>
using namespace std;

struct comp
{
    bool operator()(const string& left, const string& right) const
    {
        if(left.size() == right.size()){
            return left < right;
        }else{
            return left.size() < right.size();
        }
    }
};


int main(){
    int num;
    set<string, comp> voca;
    cin >> num;
    for(int i = 0; i<num; i++){
        string tmp;
        cin >> tmp;
        voca.insert(tmp);
    }

    for(const auto& str : voca){
        cout << str << '\n';
    }

    return 0;
}