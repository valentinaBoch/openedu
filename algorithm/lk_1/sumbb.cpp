#include <fstream>
#include <iostream>

using namespace std;

int main ()
{
	long long int a, b;
//	double res;
	char testres[100];
	ifstream fin ("aplusbb.in");
	fin >> a;
	fin >> b;
	ofstream fout ("aplusbb.out");
//	cout << (b)*(b);
//	cout << res << "\n";
	fout << a+(b)*(b);
	fin.close();
	fout.close();
	return 0;
}
