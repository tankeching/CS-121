#ifndef __Word__Frequency__
#define __Word__Frequency__

#include <iostream>
#include <string>
using namespace std;

class WordFreq{
public:

	WordFreq( string const& word = "", int freq = 1 );

	string  getWord();
	int     getFreq();

	WordFreq& operator++() {
		_freq++;
		return  *this;
	}

	WordFreq& operator=(const WordFreq& other){
		_word = other._word;
		_freq = other._freq;
		return  *this;
	}

	bool operator==(WordFreq const& other) const;
	friend ostream& operator<<( ostream& os, WordFreq const& wf )  {
		if (wf._freq <= 1)  { return os << wf._word; }
		else                { return os << wf._word << "-" << wf._freq; }
	}

private:
	string  _word;
	int     _freq;
	
};

#endif