#include "WordListKTam.h"

WordList::WordList( int length ) : _length( length ), _nullWord( nullString(), 0 ) {}

int   WordList::length() const        { return _length; }
void  WordList::length( int length )  {
  if (_length != length)  {
    _words.resize( 0 );
    _length = length;
    _nullWord = WordFreq( nullString(), 0 );
  }
}

size_t  WordList::size() const  {  return  _words.size();  }

string  WordList::nullString() const{
	std::string  s;
	for (size_t i = 0; i < _length; i++)  {
		if (i % 2 == 0)  { s += "+"; }
		else             { s += "_"; }
	}
	return    s;
}

void WordList::add( string const& word )  {
  if (_length != word.length()) { return; }
  vector<WordFreq>::iterator search = get(word);

  if (search == _words.end())  {  _words.push_back( WordFreq( word )); }
  else                         {  (*search++);  }

}

bool WordList::contains(string const& word ) const {
	return  word.length() == _length  &&  get(word) != _words.end();
}

WordFreq&  WordList::at(size_t index)  {
	if (index >= _words.size())  { 
		throw std::out_of_range("in WordList::at()");  
	}
	return  _words[index];
}

WordFreq const&  WordList::at(size_t index) const {
	if (index >= _words.size())  { return  _nullWord;   }
	return  _words[index];
}

vector<WordFreq>::iterator  WordList::get(std::string const& word) {
	return  std::find(_words.begin(), _words.end(), word );
}

vector<WordFreq>::const_iterator  WordList::get(std::string const& word) const{
	return  std::find( _words.begin(), _words.end(), word );
}

