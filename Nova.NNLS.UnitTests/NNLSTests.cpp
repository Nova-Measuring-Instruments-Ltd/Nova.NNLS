#include "stdafx.h"

#include "nnls.h"

#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NNLSUnitTests
{
	TEST_CLASS(NNLSTests)
	{
	public:
		TEST_METHOD(NNLSDefaultConstruction)
		{
			nsNNLS::nnls solver;
		}
		
		TEST_METHOD(NNLSOptimize_DoesNotLeakMemory)
		{
			_CrtMemState state1;
			_CrtMemState state2;
			_CrtMemState state3;

			_CrtMemCheckpoint(&state1);

			const int rows = 4;
			const int cols = 2;

			double input_matrix[] = {
				0.0372, 0.2869,
				0.6861, 0.7071,
				0.6233, 0.6245,
				0.6344, 0.6170
			};

			double input_vector[] = {
				0.8587,
				0.1781,
				0.0747,
				0.8405
			};

			nsNNLS::denseMatrix A(rows, cols, input_matrix);
			nsNNLS::vector b(rows, input_vector);

			nsNNLS::nnls* solver = new nsNNLS::nnls(&A, &b, 1000);

			solver->optimize();

			delete solver;

			_CrtMemCheckpoint(&state2);

			int res = _CrtMemDifference(&state3, &state1, &state2);
			Assert::AreEqual(0, res, L"NNLS optimization leaks memory!");
		}
	};
}
