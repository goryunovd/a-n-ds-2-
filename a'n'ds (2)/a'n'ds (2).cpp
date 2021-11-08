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
/*
int QuickSort() {}
int BubbleSort() {}
int Bogosor() {}
int CountingSort() {}
*/
int main()
{
	int size = 10;
	auto* massiv = new int[size];//use auto in case we have int & char type's of massiv
	for (int i = 0; i < 10; i++)
	{
		massiv[i] = i; //0-1-2-3-4-5-6-7-8-9 
	}
	cout<<BinarySearch(massiv, size, 2);

}

