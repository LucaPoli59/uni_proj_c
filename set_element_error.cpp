#include "set_element_error.h"


/**
* @brief costruttore di default chiamato dopo l'eccezione
*
* @param error_type: booleano che distingue tra errore di assenza (False), ed errore di presenza (True)
* @param message: messaggio da aggiungere
*/
set_element_error::set_element_error(const std::string message) : std::domain_error(message) {}


/**
* @brief costruttore secondario chiamato dopo l'eccezione
*
* @param error_type: booleano che distingue tra errore di assenza (False), ed errore di presenza (True)
* @param message: messaggio da aggiungere
*/
set_element_error::set_element_error(const bool error_type, const std::string message)
	: std::domain_error((error_type ? "errore, l'elemento e' gia' presente" : "errore, l'elemento non e' presente") + message) {}

