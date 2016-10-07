#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main () 
{
	int n;
	ifstream fin ("sortland.in");
	fin >> n;

	int i = 0;
	double array[n];
	for (i; i < n; i++)
		fin >> array[i];
	fin.close();
	double min, avg, max;
	int minNum, avgNum, maxNum;
	min = avg = max = array [0];
	minNum = avgNum = maxNum = 0; 
	for (i = 1; i < n; i++)
	{
		if (min > array[i]) 
		{
			min = array[i];
			minNum = i;
		}

		if (max < array[i])
                {
                        max = array[i];
                        maxNum = i;
                }
	}

	sort (array, array + n);
	avg = array [n/2];

	ifstream finput ("sortland.in");
	finput >> n;
	double arr[n];
	for (i = 0; i < n; i++)
        {
	        finput >> arr[i];
		if (avg == arr[i]) 
			avgNum = i;
	}
	finput.close();

	ofstream fout ("sortland.out");
	fout << minNum + 1 << " " << avgNum +1 << " " << maxNum + 1;
	fout.close();
	return 0;
}

