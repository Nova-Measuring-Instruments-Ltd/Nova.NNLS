#include "stdafx.h"

#include "CppUnitTest.h"

#include "denseMatrix.h"

namespace NNLSUnitTests
{
	TEST_CLASS(DenseMatrixTests)
	{
	public:
		TEST_METHOD(DenseMatrixDefaultConstruction)
		{
			nsNNLS::denseMatrix mat;
		}
	};
}
