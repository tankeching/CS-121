#ifndef __Picture_with_P_Node__Frame_Pic__
#define __Picture_with_P_Node__Frame_Pic__

#include <iostream>
using namespace std;
#include "P_Node.h"
#include "Picture.h"

class Frame_Pic : public P_Node {
private:
	friend Picture frame(const Picture& picture);

	Frame_Pic(const Picture& pic, char c = '+', char s = '|', char t = '-');
	Frame_Pic(const Picture& other);

	int height() const;
	int width() const;

	void display(ostream& os, int row, int wd) const;
	Picture reframe(char c, char s, char t);

public:
	void showDebug() const;
	Picture* getPic();

private:
	Picture _pic;
	char _corner;
	char _sideborder;
	char _topborder;
};

#endif