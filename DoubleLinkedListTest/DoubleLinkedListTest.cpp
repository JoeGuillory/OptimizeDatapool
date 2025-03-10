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
			Assert::IsNotNull(&list);
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0,list.last());
			Assert::AreEqual(0, list.getLength());
		}

		TEST_METHOD(InitializerListConstructor)
		{
			List<int> list = { 9,8,7,6,5 };
			Assert::IsNotNull(&list);
			Assert::AreEqual(5, list.getLength());
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

		TEST_METHOD(EqualOperator)
		{

			List<int> list = { 1,2,3 };
			Assert::IsNotNull(&list);
			Assert::AreEqual(3, list.getLength());
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, (*(list.begin()++)));
			Assert::AreEqual(3, list.last());
			Assert::AreEqual(3, list.getLength());

		}

		
		TEST_METHOD(EqualToOperatorCheck)
		{
			List<int> list1 = { 1,2,3 };
			List<int> list2 = { 1,2,3 };
			Assert::IsNotNull(&list1);
			Assert::AreEqual(3, list1.getLength());
			Assert::IsNotNull(&list2);
			Assert::AreEqual(3, list2.getLength());

			List<int> list3 = { 1,5,3 };
			List<int> list4 = { 1,2,3 };

			Assert::IsTrue(list1 == list2);
			Assert::IsFalse(list3 == list4);

		}

		TEST_METHOD(NotEqualToOperator)
		{
			List<int> list1 = { 2,5,3 };
			List<int> list2 = { 2,5,3 };

			
			List<int> list3 = { 2,2,3 };
			List<int> list4 = { 1,3,3 };
			
			Assert::IsFalse(list1 != list2);
			Assert::IsTrue(list3 != list4);
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

			list.popBack();
			Iterator<int> iter = list.begin();
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, *(iter)++);
			Assert::AreEqual(3, list.last());
			Assert::AreEqual(3, list.getLength());
		}
		TEST_METHOD(Insert)
		{
			List<int> list1;
			list1.insert(1, 0);
			Assert::AreEqual(1, list1.first());
			Assert::AreEqual(1, list1.getLength());

			List<int> list = { 1,2,4 };

			list.insert(3, 1);
			Iterator<int> iter = list.begin();

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
			List<int> list{};
			Assert::IsNotNull(&list);

			list.pushBack(1);
			list.pushBack(0);
			list.pushBack(1);
			list.pushBack(2);
			list.pushBack(1);
			list.pushBack(3);
			list.pushBack(1);
			Assert::AreEqual(7, list.getLength());
			Iterator<int> iter = list.begin();
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(1, *iter);


			int count = list.remove(1);
			Assert::AreEqual(4, count);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(*iter, list.first());
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::IsTrue(iter == nullptr);


			count = list.remove(5);
			Assert::AreEqual(0, count);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);


			list = List<int>();
			Assert::IsNotNull(&list);
			list.pushBack(3);
			list.pushBack(3);
			list.pushBack(3);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			list.remove(3);
			count = list.remove(3);
			Assert::AreEqual(0, list.getLength());
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
		}

		TEST_METHOD(First)
		{
			List<int> list = { 5,2,3 };

			Assert::AreEqual(5, list.first());
		}
		TEST_METHOD(Last)
		{
			List<int> list = { 2,4,9 };

			Assert::AreEqual(9, list.last());
		}

		TEST_METHOD(Destory)
		{
			List<int> list = { 6,914,64,4,5 };
			Assert::IsNotNull(&list);
			list.destroy();

			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
			Assert::AreEqual(0, list.getLength());

		}
		TEST_METHOD(GetLength)
		{
			List<int> list = { 1,5,7,9,6,8 };
			Assert::IsNotNull(&list);
			Assert::AreEqual(6, list.getLength());
		}
	};
}
