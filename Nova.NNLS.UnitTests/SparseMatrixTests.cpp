#include "stdafx.h"

#include "CppUnitTest.h"

#include "sparseMatrix.h"

namespace NNLSUnitTests
{
	TEST_CLASS(SparseMatrixTests)
	{
	public:
		TEST_METHOD(SparseMatrixDefaultConstruction)
		{
			nsNNLS::sparseMatrix mat;
		}
	};
}
