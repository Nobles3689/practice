#include <iostream>
using namespace std;

int main(){
    int a[4] = { 1, 2, 3, 4};
    for (int i = 0; i < (1 << 4); i++)
	{
        cout << "i : " << i << '\n';
		int sum = 0;
		for (int j = 0; j < 4; j++)
		{
			if (i & (1 << j)){
                cout << j << '\n';
                sum += a[j];
            }
            
		}
        cout << '\n';
	}
    return 0;
}

