#include <iostream>
using namespace std;
#include "set.h"
#include "voce.h"



/** @brief struttura per confronto di due dati interi
 *
*/
struct int_cmp
{
	bool operator() (const int a, const int b) const
	{
		return(a == b);
	}
};

/** @brief struttura che definisce la proprieta' da indagare per interi
 *
*/
struct int_pred
{
	bool operator() (const int a) const
	{
		return(a > 0);
	}
};

/** @brief struttura per confronto di due dati stringhe
 *
*/
struct str_cmp
{
	bool operator() (const string a, const string b) const
	{
		return(a == b);
	}
};

/** @brief struttura che definisce la proprieta' da indagare per stringhe
 *
*/
struct str_pred
{
	bool operator() (const string a) const
	{
		return(a.length() >= 4);
	}
};

/** @brief struttura per confronto di due dati voce (rubrica)
 *
 * @nota due voci sono uguali se il numero di telefono corrisponde
*/
struct voce_cmp
{
	bool operator() (const voce a, const voce b) const
	{
		return(a._ntel == b._ntel);
	}
};

/** @brief struttura che definisce la proprieta' da indagare per voce (rubrica)
 *
 * @nota proprietà: lunghezza numero > 4 cifre
*/
struct voce_pred
{
	bool operator() (const voce a) const
	{
		return(a._ntel >= 999);//lunghezza numero > 4 cifre
	}
};

//tipo di default usato nel set, cambiabile con stringa, o voce
typedef int df_type;

//tipo alternativo usato (quello su cui si costruisce il set a partire dai suoi iteratori), cambiabile con stringa o voce
typedef double alt_type;

//funtore per uguaglianza di default usato, cambiabile con stringa o voce
typedef int_cmp df_cmp;

//funtore per predicato di default usato, cambiabile con stringa o voce
typedef int_pred df_pred;

//set di default usato
typedef set<df_type, df_cmp> df_set;

//nota: numero minimo di elementi diversi in ogni array = 4  (altrimenti va modificato il codice che accede direttamente a quegli elementi)

//interi
df_type value_main[] = { 10, -1, 1, 2, 33, 44, 12, 1 };
unsigned int value_main_len = 8;

unsigned int value_main_alt_len = 8;
alt_type value_main_alt[] = { 1.2, 3, 10.1, 42, -15, 1, 6, -12 };

df_type value_fond[] = {3, 16, 18, -15, 2, 5};
unsigned int value_fond_len = 6;


/* stringhe
df_type value_main[] = { "a", "peppe", "sale", "da'òmg", "casaa", "si", "no", "adfaf" };
unsigned int value_main_len = 8;

unsigned int value_main_alt_len = 8;
alt_type value_main_alt[] = { "c", "a", "b", "b", "f", "g", "h", "i" };

df_type value_fond[] = { "g", "e", "pino", "f", "nuci", "gsg" };
unsigned int value_fond_len = 6;
*/

/*voce
df_type value_main[] = { voce("a", "a", 1), voce("b", "b", 1000), voce("c", "c", 4), voce("d", "d", 56), voce("e", "e", 1222), voce("c", "c", 4) };
unsigned int value_main_len = 7;

unsigned int value_main_alt_len = 5;
alt_type value_main_alt[] = { voce("a", "a", 4), voce("b", "f", 1000), voce("c", "d", 56), voce("d", "e", 2), voce("e", "e", 11) };

df_type value_fond[] = { voce("a", "o", 33), voce("m", "b", 1), voce("l", "c", 4), voce("d", "j", 56), voce("e", "f", 12122) };
unsigned int value_fond_len = 5;
*/

/**@brief funzione di appoggio per rendere l'inseriemento più sintetico, applica la gestione standard dell'eccezione
 *
*/
void add_checked(df_set& s1, df_type& value)
{
	try
	{
		s1.add(value);
	}
	catch (const set_element_error& e)
	{
		cout << "----   " << e.what() << "   ----" << endl;
	}
}

/**@brief funzione di appoggio per rendere la cancellazione più sintetica, applica la gestione standard dell'eccezione
 *
*/
void remove_checked(df_set& s1, df_type& key)
{
	try
	{
		s1.remove(key);
	}
	catch (const set_element_error& e)
	{
		cout << "----   " << e.what() << "   ----" << endl;
	}
}

