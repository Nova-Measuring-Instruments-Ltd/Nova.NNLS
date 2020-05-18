#include "stdafx.h"
#include "NNLSWrapper.h"

#include "nnls.h"
#include <vector>

namespace Nova
{
	namespace NNLS
	{
		namespace NNLSCLIWrapper
		{
			NNLSWrapper::NNLSWrapper()
			{				
			}

			NNLSWrapper::~NNLSWrapper()
			{
				this->!NNLSWrapper();
			}

			NNLSWrapper::!NNLSWrapper()
			{
			}

			void NNLSWrapper::Solve(int rows, int cols,
				cli::array<double>^ matrix,
				cli::array<double>^ vector,
				[Out] cli::array<double>^ solution)
			{
				pin_ptr<double> ptrInputMatrix = &matrix[0];
				pin_ptr<double> ptrInputVector = &vector[0];
				pin_ptr<double> ptrSolution = &solution[0];

				nsNNLS::denseMatrix A(rows, cols, ptrInputMatrix);
				nsNNLS::vector b(rows, ptrInputVector);
				nsNNLS::vector result(cols, ptrSolution);

				const int MAX_ITERATIONS = 1000; //arbitrary large number, maybe needs adjustment				

				try
				{
					nsNNLS::nnls solver(&A, &b, MAX_ITERATIONS);
					int retval = solver.optimize();
					if (retval == 0)
					{
						nsNNLS::vector* x = solver.getSolution();
						result.copy(x);
					}
					else
					{
						throw std::logic_error("NNLS solver failed");
					}
				}
				catch (const std::exception& ex)
				{
					std::string s(ex.what());
					System::String^ message = gcnew System::String(s.c_str());
					throw gcnew System::Exception(message);
				}
			}
		}
	}
}
