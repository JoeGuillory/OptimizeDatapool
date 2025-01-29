#include "pch.h"
#include "CppUnitTest.h"
#include "List.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DoubleLinkedListTest
{
	TEST_CLASS(DoubleLinkedListTest)
	{
	public:
		
		TEST_METHOD(DefualtConstructor)
		{
			List<int> list;
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0,list.last());
			Assert::AreEqual(0, list.getLength());
		}

		TEST_METHOD(InitializerListConstructor)
		{
			List<int> list = { 9,8,7,6,5 };

			Iterator<int> iter = list.begin();
			Assert::AreEqual(9, *iter);
			iter++;
			Assert::AreEqual(8, *iter);
			iter++;
			Assert::AreEqual(7, *iter);
			iter++;
			Assert::AreEqual(6, *iter);
			iter++;
			Assert::AreEqual(5, *iter);
			Assert::AreEqual(5, list.getLength());
		}

		TEST_METHOD(PushFront)
		{
			List<int> list;
			list.pushFront(1);

			Assert::AreEqual(1, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(1, list.getLength());

			list.pushFront(2);

			Assert::AreEqual(2, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(2, list.getLength());

			list.pushFront(3);

			Assert::AreEqual(3, list.first());
			Assert::AreEqual(2, *(list.begin()++));
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(3, list.getLength());

		}

		TEST_METHOD(PushBack)
		{
			List<int> list;
			list.pushBack(1);

			Assert::AreEqual(1, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(1, list.getLength());

			list.pushBack(2);

			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, list.last());
			Assert::AreEqual(2, list.getLength());

			list.pushBack(3);

			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, *(list.begin()++));
			Assert::AreEqual(3, list.last());
			Assert::AreEqual(3, list.getLength());
		}

		TEST_METHOD(PopFront)
		{
			List<int> list = { 1 };
			list.popFront();
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.getLength());

			list.pushFront(1);
			list.pushBack(2);
			list.pushBack(3);
			list.pushBack(4);
			
			list.popFront();
			Iterator<int> iter = list.begin();
			Assert::AreEqual(2, list.first());
			Assert::AreEqual(3, *iter++);
			Assert::AreEqual(4, list.last());
			Assert::AreEqual(3, list.getLength());

		}
		TEST_METHOD(PopBack)
		{
			List<int> list = { 1 };
			list.popBack();
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.getLength());

			list.pushFront(1);
			list.pushBack(2);
			list.pushBack(3);
			list.pushBack(4);

			list.popFront();
			Iterator<int> iter = list.begin();
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, *iter++);
			Assert::AreEqual(3, list.last());
			Assert::AreEqual(3, list.getLength());
		}
		TEST_METHOD(Insert)
		{
			List<int> list1;
			list1.insert(1, 0);
			Assert::AreEqual(1, list1.first());
			Assert::AreEqual(0, list1.getLength());

			List<int> list = { 1,2,4 };

			Iterator<int> iter = list.begin();
			list.insert(3, 1);

			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(4, *iter);
			Assert::AreEqual(4, list.getLength());

		}
		TEST_METHOD(Remove)
		{
			List<int> list = { 1,2,3 };

			list.remove(2);

			Assert::AreEqual(1, list.first());
			Assert::AreEqual(3, list.last());
			Assert::AreEqual(2, list.getLength());
		}
	};
}
