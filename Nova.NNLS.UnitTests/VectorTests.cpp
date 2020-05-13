#include "stdafx.h"

#include "CppUnitTest.h"

#include "vector.h"

namespace NNLSUnitTests
{
	TEST_CLASS(VectorTests)
	{
	public:
		TEST_METHOD(VectorDefaultConstruction)
		{
			nsNNLS::vector vec;
		}
	};
}
