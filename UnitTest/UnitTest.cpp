#include "pch.h"
#include<ctime>
#include "CppUnitTest.h"
#include"..\a'n'ds (2)\a'n'ds (2).cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(Test_BinarySearch)//search index of element by data
		{
			int size = 10;
			int* array = new int[10];
			for (int i = 0; i < 10; i++) { array[i] = i+1; }//1-2-3-4-5-6-7-8-9-10
			Assert::AreEqual(BinarySearch(array, size, 2), 1);//random index
			Assert::AreEqual(BinarySearch(array, size, 1), 0);//element at first index
			Assert::AreEqual(BinarySearch(array, size, 9), 8);//element at last index;
			bool check = 0;
			try
			{
				BinarySearch(array, size, 11);
			}
			catch (std::invalid_argument)
			{
				check = true;
			}
			Assert::IsTrue(check);
			int* massiv_from_high_to_low = new int[10];
			for (int i = 0; i < 10; i++) { array[i] = 10 - i; }//10-9-8-7-6-5-4-3-2-1
			bool checl_HIGHlow = 0;
			try 
			{
				BinarySearch(massiv_from_high_to_low, size, 6);
			}
			catch (std::invalid_argument)
			{checl_HIGHlow = 1; }
			Assert::IsTrue(checl_HIGHlow);
		}
		TEST_METHOD(Test_QuickSort)
		{
			int size =10;
			int* array = new int[size];
			for (int i = 0; i < size; i++) { array[i] = 9 - i; }//9-8-7-6-5-4-3-2-1-0
			QuickSort(array,0, size-1);
			Assert::AreEqual(array[0], 0);
			Assert::AreEqual(array[1], 1);
			Assert::AreEqual(array[2], 2);
			Assert::AreEqual(array[3], 3);
			Assert::AreEqual(array[4], 4);
			Assert::AreEqual(array[5], 5);
			Assert::AreEqual(array[6], 6);
			Assert::AreEqual(array[7], 7);
			Assert::AreEqual(array[8], 8);
			Assert::AreEqual(array[9], 9);
		}
		TEST_METHOD(Test_bubbleSort) 
		{
			int size = 10;
			int* array = new int[size];
			for (int i = 0; i < size; i++) { array[i] = i; }//0-1-2-3-4-5-6-7-8-9
			BubbleSort(array, size);
			Assert::AreEqual(array[0], 0);
			Assert::AreEqual(array[1], 1);
			Assert::AreEqual(array[2], 2);
			Assert::AreEqual(array[3], 3);
			Assert::AreEqual(array[4], 4);
			Assert::AreEqual(array[5], 5);
			Assert::AreEqual(array[6], 6);
			Assert::AreEqual(array[7], 7);
			Assert::AreEqual(array[8], 8);
			Assert::AreEqual(array[9], 9);
			for (int i = 0; i < size; i++) { array[i] = 9 - i; }
			BubbleSort(array, size);
			Assert::AreEqual(array[0], 0);
			Assert::AreEqual(array[1], 1);
			Assert::AreEqual(array[2], 2);
			Assert::AreEqual(array[3], 3);
			Assert::AreEqual(array[4], 4);
			Assert::AreEqual(array[5], 5);
			Assert::AreEqual(array[6], 6);
			Assert::AreEqual(array[7], 7);
			Assert::AreEqual(array[8], 8);
			Assert::AreEqual(array[9], 9);	
		}
		TEST_METHOD(Test_BogoSort)
		{
			srand(time(NULL));
			int size = 5;
			int* array = new int[size];
			for (int i = 0; i < size; i++) { array[i] = 4 - i; }//9-8-7-6-5-4-3-2-1-0
			BogoSort(array, size);
			Assert::AreEqual(array[0], 0);
			Assert::AreEqual(array[1], 1);
			Assert::AreEqual(array[2], 2);
			Assert::AreEqual(array[3], 3);
			Assert::AreEqual(array[4], 4);
		}
		TEST_METHOD(Test_CountingSort)
		{
			int size = 10;
			char* array = new char[size];
			for (int i = 0; i < size; i++) { array[i] = 67 - i; }// CBA@?>=<;:
			CountingSort(array, size);
			Assert::AreEqual(array[0],':');
			Assert::AreEqual(array[1],';');
			Assert::AreEqual(array[2],'<');
			Assert::AreEqual(array[3],'=');
			Assert::AreEqual(array[4],'>');
			Assert::AreEqual(array[5],'?');
			Assert::AreEqual(array[6],'@');
			Assert::AreEqual(array[7],'A');
			Assert::AreEqual(array[8],'B');
			Assert::AreEqual(array[9],'C');
		}
	};
}
