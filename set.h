#ifndef SET_H
#define SET_H

#include "set_element_error.h"

#include<sstream>
using namespace std;

/**
* @brief classe che implementa un set, ovvero una struttura dove non sono ammessi duplicati
* accessibile in sola lettura, e modificabile tramite add e remove
* implementata tramite una lista
* 
* 
*/
template<typename T, typename Eql>
class set
{
public:
	typedef T value_type;
	typedef unsigned int size_type;

private:

	/**
	* @brief struct che realizza l'implementazione del nodo della lista
	*/
	struct node
	{
		node* _next; //puntatore al prossimo nodo
		node* _prev; //puntatore al prossimo nodo
		value_type _value; //dato contenuto dal nodo

		/**
		* @brief costruttore di default
		*/
		node() : _next(nullptr), _prev(nullptr) {}

		/**
		* @brief costruttore secondario, che inizializza il nodo con valore
		* 
		* @param val: valore da assegnare al contenuto del nodo
		*/
		node(const value_type &val) : _next(nullptr), _prev(nullptr), _value(val) {}

		/**
		* @brief costruttore secondario, che inizializza il nodo con valore e next
		*
		* @param next: puntatore al prossimo nodo
		* @param val: valore da assegnare al contenuto del nodo
		* 
		*/
		node(node* next, const value_type& val) : _next(next), _prev(nullptr),  _value(val) {}

		/**
		* @brief costruttore secondario, che inizializza il nodo con valore e next e prev
		*
		* @param next: puntatore al prossimo nodo
		* @param prev: puntatore al nodo precedent
		* @param val: valore da assegnare al contenuto del nodo
		*
		*/
		node(node* next, node* prev, const value_type& val) : _next(next), _prev(prev), _value(val) {}

		/**
		* @brief costruttore secondario, che inizializza il nodo con  next
		*
		* @param next: puntatore al prossimo nodo
		*/
		node(node* next) : _next(next), _prev(nullptr) {}

		/**
		* @brief costruttore secondario, che inizializza il nodo con  next
		*
		* @param prev: puntatore al nodo precedente
		* @param next: puntatore al prossimo nodo
		*/
		node(node* next, node* prev) : _next(next), _prev(prev) {}

		/**
		* @brief copy constructor
		*
		* @param other: nodo da copiare
		*/
		node(const node &other) : _next(other._next), _prev(other._prev), _value(other._value) {}


		/**
		* @brief operatore assegnamento = 
		*
		* @param other: nodo da copiare
		*/
		node& operator=(const node& other)
		{
			_value = other._value;
			_next = other._next;
			_prev = other._prev;

			return *this;
		}
		/**
		* @brief distruttore
		*/
		~node() {}
	};

	node* _head;
	node* _tail;
	size_type _size;

	Eql _equals;

public:

	/**
	* @brief costruttore di default
	*/
	set() : _size(0), _head(nullptr), _tail(nullptr) {}

	/**
	* @brief costruttore secondario, che crea il set a partire da un array generico
	* 
	* @param values: array di valori
	* @param size: dimensione dell'array
	* 
	* 
	* @note gli elementi duplicati vengono scartati
	*/
	set(value_type* values, size_type size) : _tail(nullptr), _size(0), _head(nullptr)
	{
		for (size_type i = 0; i < size; i++)
		{
			try
			{
				add(values[i]);
			}
			catch (const set_element_error&)
			{}
			catch (...)
			{
				clear();
				throw;
			}
		}
	}

	/**
	* @brief copy constructor
	*
	* @param other: set da cui copiare i dati
	*/
	set(const set& other) : _size(0), _head(nullptr), _tail(nullptr)
	{
		node* patt = other._head;
		try
		{
			while (patt != nullptr)
			{
				add(patt->_value);
				patt = patt->_next;

			}
		}
		catch (...)
		{
			clear();
			throw;
		}
	}

