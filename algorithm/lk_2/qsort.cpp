#include <fstream>
#include <iostream>

using namespace std;
int array[100];
int count = 0;
int QSort (int first, int last);

int main () 
{
	int n;
	ifstream fin ("antiqs.in");
	fin >> n; // k-vo elementov

	int i = 1;
//	int array[n];
	for (i; i <= n; i++)
		fin >> array[i];
	fin.close();

//	int count = 0;;
        count = QSort(1, n); //вызов сортирующей процедуры


        //вывод упорядоченного массива
        for (i=1; i<=n; i++) 
		cout<<array[i]<<" ";
	cout << endl << count << endl;

//	ofstream fout ("sort.out");
//	for (i = 1; i <= n; i++)
//		fout << array[i] << " ";
//	fout.close();
	return 0;
}


	
int QSort(int left, int right)
{
	int i, j, key, buf, count;
	key = array[(left + right)/2];
	i = left;
	j = right;
	while (i<=j)
	{
		while (array[i] < key) {count++; i++;}
		while (key < array[j]) {count++; j--;}
		if (i <= j) 
		{
            		swap(array[i], array[j]);
            		i++; 
            		j--; 
			
		}
	}
	
	if (left < j) QSort(left, j); 
      	if (i < right) QSort(i, right); 

	
//	for (i=1; i<=right; i++)
//                cout<<array[i]<<" ";
//        cout << endl; 
}


