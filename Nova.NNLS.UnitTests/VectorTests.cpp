#include "stdafx.h"

#include "CppUnitTest.h"

#include "vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NNLSUnitTests
{
	TEST_CLASS(VectorTests)
	{
	public:
		TEST_METHOD(VectorDefaultConstruction)
		{
			nsNNLS::vector vec;
		}

		TEST_METHOD(VectorConstructionWithExternalData)
		{
			double externalData[] = { 1, 2, 3 };
			const size_t length = 3;
			
			nsNNLS::vector vec(3, externalData);
			double* actualData = vec.getData();

			Assert::AreEqual(length, vec.length());
			Assert::AreEqual(static_cast<double*>(externalData), actualData);
			for(int i = 0; i < length; i++)
			{
				Assert::AreEqual(externalData[i], actualData[i]);
			}
		}

	};
}
