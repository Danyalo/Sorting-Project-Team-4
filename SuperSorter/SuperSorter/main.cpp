#include <iostream>
#include <cstdlib>

using namespace std;

void printArray(int arr[], int n);

void heapSort(int arr[], int n);			// main function to do heap sort
void heapify(int arr[], int n, int i);

void mergesort(int a[], size_t l, size_t h) {
	if (h - l == 1) {
		if (a[l] > a[h]) {
			int t = a[l];
			a[l] = a[h];
			a[h] = t;
		}
	}
	else if (h == l) {

	}
	else if (h > l) {
		size_t size = h - l + 1;
		size_t m = l + (h - l) / 2;
		mergesort(a, l, m);
		mergesort(a, m + 1, h);
		int* b = new int[size];
		size_t k = 0;
		size_t i = l;
		size_t j = m + 1;
		while (i <= m && j <= h)
			if (a[i] <= a[j])
				b[k++] = a[i++];
			else
				b[k++] = a[j++];

		while (i <= m)
			b[k++] = a[i++];

		while (j <= h)
			b[k++] = a[j++];

		for (k = 0; k < size; k++) {
			a[l + k] = b[k];
		}
		delete[] b;
	}
}

void mergesort(int a[], size_t size) {
	mergesort(a, 0, size - 1);
}

void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

int main()
{
	// sup
	cout << "Please enter the number of elemens in array: ";
	int n;
	cin >> n;
	int *arr = new int[n];
	cout << "Please enter your array:\n";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "Please choose your sorting method:\n";
	cout << "1 - Heap Sort \n";
	cout << "2 - Quick Sort \n";
	cout << "3 - Merge Sort \n";

	int sw;
	cin >> sw;
	switch (sw) {
		case 1:
			heapSort(arr, n);
			cout << "\nHeapSort successful! Here's to you: \n";
			printArray(arr, n);
			break;
		case 2:
			quickSort(arr, 0, n - 1);
			cout << "\nQuickSort successful! Here's to you: \n";
			printArray(arr, n);
			break;
		case 3:
			mergesort(arr, n);
			cout << "\nMergeSort successful! Here's to you: \n";
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
