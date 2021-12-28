#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <csignal>
#include <conio.h>
#include <cstdlib>
#include <string>

namespace Pipe 
{
    class Arithmetic
    {
    public:
        static BOOL FAR PASCAL PipesProc(LPSTR lpData);
    };
}
