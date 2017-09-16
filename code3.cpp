#include <iostream>  
using namespace std;

int reserver(int n)
{
	int m = 0;
	while (n) {  
        m = m * 10 + n % 10;  
        n /= 10;  
    }
    return m;
}

int main(int argc, char const *argv[])
{
	int num;
	cin>>num; 
    int the_reserver_int = reserver_int(num);
    cout<<the_reserver_int;

	return 0;
}