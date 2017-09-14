#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	cout << "Please enter the number of elemens in array: ";
	int n;
	cin >> n;
	int *arr = new int[n];
	cout << "Please enter your array:\n";
	for (int i = 0; i < n; i++)
		cin >> arr[i];


	delete[] arr;

	return 0;
}