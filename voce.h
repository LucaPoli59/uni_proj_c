#ifndef VOCE
#define VOCE

#include <ostream>

using namespace std;

/**
* @file voce.h
* 
* @brief file che gestisce e contiene la struct voce
* 
*/


/**
* @brief struct che rappresenta la singola voce
*/

struct voce {

	string _cognome, _nome;
	unsigned int _ntel;

	voce();
	voce(const string cognome, const string nome, const unsigned int ntel);
};

	ostream& operator<<(ostream& os, const voce& v);


#endif //!VOCE