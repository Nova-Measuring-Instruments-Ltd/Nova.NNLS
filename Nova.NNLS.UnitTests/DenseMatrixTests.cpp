#include "stdafx.h"

#include "CppUnitTest.h"

#include "denseMatrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NNLSUnitTests
{
	TEST_CLASS(DenseMatrixTests)
	{
	public:
		TEST_METHOD(DenseMatrixDefaultConstruction)
		{
			nsNNLS::denseMatrix mat;
		}

		TEST_METHOD(DenseMatrixConstructionWithExternalData)
		{
			double externalData[] = {
				1, 2,
				3, 4,
				5, 6
			};
			const size_t rows = 3;
			const size_t columns = 2;
			
			nsNNLS::denseMatrix matr(rows, columns, externalData);

			Assert::AreEqual(rows, matr.nrows());
			Assert::AreEqual(columns, matr.ncols());
			for(int i = 0; i < rows; i++)
				for(int j = 0; j < columns; j++)
				{
					double expected = externalData[i*columns + j];
					double actual = matr.get(i, j);
					Assert::AreEqual(expected, actual);
				}
		}
	};
}
