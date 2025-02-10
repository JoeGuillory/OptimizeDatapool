#include "pch.h"
#include "CppUnitTest.h"
#include "../DoubleLinkedList/ObjectPool.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ObjectPoolTest
{
	TEST_CLASS(ObjectPoolTest)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			ObjectPool<int> pool = ObjectPool<int>(10);
			Assert::IsNotNull(&pool);
		}
		TEST_METHOD(CountActive)
		{
			ObjectPool<int> pool = ObjectPool<int>(10);
			Assert::IsNotNull(&pool);

			int* a = pool.Get();
			int* b = pool.Get();
			int* c = pool.Get();
			int* d = pool.Get();
			Assert::IsNotNull(a);
			Assert::IsNotNull(b);
			Assert::IsNotNull(c);
			Assert::IsNotNull(d);

			Assert::AreEqual(4, pool.CountActive());
			int* e = pool.Get();
			Assert::IsNotNull(e);
			Assert::AreEqual(5, pool.CountActive());
			pool.Clear();
			Assert::AreEqual(0, pool.CountActive());

		}

		TEST_METHOD(CountInActive)
		{

			ObjectPool<int> pool = ObjectPool<int>(10);
			Assert::IsNotNull(&pool);

			int* a = pool.Get();
			int* b = pool.Get();
			int* c = pool.Get();
			int* d = pool.Get();
			Assert::IsNotNull(a);
			Assert::IsNotNull(b);
			Assert::IsNotNull(c);
			Assert::IsNotNull(d);

			Assert::AreEqual(6, pool.CountInactive());
			int* e = pool.Get();
			Assert::IsNotNull(e);
			Assert::AreEqual(5, pool.CountInactive());
			pool.Clear();
			Assert::AreEqual(0, pool.CountInactive());
		}
		TEST_METHOD(CountAll)
		{
			ObjectPool<int> pool = ObjectPool<int>(10);
			Assert::IsNotNull(&pool);

			Assert::AreEqual(10, pool.CountAll());
			pool = ObjectPool<int>(1000);
			Assert::IsNotNull(&pool);
			Assert::AreEqual(1000, pool.CountAll());

		}
		TEST_METHOD(Get)
		{
			ObjectPool<int> pool = ObjectPool<int>(10);
			Assert::IsNotNull(&pool);

			int* x = pool.Get();
			Assert::IsNotNull(x);

			Assert::AreEqual(1,pool.CountActive());
			Assert::AreEqual(9, pool.CountInactive());
			Assert::AreEqual(10, pool.CountAll());

		}
		TEST_METHOD(Release)
		{
			ObjectPool<int> pool = ObjectPool<int>(10);
			Assert::IsNotNull(&pool);

			int* x = pool.Get();
			Assert::IsNotNull(x);

			pool.Release(x);
			

		}
	};
}