	/**
	* @brief costruttore secondario, che inizializza il set a partire da una coppia di iteratori su tipi Q
	*
	* @param begin: iteratore di inizio
	* @param end: iteratore di fine
	*
	*
	* @note gli elementi duplicati vengono scartati
	*/
	template<typename Iter>
	set(Iter begin, Iter end) : _size(0), _head(nullptr), _tail(nullptr)
	{
		while (begin != end)
		{
			try
			{
				add(static_cast<value_type>(*begin));
			}
			catch (const set_element_error&)
			{
			}
			catch (...)
			{
				clear();
				throw;
			}
			begin++;
		}
	}

	
	/**
	* @brief distruttore
	*/
	~set()
	{
		clear();
	}

	/**
	* @brief metodo che resetta il set
	*
	*/
	void clear()
	{
		node* patt = _tail;

		while (patt != nullptr)
		{
			node* tmp = patt;
			patt = patt->_prev;

			delete tmp;
		}

		_head = nullptr;
		_tail = nullptr;
		_size = 0;
	}

	/**
	* @brief metodo che restituisce se il set e' vuoto
	* 
	* @return True o False se il set e' vuoto
	*/
	bool empty() const
	{
		return (_size == 0);
	}

	/**
	* @brief metodo che restituisce la dimensione
	*
	* @return la size
	*/
	size_type size() const
	{
		return _size;
	}

	/**
	* @brief metodo che inserisce un elemento nel set, lancia un eccezione se e' gia' presente o se non e' possibile l'allocazione
	*
	* @param new_val: il nuovo valore da aggiungere
	* 
	* @exception std::bad_alloc per possibile errore di allocazione
	* @exception set_element_error per possibile errore di elemento gia' presente
	*/
	void add(const value_type& new_val)
	{
		if (search(new_val) != nullptr)//elemento gia' presente
		{
			throw set_element_error(true);
		}

		node* tmp = new node(new_val);

		tmp-> _next = nullptr;//inserimento in coda

		if (empty())//se e' vuota imposto l'indice di testa
		{
			_head = tmp;
		}
		else
		{
			_tail->_next = tmp;
		}
		
		tmp->_prev = _tail;
		_tail = tmp;

		_size++;
	}

	/**
	* @brief metodo che elimina un elemento dal set, lancia un eccezione se non e' presente
	*
	* @param new_val: il nuovo valore da aggiungere
	*
	* @throw set_element_error per possibile errore di elemento non presente
	*/
	void remove(const value_type& key)
	{
		node* key_node = search(key);
		if (key_node == nullptr)//elemento non presente
		{
			throw set_element_error(false);
		}

		if (key_node == _head and key_node == _tail)//singolo elemento
		{
			_head = nullptr;
			_tail = nullptr;
		}
		else
		{
			if (key_node == _head)//cancellazione in testa
			{
				key_node->_next->_prev = nullptr;
				_head = key_node->_next;
			}
			else
			{
				if (key_node == _tail)//cancellazione in coda
				{
					key_node->_prev->_next = nullptr;
					_tail = key_node->_prev;
				}
				else//cancellazione nel mezzo
				{
					key_node->_prev->_next = key_node->_next;
					key_node->_next->_prev = key_node->_prev;
				}
			}
		}

		delete key_node;
		_size--;
	}

	/**
	* @brief metodo che restituisce true o false se l'elemento e' gia' presente nel set
	*
	* @param key: il valore da cercare
	* @return booleano che indica se l'elemento e' presente
	*/
	bool find(const value_type key) const
	{
		return(search(key) != nullptr);
	}

	/**
	* @brief metodo che legge un elemento nel set
	*
	* @throw std::out_of_rangese si eccede la dimensione
	*/
	value_type operator[](const size_type index) const
	{
		if (index >= _size)
		{
			throw out_of_range("Index out of range (" + stringstream(index).str() + " >= " + stringstream(_size).str() + ")");
		}

		node* patt = _head;
		size_type i = 0;
		while (i < index)
		{
			patt = patt->_next;
			i++;
		}

		return patt->_value;
	}

