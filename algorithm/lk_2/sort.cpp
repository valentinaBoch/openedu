#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main () 
{
	int n;
	ifstream fin ("sort.in");
	fin >> n;

	int i = 0;
	int array[n];
	for (i; i < n; i++)
		fin >> array[i];
	fin.close();

	int temp = 0;
	for (i = 0; i < n-1; i++)
	{
		if (array[i] > array[i+1])
		{
			temp = array[i];
			array[i] = array[i+1];
			array[i+1] = temp;
		}
	}

	for (i = 0; i < n; i++)
        	cout << array [i];

	cout << endl;

//	ofstream fout ("sor.out");
//	fout << minNum + 1 << " " << avgNum +1 << " " << maxNum + 1;
//	fout.close();
	return 0;
}

