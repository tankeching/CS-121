#include "ChapterKTam.h"

#include <iostream>
#include <string>
using namespace std;

Chapter::Chapter( int chapter ) : _chapter( chapter )  {
  for (int i = 0; i < NLISTS; i++)  {  _lists[ i ].length( i );  }
}

void Chapter::add( string const& word  ){
	_lists[ word.length() ].add(word);
}

bool Chapter::contains( string const& word )  {
	return  _lists[word.length()].contains(word);
}



ostream&  operator<< ( ostream& os, Chapter const& ch )  {
	size_t  max_row    = 0;
	int     max_column = 8;                   // 12 or whatever
	
  for (int i = 1; i < max_column; i++)  {     // find the max # of rows for this chapter
    WordList const&  wl   = ch._lists[ i ];
    size_t           size = wl.size();
    if (max_row < size)  {  max_row = size;  }
  }
  
	for (int row = 0; row < max_row; row++) {
		for (int column = 1; column < max_column; column++) {   // no col 1 == 0 length words
      WordList const&  wl = ch._lists[ column ];
      WordFreq const&  wf = wl.at( row );
      os << wf << " "  << " | ";
    }
		os << endl;
	}

	cout << endl << endl;
	max_column = 13;

	for (int row = 0; row < max_row; row++) {
		for (int column = 8; column < max_column; column++) {   // no col 1 == 0 length words
			WordList const&  wl = ch._lists[column];
			WordFreq const&  wf = wl.at(row);
			os << wf << " " << " | ";
		}
		os << endl;
	}
	for (int row = 9; row < max_row; row++) {
		for (int column = max_column; column < max_column; column++) {   // no col 1 == 0 length words
			WordList const&  wl = ch._lists[column];
			WordFreq const&  wf = wl.at(row);
			os << wf << " " << " | ";
		}
		os << endl;
	}
  
	return   os;
}