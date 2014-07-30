#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "BookKTam.h"
#include "ChapterKTam.h"
#include "WordFreqKTam.h"
#include "WordListKTam.h"
using namespace std;

int main(){

	Book  bk( "/Users/Taminatuh/Desktop/Kenneth's Code/CWeb_1" );
  bk.process();
  cout << bk << endl;
  
  cout << "...done." << endl;

	return 0;

}