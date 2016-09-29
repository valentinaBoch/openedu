#include <fstream>
#include <iostream>

using namespace std;

int main ()
{
	int a, b;
	char buff[50];
	ifstream fin ("aplusb.in");
	fin >> a;
	fin >> b;
	ofstream fout ("aplusb.out");
	fout << a+b;
	fin.close();
	fout.close();
	return 0;
}
