#ifndef __Class__Book__
#define __Class__Book__

#include "ChapterKTam.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book{
public:

	Book( string const& filename );
  
	void  add(      string const& word );
	bool  contains( string const& word );
  void  process();

  friend ostream&  operator<<( ostream& os, Book const& bk );

private:
  string           _filename;
	vector<Chapter>  _chapters;
	Chapter          _cumulative;
	int              _currentChapter;
};

#endif



//iterator sort for ABC sort
//if using pointers _word <= word, then use _word-> to move to next word.
//if using vectors then we can use pop.