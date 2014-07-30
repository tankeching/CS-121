#ifndef __Picture_with_P_Node__String_Pic__
#define __Picture_with_P_Node__String_Pic__

#include <iostream>
using namespace std;
#include "P_Node.h"

class String_Pic : public P_Node {
private:
	friend class Picture;

	String_Pic(const char* const* pLines, int nLines);
	~String_Pic();

	int height() const;
	int width() const;
	void display(ostream& os, int x, int y) const;

	Picture reframe(char c, char s, char t);

public:
	void showDebug() const;
	Picture* getPic();

private:
	char** _data;
	int _size;
};

#endif