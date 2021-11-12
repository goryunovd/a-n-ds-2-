// a'n'ds (2).cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*some new commit*/
#include <iostream>
#include<ctime>
using namespace std;
int BinarySearch(int* array, int size, int data)// in binary search we have already sorted array, then we checked if element in half index is (less or equal) or (greater) and cut second or first half array 
{
	
	int index = -1;
	bool check_exist =false;//check if element with current data exist 
	bool check_sort = true;//check if every element is greater then previous
	int leftcorner = 0;
	int rightcorner = size - 1;
	for (int j = 0; j < size - 1; j++) { if (array[j] > array[j + 1]) check_sort = false; }
	if (check_sort) {
		while ((leftcorner <= rightcorner) && (check_exist != true)) {
			index = (leftcorner + rightcorner) / 2;
			if (array[index] == data) check_exist = true;//check if our element is in middle
			if (array[index] > data) rightcorner = index - 1; // check which half should be deleted
			else leftcorner = index + 1;
		}
		if (check_exist) return index; else
		{
			throw invalid_argument("Not found element with this data\n");
		}
		
	}
	else { throw invalid_argument("Current array is not sorted from low to high data\n"); }
}
void QuickSort(int* array, int low, int high) {
	int left = low;
	int right = high;
	int middle = array[(left + right) / 2];
	int tmp;

	while (left <= right)
	{
		while (array[left] < middle)
			left++;
		while (array[right] > middle)
			right--;
		if (left <= right)
		{
			tmp = array[left];
			array[left] = array[right];
			array[right] = tmp;
			left++;
			right--;
		}
	}
	if (right > low)
		QuickSort(array, low, right);
	if (left < high)
		QuickSort(array, left, high);
}
void BubbleSort(int* array, int size) 
{
	bool flag; int tmp;
	for (int i = 0; i < size; i++)
	{
		flag = 0;
		for (int j = size - 1; j > i; j--)
			if (array[j - 1] > array[j])
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				flag = 1;
			}
		if (flag == 0) break;
	}
}
bool isSorted(int* array, int size)
{
	for (int i = 0; i < size - 1; i++) {
		if (array[i] > array[i + 1])
			return false;
	}
	
	return true;
}
void send_to_god_of_random(int* array, int size)
{
	for (int i = 0; i < size; i++)
		swap(array[i], array[rand() % size]);
}
void BogoSort(int* array, int size)
{
	while (!isSorted(array, size))
		send_to_god_of_random(array, size);
}
void CountingSort(char* array, int size)
//for this sort we use array of type char but we can also sort as int in case char has his own int index am i right?0-0
//ASCII table
{
	int high_number = 0; int z;
	for (int i=0;i<size;i++)	{		if (array[i] > high_number) { high_number = array[i];}	}
	high_number++;
	int* count_array = new int[high_number];
	for (int i =0 ; i < high_number; i++) //lets count how many 
	{
		count_array[i] = 0;
	}
	for (int i = 0; i < size; i++) 
	{ z = array[i];
	count_array[z]++; 
	}
	for (int i =0 ; i < high_number; i++)
	{
		cout << count_array[i]<<" ";
	}
	cout << endl;
	int i = 0;
	for (int j = 0; j < high_number; j++) {
		while (count_array[j] != 0) {
			array[i] = j ;
			count_array[j]--;
			i++;
		}
	}
}
int main()
{
	srand(time(NULL));
	int size1 = 10;
	char* array1 = new char[size1];
	for (int i = 0; i < size1; i++) { cin >> array1[i]; }//zyxwvutsrqp	))('&%$###!!!
	cout << endl;
	for (int i = 0; i < size1; i++) { cout << array1[i]; }
	auto* array = new int[size1];//use auto in case we have int & char type's of array
	//for (int i = 0; i < size1; i++){array[i] = rand()%100;		cout << array[i] << " "; 	}
	cout << endl;
	clock_t begin = clock(); 
//	cout<<BinarySearch(array, size1, 2);
	//BubbleSort(array, size1);
	//QuickSort(array, 0, size1-1);
	//BogoSort(array, size1);
	CountingSort(array1, size1);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << fixed << endl;
	cout << "required " << elapsed_secs << "seconds" << endl;
	for (int i = 0; i < size1; i++)	{ cout << array1[i] << " ";	}
	}

