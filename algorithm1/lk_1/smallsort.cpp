#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
	int n;
	ifstream fin ("smallsort.in");
	fin >> n;

	int i = 0, array[n];
	for (i; i < n; i++)
		fin >> array[i];

	sort (array, array+n);
	
	ofstream fout ("smallsort.out");
	i = 0;
	for (i; i < n; i++)
		fout << array[i] << " ";
	fin.close();
	fout.close();
	return 0;
}

