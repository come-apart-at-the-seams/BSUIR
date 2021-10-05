// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "MathLibrary.h"

static double previous_;  // Previous value, if any
static unsigned long long current_;   // Current sequence value
static unsigned index_;


double x_i(double a, double b, int n, int i) {
	return a + i * (b - a) / n;
}
double h(double a, double b, int n) {
	return (b - a) / n;
}