#include "pch.h"
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


	};
}
