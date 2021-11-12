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
			int* massiv = new int[10];
			for (int i = 0; i < 10; i++) { massiv[i] = i+1; }//1-2-3-4-5-6-7-8-9-10
			Assert::AreEqual(BinarySearch(massiv, size, 2), 1);//random index
			Assert::AreEqual(BinarySearch(massiv, size, 1), 0);//element at first index
			Assert::AreEqual(BinarySearch(massiv, size, 9), 8);//element at last index;
			bool check = 0;
			try
			{
				BinarySearch(massiv, size, 11);
			}
			catch (std::invalid_argument)
			{
				check = true;
			}
			Assert::IsTrue(check);
			int* massiv_from_high_to_low = new int[10];
			for (int i = 0; i < 10; i++) { massiv[i] = 10 - i; }//10-9-8-7-6-5-4-3-2-1
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
			int* massiv = new int[size];
			for (int i = 0; i < size; i++) { massiv[i] = 9 - i; }//9-8-7-6-5-4-3-2-1-0
			QuickSort(massiv,0, size-1);
			Assert::AreEqual(massiv[0], 0);
			Assert::AreEqual(massiv[1], 1);
			Assert::AreEqual(massiv[2], 2);
			Assert::AreEqual(massiv[3], 3);
			Assert::AreEqual(massiv[4], 4);
			Assert::AreEqual(massiv[5], 5);
			Assert::AreEqual(massiv[6], 6);
			Assert::AreEqual(massiv[7], 7);
			Assert::AreEqual(massiv[8], 8);
			Assert::AreEqual(massiv[9], 9);
		}
		TEST_METHOD(Test_bubbleSort) 
		{
			int size = 10;
			int* massiv = new int[size];
			for (int i = 0; i < size; i++) { massiv[i] = i; }//0-1-2-3-4-5-6-7-8-9
			BubbleSort(massiv, size);
			Assert::AreEqual(massiv[0], 0);
			Assert::AreEqual(massiv[1], 1);
			Assert::AreEqual(massiv[2], 2);
			Assert::AreEqual(massiv[3], 3);
			Assert::AreEqual(massiv[4], 4);
			Assert::AreEqual(massiv[5], 5);
			Assert::AreEqual(massiv[6], 6);
			Assert::AreEqual(massiv[7], 7);
			Assert::AreEqual(massiv[8], 8);
			Assert::AreEqual(massiv[9], 9);
			for (int i = 0; i < size; i++) { massiv[i] = 9 - i; }
			BubbleSort(massiv, size);
			Assert::AreEqual(massiv[0], 0);
			Assert::AreEqual(massiv[1], 1);
			Assert::AreEqual(massiv[2], 2);
			Assert::AreEqual(massiv[3], 3);
			Assert::AreEqual(massiv[4], 4);
			Assert::AreEqual(massiv[5], 5);
			Assert::AreEqual(massiv[6], 6);
			Assert::AreEqual(massiv[7], 7);
			Assert::AreEqual(massiv[8], 8);
			Assert::AreEqual(massiv[9], 9);	
		}
		TEST_METHOD(Test_Bogosort)
		{
			srand(time(NULL));
			int size = 5;
			int* massiv = new int[size];
			for (int i = 0; i < size; i++) { massiv[i] = 4 - i; }//9-8-7-6-5-4-3-2-1-0
			BogoSort(massiv, size);
			Assert::AreEqual(massiv[0], 0);
			Assert::AreEqual(massiv[1], 1);
			Assert::AreEqual(massiv[2], 2);
			Assert::AreEqual(massiv[3], 3);
			Assert::AreEqual(massiv[4], 4);
		}
		
	};
}
