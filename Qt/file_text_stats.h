#ifndef FILE_TEXT_STATS_H
#define FILE_TEXT_STATS_H


struct File_text_stats
{

    unsigned int _nchars_total;
    unsigned int _nchars_nospace;
    unsigned int _nwords;
    unsigned int _nparagraph;
    unsigned int _nphrase;

    /*
     * costruttore di default
    */
    File_text_stats();

    /*
     * costruttore secondario, inizializza la struct che contiene i dettagli del file
     *
     * nchars_total: numero di caratteri totali
     * nchars_nospace: numero di caratteri senza spazi
     * nwords: numero di parole
     * nparagraph: numero di paragrafi
     * nphrase: numero di frasi
    */
    File_text_stats(const unsigned int nchars_total, const unsigned int nchars_nospace, const unsigned int nwords, const unsigned int nparagraph, const unsigned int nphrase);

    /*
     * costruttore copy constructor, inizializza la struct che contiene i dettagli del file
     *
     * other: strcut di input da cui vengono copiati i dati
    */
    File_text_stats(const File_text_stats& other);

    /*
     * operatore di assegnamento
     *
     * other: strcut di input da cui vengono copiati i dati
    */
    File_text_stats& operator=(const File_text_stats& other);

    /*
     * operatore di confornto
     *
     * other: strcut da confrontare
    */
    bool operator==(const File_text_stats& other);

    ~File_text_stats() {}
};

#endif // FILE_TEXT_STATS_H
