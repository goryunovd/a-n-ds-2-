// a'n'ds (2).cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*some new commit*/
#include <iostream>
#include<ctime>
using namespace std;
int BinarySearch(int* massiv, int size, int data)// in binary search we have already sorted massiv, then we checked if element in half index is (less or equal) or (greater) and cut second or first half massiv 
{
	clock_t begin = clock();
	int index = -1;
	bool check_exist = false;//check if element with current data exist 
	bool check_sort = true;//check if every element is greater then previous
	int leftcorner = 0;
	int rightcorner = size - 1;
	for (int j = 0; j < size - 1; j++) { if (massiv[j] > massiv[j + 1]) check_sort = false; }
	if (check_sort) {
		while ((leftcorner <= rightcorner) && (check_exist != true)) {
			index = (leftcorner + rightcorner) / 2;
			if (massiv[index] == data) check_exist = true;//check if our element is in middle
			if (massiv[index] > data) rightcorner = index - 1; // check which half should be deleted
			else leftcorner = index + 1;
		}
		if (check_exist) return index; else
		{
			throw invalid_argument("Not found element with this data\n");
		}
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << fixed << endl;
		cout << "required " << elapsed_secs << "seconds" << end;
	}
	else { throw invalid_argument("Current massiv is not sorted from low to high data\n"); }
}

int QuickSort(int* massiv,int size)
{//Указатели в начало и в конец массива
	int i = 0;//left corner of sort of sort 
	int j = size - 1;//right corner of sort of sort
	int mid = massiv[size / 2];
	//Делим массив
	while (i <= j)
	{
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (massiv[i] < mid) {
			i++;
				
		}
		//В правой части пропускаем элементы, которые больше центрального
		while (massiv[j] > mid) {
			j--;
		}
		//Меняем элементы местами
		if (i <= j) {
			int tmp = massiv[i];
			massiv[i] = massiv[j];
			massiv[j] = tmp;
			i++;
			j--;
		}
	} 
	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		//"Левый кусок"
		QuickSort(massiv, j + 1);
	}
	if (i < size) {
		//"Првый кусок"
		QuickSort(massiv, size - i);
	}
	return *massiv;
}
//выше не работает 
void BubbleSort(int* massiv, int size) 
{
	bool flag; int tmp;
	for (int i = 0; i < size; i++)
	{
		flag = 0;
		for (int j = size - 1; j > i; j--)
			if (massiv[j - 1] > massiv[j])
			{
				tmp = massiv[j - 1];
				massiv[j - 1] = massiv[j];
				massiv[j] = tmp;
				flag = 1;
			}
		if (flag == 0) break;
	}
}/*
int Bogosor() {}
int CountingSort() {}
*/
int main()
{
	int size = 10;
	auto* massiv = new int[size];//use auto in case we have int & char type's of massiv
	for (int i = 0; i < 10; i++)
	{
		massiv[i] = rand()%100;
		//cin>>massiv[i];
		cout << massiv[i] << " ";//0-1-2-3-4-5-6-7-8-9 
	}
//	cout<<BinarySearch(massiv, size, 2);
	cout << endl;
//	QuickSort(massiv, size);
	/*
41 67 34 0 69 24 78 58 62 64
0 24 34 41 58 67 78 69 62 64
*/
	BubbleSort(massiv, size);
	for (int i = 0; i < 10; i++)
	{
		 cout << massiv[i] << " ";//0-1-2-3-4-5-6-7-8-9 
	}
}

