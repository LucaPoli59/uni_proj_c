#include "file_text_stats.h"

/*
 * costruttore di default
*/
File_text_stats::File_text_stats() : _nchars_total(0), _nchars_nospace(0), _nwords(0), _nparagraph(0), _nphrase(0){}

/*
 * costruttore copy constructor, inizializza la struct che contiene i dettagli del file
 *
 * other: strcut di input da cui vengono copiati i dati
*/
File_text_stats::File_text_stats(const File_text_stats& other) : _nchars_total(other._nchars_total), _nchars_nospace(other._nchars_nospace), _nwords(other._nwords), _nparagraph(other._nparagraph), _nphrase(other._nphrase){}

/*
 * costruttore secondario, inizializza la struct che contiene i dettagli del file
 *
 * nchars_total: numero di caratteri totali
 * nchars_nospace: numero di caratteri senza spazi
 * nwords: numero di parole
 * nparagraph: numero di paragrafi
 * nphrase: numero di frasi
*/
File_text_stats::File_text_stats(const unsigned int nchars_total, const unsigned int nchars_nospace, const unsigned int nwords, const unsigned int nparagraph, const unsigned int nphrase) :
    _nchars_total(nchars_total), _nchars_nospace(nchars_nospace), _nwords(nwords), _nparagraph(nparagraph), _nphrase(nphrase){}

/*
 * operatore di assegnamento
 *
 * other: strcut di input da cui vengono copiati i dati
*/
File_text_stats& File_text_stats::operator=(const File_text_stats& other)
{
    if(this != &other)
    {
        File_text_stats tmp(other);

        _nchars_total = tmp._nchars_total;
        _nchars_nospace = tmp._nchars_nospace;
        _nwords = tmp._nwords;
        _nparagraph = tmp._nparagraph;
        _nphrase = tmp._nphrase;
    }
    return *this;
}

/*
 * operatore di confornto
 *
 * other: strcut da confrontare
*/
bool File_text_stats::operator==(const File_text_stats& other)
{
    return(_nchars_nospace == other._nchars_nospace and _nchars_total == other._nchars_total and
           _nparagraph == other._nparagraph and _nphrase == other._nphrase and _nwords == other._nwords);
}
