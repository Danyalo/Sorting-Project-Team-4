#include <iostream>
#include <cstdlib>

using namespace std;

void printArray(int arr[], int n);

void heapSort(int arr[], int n);			// main function to do heap sort
void heapify(int arr[], int n, int i);

int main()
{
	cout << "Please enter the number of elemens in array: ";
	int n;
	cin >> n;
	int *arr = new int[n];
	cout << "Please enter your array:\n";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "Please choose your sorting method:\n";
	cout << "1 - Heap Sort \n";


	int sw;
	cin >> sw;
	switch (sw) {
		case 1:
			heapSort(arr, n);
			cout << "\nHeapSort successful! Here's to you: \n";
			printArray(arr, n);
			break;
		default:
			cout << "\nOops! \n";
	}

	system("pause");

	delete[] arr;

	return 0;
}

void printArray(int arr[], int n)
{
	for (int i = 0; i<n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

void heapify(int arr[], int n, int i)
{
	// Find largest among root, left child and right child
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Swap and continue heapifying if root is not largest
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	// Build max heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Heap sort
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);

		// Heapify root element to get highest element at root again
		heapify(arr, i, 0);
	}
}