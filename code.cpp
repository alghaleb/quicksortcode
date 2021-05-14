#include<iostream>
using namespace std;
 
// Swapping two values.
void swap(int *a, int *b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
 
// Partitioning the array on the basis of values at high as pivot value.
int partition(int array[], int low, int high)
{
	int pivot, index, i;
	index = low;
	pivot = high;
 
	// Getting index of pivot.
	for(i=low; i < high; i++)
	{
		if(array[i] < array[pivot])
		{
			swap(&array[i], &array[index]);
			index++;
		}
	}
	// Swapping value at high and at the index obtained.
	swap(&array[pivot], &array[index]);
 
	return index;
}
 
// Random selection of pivot.
int getRandomPivot(int array[], int low, int high)
{
	int pvt, n, temp;
	n = rand();
	// Randomizing the pivot value in the given subpart of array.
	pvt = low + n%(high-low+1);
 
	// Swapping pvt value from high, so pvt value will be taken as pivot while partitioning.
	swap(&array[high], &array[pvt]);
 
	return partition(array, low, high);
}
 
// Implementing QuickSort algorithm.
int quickSort(int array[], int first, int last)
{
	int pindex;
	if(first < last)
	{
		// Partitioning array using randomized pivot.
		pindex = getRandomPivot(array, first, last);
		// Recursively implementing QuickSort.
		quickSort(array, first, pindex-1);
		quickSort(array, pindex+1, last);
	}
	return 0;
}
 
 void print(int array[], int size) 
{
  for (int j = 0; j < size; j++)
    cout << array[j] << " ";
    cout << endl;
}

int main()
{
	int size;
	cout<<"\nEnter the size of your array: ";
	cin>>size;
 
	int array[size];
	for(int j = 0; j < size; j++)
	{
		cout<<"Enter element "<< j+1 <<": ";
		cin>>array[j];
	}
	
	cout << "\nArray before being sorted: ";
	print(array, size);
	
	quickSort(array, 0, size-1);
	
    cout << "\nArray after being sorted: ";
	print(array, size);

	return 0;
}
