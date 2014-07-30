#ifndef __Word__List__
#define __Word__List__

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "WordFreqKTam.h"


class WordList{
public:
  WordList( int length = 0 );
  
	int     length() const;
	void    length( int len );		// warning; throws away all words in the list if _length != length
  size_t  size() const;
	string  nullString() const;

	void add(      string const& word );
	bool contains( string const& word ) const;

	void display();

	WordFreq&        at( size_t index );
	WordFreq const&  at( size_t index ) const;

	std::vector<WordFreq>::iterator        get( std::string const& word );
	std::vector<WordFreq>::const_iterator  get( std::string const& word ) const;

private:
	vector<WordFreq>  _words;
	int               _length;      // length of every word in this list
	WordFreq          _nullWord;
};

#endif