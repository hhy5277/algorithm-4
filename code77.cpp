#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a;
	cout<<"input a int num"<<endl;
	cin >> a;
    
    int n = 1;
    int count = 0;

    while (n <= a) {
        if ((n & a) != 0) {
        	count++;
        }

        n = n << 1;
    }

    cout << count << endl;

	return 0;
}