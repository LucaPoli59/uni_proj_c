#include "voce.h"

voce::voce() : _nome(""), _cognome(""), _ntel(0) {}

voce::voce(const string cognome, const string nome, const unsigned int ntel) : _nome(nome), _cognome(cognome), _ntel(ntel) {}


ostream& operator<<(ostream& os, const voce& v)
{
	os << "nome: " << v._nome << "  |  cognome: " << v._cognome << "  |  telefono: " << v._ntel;

	return os;
}

