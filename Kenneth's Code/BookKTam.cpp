#include "BookKTam.h"
#include "ChapterKTam.h"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

Book::Book( string const& filename )
: _filename( filename ), _chapters( 0 ), _currentChapter(1) {}

bool Book::contains( string const& word ){
	return _cumulative.contains( word );
}

void Book::add(string const& word) {
  Chapter&  current = _chapters[ _currentChapter - 1 ];
  if (current.contains( word ) || !_cumulative.contains( word ))  {
	  current.add( word );
  }
  _cumulative.add( word );
}

void  Book::process()  {
  string  filename = _filename + ".txt";
  
  ifstream  ifs;
  ifs.open( filename );
  if (!ifs)  {  cout << "could not open: " << filename << endl;  }
  
  Chapter  ch( _currentChapter );
  _chapters.push_back( ch );
  
  string atoz = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-0123456789'";
  size_t first;
  size_t last;
  string  word;
  while (ifs >> word)  {  
	  if (word.length() == 0 || word == "..."){ continue; }
	  first = word.find_first_of(atoz);
	  last = word.find_last_of(atoz);
	 // tolower(word);
	  string cleanWord = word.substr(first, last + 1);
	  add( cleanWord );  
	
  }
 
  ifs.close();
}




std::ostream&  operator<<( std::ostream& os, Book const& bk )  {
  for (std::vector<Chapter>::const_iterator  citer = bk._chapters.begin(); citer != bk._chapters.end(); citer++)  {
   // os << *citer << std::endl;
  }
  os << bk._cumulative << std::endl;
  return  os;
}
