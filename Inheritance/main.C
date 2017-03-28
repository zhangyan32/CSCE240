#include <iostream>
#include "shape.h"
using namespace std;
int main(){
	Shape a;
	a.setHeight(10);
	a.setWidth(20);
	cout << a << endl;
	Rectangle b;
	b.setHeight(10);
	b.setWidth(20);
	cout << a.getArea() << endl;
	cout << b.getArea() << endl;
	cout << "-------------------------------------" << endl;
	Shape * c = new Shape();
	Rectangle * d = new Rectangle();
	Shape * e = new Rectangle();
	// Invalid conversion
	//Rectangle * f = new Shape();
	Rectangle * f = static_cast<Rectangle * > (c);
	c->setWidth(5);
	c->setHeight(3);
	cout << "difference in Virtual Function" << endl;
	cout << e << endl;
	e->virtual_function();
	e->non_virtual_function();
	cout << "------end--------" << endl;
	cout << c << endl;
	c->virtual_function();
	cout << f << endl;
	f->virtual_function();

}
