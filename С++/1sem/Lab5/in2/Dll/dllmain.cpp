// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "dll.h"
#include <math.h>

bool fun(float* arr, int m, int n) {
	if (n == m) return sin(arr[m]) > 0;
	return (fun(arr, m, (m + n) / 2)) | (fun(arr, (n + m) / 2 + 1, n));
}
