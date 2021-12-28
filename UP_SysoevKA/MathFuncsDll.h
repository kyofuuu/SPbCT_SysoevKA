#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
// MathFuncsDll.h
#ifdef MATHFUNCSDLL_EXPORTS
#define MATHFUNCSDLL_API __declspec(dllexport) 
#else
#define MATHFUNCSDLL_API __declspec(dllimport) 
#endif

namespace MathFuncs
{
	// This class is exported from the MathFuncsDll.dll
	class MyMathFuncs
	{
	public:
		static MATHFUNCSDLL_API float clamp(float value, float min, float max);
		static MATHFUNCSDLL_API char* push(char* stack, int size, char a);
	};
}
