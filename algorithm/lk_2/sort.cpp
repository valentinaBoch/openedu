#include <fstream>
#include <iostream>

using namespace std;
void Merge (int *a, int first, int last);
void MergeSort (int *a, int first, int last);
ofstream fout ("sort.out");

int main () 
{
	int n;
	ifstream fin ("sort.in");
	fin >> n;

	int i = 1;
	int *array = new int[100];
	for (i; i <= n; i++)
		fin >> array[i];
	fin.close();

        MergeSort(array, 1, n); //вызов сортирующей процедуры
//        cout<<"Result sort: "; //вывод упорядоченного массива
        for (i=1; i<=n; i++) 
		cout<<array[i]<<" ";
        delete []array;
	cout << endl;

//	ofstream fout ("sort.out");
	for (i = 1; i <= n; i++)
		fout << array[i] << " ";
	fout.close();
	return 0;
}


void Merge (int *a, int first, int last)
{	
//	ofstream fout("sort.out");
	int middle, start, final, i;
	int *mas = new int [1000000000];// [last];
	middle = (first + last)/2;
//	cout << middle << endl;
	start = first; //начало левой части
	final = middle+1; //начало правой части

//cout << start << " " << final << " " << mas [start] << " " << a [middle] << endl;
	for (i = first; i <= last; i++) //выполнять от начала до конца
	{
//		cout << start << " " << middle << " " << a [start] << " " << a [final] << endl;
		if ((start <= middle) && ((final > last) || (a[start] < a[final])))
		{
			mas[i] = a[start];
//			cout << start << " " << final << " " << mas [start] << " " << a [middle] << endl;
			start++;	
		}
		else
		{
			mas[i]=a[final];
//			cout << start << " " << final << " " << mas [start] << " " << a [middle] << endl;
			final++;
		}
//		cout << start << " " << final << " " << mas [start] << " " << a [middle] << endl; 
	}

	//возвращение результата в список
	for (i=first; i<=last; i++) 
		a[i]=mas[i];

//	fout.close();
	cout << start << " " << final << " " << mas [start] << " " << a [middle] << endl;
	delete[]mas;
//      cout << start << " " << final << " " << mas [start] << " " << a [middle] << endl;

};

//рекурсивная процедура сортировки
void MergeSort(int *a, int first, int last)
{
        if (first<last)
        {
                MergeSort(a, first, (first+last)/2); //сортировка левой части
                MergeSort(a, (first+last)/2+1, last); //сортировка правой части
                Merge(a, first, last); //слияние двух частей
        }
};

