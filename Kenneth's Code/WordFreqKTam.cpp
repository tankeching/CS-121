#include "WordFreqKTam.h"

WordFreq::WordFreq( string const& word, int freq ) : _word(word), _freq( freq )  {}

string WordFreq::getWord()  { return _word; }
int    WordFreq::getFreq()  { return _freq; }

bool WordFreq::operator==(WordFreq const& other) const{
	return _word == other._word;
}



