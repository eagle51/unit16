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
//2016年7月1日19:21:02
//实验室