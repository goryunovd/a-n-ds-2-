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
void QuickSort(int* array, int low, int high) //choose middle element and sort near him
{
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
		QuickSort(array, low, right);//go sort left part
	if (left < high)
		QuickSort(array, left, high);//go sort right part
}
void BubbleSort(int* array, int size) //alway compare elements and if previous is bigger swap them
{
	bool flag; 
	for (int i = 0; i < size; i++)
	{
		flag = 0;
		for (int j = size - 1; j > i; j--)
			if (array[j - 1] > array[j])
			{
				swap(array[j - 1], array[j]);
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
void send_to_god_of_random(int* array, int size)//random change of elements
{
	for (int i = 0; i < size; i++)
		swap(array[i], array[rand() % size]);
}
void BogoSort(int* array, int size)//if array isn't sorted let the random sort it
{
	while (!isSorted(array, size))
		send_to_god_of_random(array, size);
}
void CountingSort(char* array, int size)
//for this sort we use array of type char but we can also sort as int in case char has his own int index am i right?0-0
//ASCII table
{
	int high_number = 0; int z;
	for (int i=0;i<size;i++)	{		if (array[i] > high_number) { high_number = array[i];}	}//find the highest number in ASCCII ttable
	high_number++;
	int* count_array = new int[high_number];
	for (int i =0 ; i < high_number; i++) //make NULL augmented array
	{
		count_array[i] = 0;
	}
	for (int i = 0; i < size; i++) //in augmented[array[i]] we count how many this symbol we meet 
	{ z = array[i];
	count_array[z]++; 
	}
	int i = 0;
	for (int j = 0; j < high_number; j++) {
		while (count_array[j] != 0) {
			array[i] = j ;
			count_array[j]--;
			i++;
		}
	}
	delete count_array;
}

void time_fuction(int* array_BubbleSort,int* array_QuickSort,  int size)//to compare 2 times of different algorthimes 
{
	clock_t end = clock(); clock_t begin = clock();
	double elapsed_secs_B = double(end - begin) / CLOCKS_PER_SEC;//BubbleSort
	double elapsed_secs_Q = double(end - begin) / CLOCKS_PER_SEC;//QuickSort
	elapsed_secs_B = 0; elapsed_secs_Q = 0;
	for (int i = 0; i < 10; i++)
	{
		begin = clock();
		BubbleSort(array_BubbleSort, size);  end = clock();
		elapsed_secs_B += double(end - begin) / CLOCKS_PER_SEC;
	}
	elapsed_secs_B = elapsed_secs_B / 10;
	cout << "10 BubbleSort["<<size<<"] required " << elapsed_secs_B << "seconds" << endl;
	for (int i = 0; i < 10; i++) {
		begin = clock();
		QuickSort(array_QuickSort, 0, size - 1); 
		end = clock(); elapsed_secs_Q += double(end - begin) / CLOCKS_PER_SEC; 
	}
	elapsed_secs_Q = elapsed_secs_Q / 10;
	cout << "10 QucikSort [" << size << "] required " << elapsed_secs_Q << "seconds" << endl;
	if (elapsed_secs_Q < elapsed_secs_B) { cout << "QuickSort is faster\n"; }
	else { cout << "BubbleSort is faster\n"; }
	cout << endl;

}
void Compare_of_2_sorts()
{
	srand(time(NULL));
	int size =  10;
	int size1 = 100;
	int size2 = 1000;
	int size3 = 10000;
	int size4 = 100000;
	
	int* array_QuickSort = new int[size];
	int* array_QuickSort1 = new int[size1];
	int* array_QuickSort2 = new int[size2];
	int* array_QuickSort3 = new int[size3];
	int* array_QuickSort4 = new int[size4];

	int* array_BubbleSort = new int[size];
	int* array_BubbleSort1 = new int[size1];
	int* array_BubbleSort2 = new int[size2];
	int* array_BubbleSort3 = new int[size3];
	int* array_BubbleSort4 = new int[size4];
	
	clock_t end = clock(); clock_t begin = clock();
	double elapsed_secs_B = double(end - begin) / CLOCKS_PER_SEC;//BubbleSort
	double elapsed_secs_Q = double(end - begin) / CLOCKS_PER_SEC;//QuickSort
	for (int i = 0; i < size; i++)	{ array_BubbleSort[i] = rand() % 100; 		array_QuickSort[i] = rand() % 100;	}
	for (int i = 0; i < size1; i++) { array_BubbleSort1[i] = rand() % 100; 		array_QuickSort1[i] = rand() % 100; }
	for (int i = 0; i < size2; i++) { array_BubbleSort2[i] = rand() % 100; 		array_QuickSort2[i] = rand() % 100; }
	for (int i = 0; i < size3; i++) { array_BubbleSort3[i] = rand() % 100; 		array_QuickSort3[i] = rand() % 100; }
	for (int i = 0; i < size4; i++) { array_BubbleSort4[i] = rand() % 100; 		array_QuickSort4[i] = rand() % 100; }
	

	time_fuction(array_BubbleSort, array_QuickSort, size);
	time_fuction(array_BubbleSort1, array_QuickSort1, size1);
	time_fuction(array_BubbleSort2, array_QuickSort2, size2);
	time_fuction(array_BubbleSort3, array_QuickSort3, size3);
	time_fuction(array_BubbleSort4, array_QuickSort4, size4);
	delete array_QuickSort, array_QuickSort1, array_QuickSort2, array_QuickSort3, array_QuickSort4, array_BubbleSort, array_BubbleSort1, array_BubbleSort2, array_BubbleSort3, array_BubbleSort4;
}
int main()
{
	srand(time(NULL));
	int size = 10;
	char* array_CountingSort = new char[size];for (int i = 0; i < size; i++) 
	{ array_CountingSort[i]=67 - i; cout << array_CountingSort[i]<<" ";}// CBA@?>=<;:
	cout << endl;
	int* array_BinarySearch = new int[size];
	int* array_BubbleSort= new int[size];
	int* array_Bogosort= new int[size];
	int* array_QuickSort= new int[size];
	int* array_main = new int[size];	
	for (int i = 0; i < size; i++)
	{
		array_main[i] = rand() % 100; 
		array_BinarySearch[i] = i+1;//1-2-3-4-5-6-7-8-9-10
		array_BubbleSort[i] = array_main[i];
		array_Bogosort[i] = array_main[i];
		array_QuickSort[i] = array_main[i];
		cout << array_main[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << array_BinarySearch[i] << " ";
	}
	cout << endl;
	clock_t begin = clock(); 
	cout<<"index with data 2 is"<<BinarySearch(array_BinarySearch, size, 2);
	clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << fixed << endl;
		cout << "BinarySearch required " << elapsed_secs << "seconds" << endl;
	 begin = clock();
	BubbleSort(array_BubbleSort, size);  end = clock();
		 elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << fixed << endl;
		cout << "BubbleSort required " << elapsed_secs << "seconds" << endl;
	 begin = clock();
	QuickSort(array_QuickSort, 0, size-1); //need to compare with bubble
		 end = clock();
		 elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << fixed << endl;
		cout << "QuickSort required " << elapsed_secs << "seconds" << endl;
	 begin = clock(); 
	BogoSort(array_Bogosort, size);
		 end = clock();
		 elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << fixed << endl;
		cout << "BogoSort required " << elapsed_secs << "seconds" << endl;
	 begin = clock(); 	
	CountingSort(array_CountingSort, size);
		 end = clock();
		 elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << fixed << endl;
		cout << "CountingSort required " << elapsed_secs << "seconds" << endl;
		cout << "BubbleSort";	for (int i = 0; i < size; i++) { cout << array_BubbleSort[i] << " "; }cout << endl;
		cout << "QuickSort";	for (int i = 0; i < size; i++) { cout << array_QuickSort[i] << " "; }cout << endl;
		cout << "BogoSort";		for (int i = 0; i < size; i++) { cout << array_Bogosort[i] << " "; }cout << endl;
		cout <<"CountingSort";	for (int i = 0; i < size; i++) { cout << array_CountingSort[i] << " "; }cout << endl;
		Compare_of_2_sorts();
		delete array_BinarySearch, array_BubbleSort, array_Bogosort, array_QuickSort, array_main;
}

