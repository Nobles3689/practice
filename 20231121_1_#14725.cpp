//Beakjoon Online Judge #14725
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Trie
{
private:
    map<string, Trie*> next;

public:
    
    void insert(vector<string>& room, int index){
        if(index == room.size())
            return;

        if(next.find(room[index]) == next.end()){
            next[room[index]] = new Trie();
        }

        next[room[index]]->insert(room, index+1);
    }

    void output(int floor){
        for(auto& a : next){
            for(int i = 0; i<floor; i++){
                cout << "--";
            }
            cout << a.first << '\n';
            a.second->output(floor+1);
        }
    }
    
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Trie *Root = new Trie();
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int nn;
        cin >> nn;
        vector<string> vs(nn);
        for(int j = 0; j<nn; j++){
            cin >> vs[j];
        }
        Root->insert(vs, 0);
    }

    Root->output(0);
    return 0;

}