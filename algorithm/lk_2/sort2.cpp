#include <iostream>
#include <fstream>

using namespace std;

//#define maxn 100

void merge(int * arr, int l, int r) 
{
	ofstream fout ("sort.out", std::ios_base::app);
	if (r == l)
	{	
		fout << l << " " << r << " " << arr[l] << " " << arr [r] << endl;
        	return;
 	}   	
	if (r - l == 0) 
	{ 
        	if (arr[r] < arr[l])
            		swap(arr[r], arr[l]);
        	return;
    	}

	int m = (r + l) / 2;
    	merge(arr, l, m);
    	merge(arr, m + 1, r);
    	int buf[r];
    	int xl = l;
    	int xr = m + 1;
    	int cur = 0;
//	int count = 0;
    	while (r - l + 1 != cur) 
	{
		fout << xl << " " << xr << " ";
        	if (xl > m)
            	{
			fout  << arr[xl] << " " << arr [xr] << endl;
			buf[cur++] = arr[xr++];
		}
        	else 
			if (xr > r)
            		{	
				fout << arr[xl] << " " << arr [xr] << endl;
				buf[cur++] = arr[xl++];	
        		}
			else 
				if (arr[xl] > arr[xr])
				{
					fout << arr[xr] << " " << arr [xl] << endl;
            				buf[cur++] = arr[xr++];
				}
        			else 
				{
					fout << arr[xl] << " " << arr [xr] << endl;
 					buf[cur++] = arr[xl++];

				}
    	}
    	for (int i = 0; i < cur; i++)
        	arr[i + l] = buf[i]; 
//	for (int i = 1; i <= r; i++) cout << arr[i] << " ";
	fout.close();
	
}

int main() 
{    
	int n;
        ifstream fin ("sort.in");
        fin >> n;

        int i = 1;
        int *array = new int[100];
        for (i; i <= n; i++)
                fin >> array[i];
        fin.close();

	merge(array, 1, n);

//	for (int i = 1; i <= n; i++)
//        	cout << array[i] << " ";
	ofstream fout ("sort.out", std::ios_base::app);
	for (int i = 1; i <= n; i++)
              fout << array[i] << " ";
	fout.close();
	return 0;
}
