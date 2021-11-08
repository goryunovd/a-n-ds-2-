// a'n'ds (2).cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*some new commit*/
#include <iostream>
#include<ctime>
using namespace std;
int BinarySearch(int* massiv,int size,int data)// in binary search we have already sorted massiv, then we checked if element in half index is (less or equal) or (greater) and cut second or first half massiv 
{
	clock_t begin = clock();
  int index=-1;
  bool flag = false;
  int leftcorner = 0; 
  int rightcorner = size-1; 
  while ((leftcorner <= rightcorner) && (flag != true)) {
	 index = (leftcorner + rightcorner) / 2; 
	  if (massiv[index] == data) flag = true;//check if our element is in middle
	  if (massiv[index] > data) rightcorner = index - 1; // check which half should be deleted
	  else leftcorner	 = index + 1;
  }
  if (flag) return index; else
  {
	    throw invalid_argument("Not found element with this data\n");
  }
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << fixed << endl;
  cout << "required " << elapsed_secs << "seconds" << end;
}

int QuickSort(int* massiv,int size)
{//Указатели в начало и в конец массива
	int i = 0;
	int j = size - 1;

	//Центральный элемент массива
	int mid = massiv[size / 2];

	//Делим массив
	do {
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
	} while (i <= j);


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

/*int BubbleSort() {}
int Bogosor() {}
int CountingSort() {}
*/
int main()
{
	int size = 10;
	auto* massiv = new int[size];//use auto in case we have int & char type's of massiv
	for (int i = 0; i < 10; i++)
	{
		massiv[i] = 10 - i; cout << massiv[i] << " ";//0-1-2-3-4-5-6-7-8-9 
	}
//	cout<<BinarySearch(massiv, size, 2);
	cout << endl;
	QuickSort(massiv, size);
	for (int i = 0; i < 10; i++)
	{
		massiv[i] = 10 - i; cout << massiv[i] << " ";//0-1-2-3-4-5-6-7-8-9 
	}
}

