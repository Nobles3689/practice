#include <iostream>
using namespace std;
namespace Nobles {
    void printNName(){
        cout << "MyNickName : Nobles3689" << endl;
    }
}
using Nobles::printNName;

int main(){
    printNName();
    return 0;
}
