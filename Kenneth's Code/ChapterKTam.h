#ifndef __Class__Chapter__
#define __Class__Chapter__

#include "WordListKTam.h"
#include <iostream>
#include <string>
using namespace std;

class Chapter{
public:

	Chapter( int chapter = 1 );

	void  add(      string const& word );
  bool  contains( string const& word );
  
	friend ostream&  operator<<( ostream& os, Chapter const& ch );

private:
  enum  { NLISTS = 25 };

private:
	WordList _lists[NLISTS];
  int      _chapter;
};

#endif