	/**
	* @brief metodo che confronta due set
	*
	* @param other: l'altro set
	*
	* @return true se sono uguali, false altrimenti
	*/
	bool operator==(const set& other) const
	{
		if (_size != other._size)
		{
			return false;
		}

		node* patt = _head;
		bool uguali = true;

		while (patt != nullptr and uguali)
		{
			uguali = find(patt->_value);
			patt = patt->_next;

		}

		return uguali;
	}

	/**
	* @brief operatore assegnamento =
	*
	* @param other: set da copiare
	*/
	set& operator=(const set& other)
	{
		if (this != &other)
		{
			set tmp(other);

			swap(_head, tmp._head);
			swap(_tail, tmp._tail);
			swap(_size, tmp._size);
		}
		return *this;

	}



	/**
	* @brief metodo che effettua la stampa del set
	*
	* @param os: stream da modificare
	* @param s: set da stampare
	*
	* @return lo stream aggiunto dei dati del set
	*/
	friend ostream& operator<<(ostream& os, const set& s)
	{
		os << "{ ";
		node* patt = s._head;
	
		while (patt != nullptr)
		{
			os << patt->_value << ", ";
			patt = patt->_next;
			
		}
		os << "}" << endl;

		return os;
	}

private:
	/**
	* @brief metodo che restituisce il puntatore ad un elemento del set
	*
	* @param key: il valore da cercare
	* @return puntatore a nodo
	*
	*/
	node* search(const value_type key) const
	{
		node* patt = _head;
		bool trovato = false;

		while (patt != nullptr and !trovato)
		{
			if (_equals(patt->_value, key))
			{
				trovato = true;
			}
			else
			{
				patt = patt->_next;
			}
		}
		if (trovato)
		{
			return patt;
		}
		else
		{
			return nullptr;
		}
	}

public:

	class const_iterator {
		//	
	public:
		typedef bidirectional_iterator_tag     iterator_category;
		typedef ptrdiff_t                       difference_type;
		typedef const T* pointer;
		typedef const T& reference;


		const_iterator() : _pnode(nullptr), _backNode(nullptr) {}

		const_iterator(const const_iterator& other) : _pnode(other._pnode), _backNode(other._backNode) {}

		const_iterator& operator=(const const_iterator& other) {
			_pnode = other._pnode;
			_backNode = other._backNode;
			return *this;
		}

		~const_iterator() {}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const { return (_pnode->_value); }

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const { return &(_pnode->_value); }


		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
			const_iterator tmp(*this);
			
			if (_pnode != nullptr)//nel caso ci possiamo muovere ancora in avanti
			{
				_backNode = _pnode;
				_pnode = _pnode->_next;
			}
			else//nel caso siamo in end state
			{
				if (_backNode->_prev == nullptr)//siamo in testa
				{
					_pnode = _backNode;
					
				}
				_backNode = nullptr;//se siamo in coda non possiamo fare nulla, l'iteratore andra' in stato di errore finale

			}
			return tmp;
		}
	
		// Operatore di iterazione pre-incremento
		const_iterator& operator++() {
			if (_pnode != nullptr)//nel caso ci possiamo muovere ancora in avanti
			{
				_backNode = _pnode;
				_pnode = _pnode->_next;
			}
			else//nel caso siamo in end state
			{
				if (_backNode->_prev == nullptr)//siamo in testa
				{
					_pnode = _backNode;

				}
				_backNode = nullptr;//se siamo in coda non possiamo fare nulla, l'iteratore andra' in stato di errore finale

			}
			return *this;
		}

		// Operatore di iterazione post-decremento
		const_iterator operator--(int) {
			const_iterator tmp(*this);

			if (_pnode != nullptr)//nel caso ci possiamo muovere ancora in dietro
			{
				_backNode = _pnode;
				_pnode = _pnode->_prev;
			}
			else//nel caso siamo in end state
			{
				if (_backNode->_next == nullptr)//siamo in coda
				{
					_pnode = _backNode;
				}
				_backNode = nullptr;//se siamo in testa non possiamo fare nulla, l'iteratore andra' in stato di errore finale

			}
			return tmp;
		}