/**@brief funzione di appoggio per svolgere i test delle operazioni fondamentali su un set
 *
 *@param s: set da testare
*/
void test_Fondamentali(df_set s)
{
	cout << endl << "test fondamentali" << endl << endl;
	cout << "size: " << s.size() << endl;
	for (unsigned int i = 0; i < value_fond_len; i++)
	{
		add_checked(s, value_fond[i]);
	}
	
	cout << "standard dopo inserimenti: " << s << endl << "Size: " << s.size() << endl << endl;

	df_set sc(s);
	cout << "copy constructor: " << sc << endl << endl;

	df_set s_eq;
	s_eq = s;
	cout << "operatore assegnamento: " << s_eq << endl << endl;

	remove_checked(s, value_fond[0]);
	remove_checked(s, value_fond[0]);
	remove_checked(s, value_fond[2]);

	cout << "dopo rimozioni: " << s << endl << "Size: " << s.size() << endl << endl;
	cout << "copy constructor: " << sc << endl << "Size: " << sc.size() << endl << endl;
	cout << "operatore assegnamento: " << s_eq << endl << "Size: " << s_eq.size() << endl << endl;

	cout << "confronto fra set standard e copy: " << (s == sc) << endl;
	cout << "confronto fra set standard e assegnato: " << (s == s_eq) << endl;
	cout << "confronto fra set assegnato e copy: " << (s_eq == sc) << endl << endl;

	cout << "find val: " << value_fond[3] << endl;
	cout << "standard: " << s.find(value_fond[3]) << endl;
	cout << "copy: " << sc.find(value_fond[3]) << endl;
	cout << "assegnato: " << s_eq.find(value_fond[3]) << endl << endl;

	remove_checked(s, value_fond[3]);
	remove_checked(sc, value_fond[3]);
	remove_checked(s_eq, value_fond[3]);

	cout << "find val, dopo rimozione: " << value_fond[3] << endl;
	cout << "standard: " << s.find(value_fond[3]) << endl;
	cout << "copy: " << sc.find(value_fond[3]) << endl;
	cout << "assegnato: " << s_eq.find(value_fond[3]) << endl << endl;

	s.clear();
	cout << "dopo clear: " << s << endl << "Size: " << s.size() << endl << endl;
	cout << "copy constructor: " << sc << endl << endl;
	cout << "operatore assegnamento: " << s_eq << endl << endl;


	cout << "stampa copy con iteratore "<< endl << "{ ";
	df_set::const_iterator begin, end;
	unsigned int i;

	for (begin = sc.begin(), end = sc.end(), i = 0; begin != end; i++, ++begin)
	{
		cout << i << ": " << *begin << ", ";
	}
	cout << "}" << endl << endl;

	cout << "stampa copy con iteratore, nel senso inverso : " << endl << "{ ";
	--begin;
	for (; begin != end; i--, --begin)
	{
		cout << i << ": " << *begin << ", ";
	}
	cout << "}" << endl << endl;

	cout << endl << "fine test fondamentali" << endl << endl << endl << endl;
}

/**@brief funzione di appoggio per svolgere i test delle operazioni fondamentali dell'iteratore su un set
 *
 *@param s: set di cui testare l'iteratore
*/
void test_iteratori(df_set& s)
{
	cout << endl << endl << "test iteratori" << endl << endl;

	df_set::const_iterator begin, end;
	begin = s.begin();
	end = s.end();

	cout << "uso iteratore in end-state: testa + " << endl ;
	--begin;
	try
	{
		cout << (begin == end) << endl;
		//cout << *begin << endl;//genera eccezione come atteso
	}
	catch (...)
	{
		cout << "in end-state 1" << endl;
	}
	try
	{
		//--begin;//genera eccezione come atteso
		//++begin;
	}
	catch (...)
	{
		cout << "in end-state 2" << endl;
	}

	begin = s.begin();
	cout << *begin << endl;
	
	cout << "uso iteratore in end-state: coda + " << endl;
	while (begin != end)
	{
		++begin;
	}
	//cout << *begin << endl;//genera eccezione come atteso

	try
	{
		cout << (begin == end) << endl;
		//cout << *begin << endl;//genera eccezione come atteso
	}
	catch (...)
	{
		cout << "in end-state 1" << endl;
	}
	try
	{
		++begin;
		//++begin;//genera eccezione come atteso
	}
	catch (...)
	{
		cout << "in end-state 2" << endl;
	}

	
	cout << endl << endl << "fine test iteratori" << endl << endl;
}

/**@brief funzione di appoggio per svolgere i test delle operazioni generiche su due set
 *
 *@param s1: primo set da testare
 *@param s2: secondo set da testare
*/
void test_delle_generiche(df_set& s1, df_set& s2)
{
	df_pred pred;
	df_set* s1F, *s2F, *s1_c_s2, *s2_c_s1, *s1_int_s2;

	cout << endl << endl << endl << "inizio test delle generiche:" << endl << endl;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl << endl;


	s1F = filter_out(s1, pred);
	s2F = filter_out(s2, pred);
	cout << "s1F: " << *s1F << endl;
	cout << "s2F: " << *s2F << endl << endl;


	s1_c_s2 = s1 + s2;
	s2_c_s1 = s2 + s1;
	s1_int_s2 = s1 - s2;
	cout << "s1 concatenato a s2: " << *s1_c_s2 << endl;
	cout << "s2 concatenato a s1: " << *s2_c_s1 << endl;
	cout << "s1 intersezione s2: " << *s1_int_s2 << endl << endl;

	delete s1F;
	delete s2F;
	delete s1_c_s2;
	delete s2_c_s1;
	delete s1_int_s2;

	cout << endl << "fine test delle generiche:" << endl << endl;
}

int main()
{
	
	

	df_set sV;
	cout << "set vuoto: " << sV << endl << "Size: " << sV.size() << endl << endl;
	

	df_set sA(value_main, value_main_len);
	cout << "set array: " << sA << endl << "Size: " << sA.size() << endl << endl;
	
	df_set sIter(value_main_alt, (value_main_alt + value_main_alt_len));
	cout << "set iterator: " << sIter << endl << "Size: " << sIter.size() << endl << endl;
	

	cout << "test fondamentali su set array::" << endl << endl;
	test_Fondamentali(sA);

	cout << endl << endl << endl << endl << "test fondamentali su set iter::" << endl << endl;
	test_Fondamentali(sIter);

	cout << endl << endl << endl << endl << "test generiche su set array e iter::" << endl << endl;
	test_delle_generiche(sA, sIter);

	cout << "test iteratori su set array::" << endl << endl;
	test_iteratori(sA);

	return 0;
}
