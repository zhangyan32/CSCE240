#include <cstddef>
#include <iostream>

using namespace std;
class Shape{
public:
	void setWidth(int w){
		width = w;
	}
	void setHeight(int h){
		height = h;
	}
	int getArea(){
		cout << "cannot calculate area" << endl;
		return -1;
	};
	virtual void virtual_function(){
		cout << "this is the virtual function of Shape" << endl;
	}
	void non_virtual_function(){
		cout << "this is the non-virtual function of Shape" << endl;
	}
protected:
	int width;
	int height;
private:
	int position_x;
	int positive_y;
};

class Rectangle: public Shape{
public:
	int getArea(){
		return width * height;
	}
	void virtual_function(){
		cout << "this is the function of Rectangle" << endl;
	}
	void non_virtual_function(){
		cout << "this is the non-virtual function of Rectangle" << endl;
	}
};