		// Operatore di iterazione pre-decremento
		const_iterator& operator--() {
			if (_pnode != nullptr)//nel caso ci possiamo muovere ancora in dietro
			{
				_backNode = _pnode;
				_pnode = _pnode->_prev;
			}
			else//nel caso siamo in end state
			{
				if (_backNode->_next == nullptr)//siamo in coda
				{
					_pnode = _backNode;
				}
				_backNode = nullptr;//se siamo in testa non possiamo fare nulla, l'iteratore andra' in stato di errore finale

			}
			return *this;
		}

		// Uguaglianza
		bool operator==(const const_iterator& other) const {
			return (_pnode == other._pnode);
		}

		// Diversita'
		bool operator!=(const const_iterator& other) const {
			return (_pnode != other._pnode);
		}

	private:

		friend class set;
		
		const node* _pnode;//puntatore al nodo corrente

		/**@brief puntatore al nodo precedentemente letto
		* 
		* utilizzato per uscire dalla end-state con l'operazione contraria 
		* a quella con cui ci si e' entrati
		* 
		* end-state: situazione in cui l'iteratore e' in coda o in tail
		*/
		const node* _backNode;


		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		const_iterator(const node* pnode, const node* backNode) : _pnode(pnode), _backNode(backNode)
		{}

	};

	// Ritorna l'iteratore all'inizio della sequenza dati
	const_iterator begin() const {
		return const_iterator(_head, nullptr);
	}

	// Ritorna l'iteratore alla fine della sequenza dati
	const_iterator end() const {
		return const_iterator(nullptr, nullptr);
	}

};


/**
* @brief metodo globale generico che applica un predicato ad ogni elemento del set, restituendo il set con i valori che lo soddisfano
*
* @param s: set su cui applicare il predicato
* @param pred: predicato
*
* @return pointer al set con i valori che soddisfano il predicato
*/

template<typename T, typename Eql, typename Pred>
set<T, Eql>* filter_out(const set<T, Eql>& s, Pred pred)
{
	typename set<T, Eql>::const_iterator begin, end;
	set<T, Eql>* s_out = new set<T, Eql>();

	try
	{
		for (begin = s.begin(), end = s.end();  begin != end; ++begin)
		{
			if (pred(*begin))
			{
				s_out->add(*begin);
			}
		}
	}
	catch (...)
	{
		delete s_out;
		throw;
	}

	return s_out;
}



/**
* @brief metodo globale generico per la concatenzione di due set
*
* @param s1: primo set di input
* @param s2: secondo set di input
*
* @return pointer al set con i valori concatenati
*/
template<typename T, typename Eql>
set<T, Eql>* operator+(const set<T, Eql>& s1, const set<T, Eql>& s2)
{
	typename set<T, Eql>::const_iterator begin, end;
	set<T, Eql>* s_out = new set<T, Eql>(s1);


	for (begin = s2.begin(), end = s2.end(); begin != end; ++begin)
	{
		try
		{
			s_out->add(*begin);
		}
		catch (const set_element_error&) {}
		catch (...)
		{
			delete s_out;
			throw;
		}

	}

	return s_out;
}


/**
* @brief metodo globale generico per l'intersezione di due set
*
* @param s1: primo set di input
* @param s2: secondo set di input
*
* @return pointer al set con l'intersezione
*/
template<typename T, typename Eql>
set<T, Eql>* operator-(const set<T, Eql>& s1, const set<T, Eql>& s2)
{
	typename set<T, Eql>::const_iterator begin, end;
	set<T, Eql>* s_out = new set<T, Eql>();

	try
	{
		for (begin = s1.begin(), end = s1.end(); begin != end; ++begin)
		{
			if (s2.find(*begin))
			{
				s_out->add(*begin);
			}
		}
	}
	catch (...)
	{
		delete s_out;
		throw;
	}
	return s_out;
}





#endif // !SET_H
