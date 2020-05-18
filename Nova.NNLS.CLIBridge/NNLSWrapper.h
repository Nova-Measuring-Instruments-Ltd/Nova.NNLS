#pragma once

using namespace System::Runtime::InteropServices;

namespace Nova
{
	namespace NNLS
	{
		namespace NNLSCLIWrapper
		{

			public ref class NNLSWrapper
			{
			public:
				NNLSWrapper();
				virtual ~NNLSWrapper();
				!NNLSWrapper();

				void Solve(int rows, int cols,
					cli::array<double>^ matrix, 
					cli::array<double>^ vector,
					[Out] cli::array<double>^ solution);
			};
		}
	}
}

