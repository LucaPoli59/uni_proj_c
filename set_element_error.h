#ifndef SET_ELEMENT_ERROR_H
#define SET_ELEMENT_ERROR_H

#include <stdexcept>


/**
* @brief classe eccezione che viene usata quando l'elemento passato non e' valido rispetto al set
*/
class set_element_error : public std::domain_error
{
public:

	/**
	* @brief costruttore di default, chiamato dopo l'eccezione
	*
	* @param error_type: booleano che distingue tra errore di assenza (False), ed errore di presenza (True)
	* @param message: messaggio da aggiungere
	*/
	set_element_error(const std::string message);

	/**
	* @brief costruttore secondario, chiamato dopo l'eccezione
	* 
	* @param error_type: booleano che distingue tra errore di assenza (False), ed errore di presenza (True)
	* @param message: messaggio da aggiungere
	*/
	set_element_error(const bool error_type, const std::string message = "");
};

#endif // !SET_ELEMENT_ERROR_H

