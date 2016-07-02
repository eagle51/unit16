#include <iostream>
#include <string>
#include "screen.h"
using namespace std;
int main()
{
	Screen<5, 3> myScreen;
	myScreen.display(cout);
	//将光标移动到指定位置，并设置其内容
	myScreen.move(4, 0).set('#');

	Screen<5, 5> nextScreen('X');
	nextScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	nextScreen.display(cout);
	cout << endl;

	const Screen<5, 3> blank;
	myScreen.set('#').display(cout);	//调用非const版本
	cout << endl;
	blank.display(cout);				//调用const版本
	cout << endl;

	myScreen.clear('Z').display(cout);
	cout << endl;

	myScreen.clear('Z').display(cout);cout << endl;
	myScreen.move(4, 0);
	myScreen.set('#');
	myScreen.display(cout).display(cout);
	cout << endl;

	//由于temp类型是Screen<5,3>而非Screen<5,3>&
	Screen<5, 3> temp = myScreen.move(4, 0);//则返回值被拷贝
	temp.set('#');							//改变temp就不会影响myScreen
	myScreen.display(cout);
	cout << endl;

	system("pause");
	return 0;
}