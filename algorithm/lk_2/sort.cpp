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

void SortAlgo::mergeSort(int data[], int lenD)
{
  if(lenD>1){
    int middle = lenD/2;
    int rem = lenD-middle;
    int* L = new int[middle];
    int* R = new int[rem];
    for(int i=0;i<lenD;i++){
      if(i<middle){
        L[i] = data[i];
      }
      else{
        R[i-middle] = data[i];
      }
    }
    mergeSort(L,middle);
    mergeSort(R,rem);
    merge(data, lenD, L, middle, R, rem);
  }
}
 
void SortAlgo::merge(int merged[], int lenD, int L[], int lenL, int R[], int lenR){
  int i = 0;
  int j = 0;
  while(i<lenL||j<lenR){
    if (i<lenL & j<lenR){
      if(L[i]<=R[j]){
        merged[i+j] = L[i];
        i++;
      }
      else{
        merged[i+j] = R[j];
        j++;
      }
    }
    else if(i<lenL){
      merged[i+j] = L[i];
      i++;
    }
    else if(j<lenR){
      merged[i+j] = R[j];
      j++;
    }
  }
}

