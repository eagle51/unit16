#include <iostream>
#include <string>

using namespace std;
template <typename T,size_t N>
T *mybegin(const T (&a)[N])
{
	return &a[0];
}

template <typename T,size_t N>
T *myend(const T (&a)[N])
{
	return &a[0] + N;
}
//2016��7��1��19:21:02
//ʵ����