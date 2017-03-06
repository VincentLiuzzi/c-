#include "string.h"
#include "stdlib.h"

class CException
{
	private:
		unsigned int uiEXCValeur;
		char* cpEXCmessage;
	public:
		CException(); //Constructeur par d�faut
		CException(CException & objet); //de reocpie
		CException(unsigned  int uiValeur, char* cpMessage); // de confort
		~CException(); //Destructeur

		unsigned int EXCReadError(); //Accesseur lecture valeur eerreur
		char * EXCReadMessage(); // Accesseur lecture message d'erreur 
		void EXCwriteMessage(char* cpMessage); //Accesseur ecriture message
		void EXCwriteError(unsigned int uiValeur); // Accesseur �criture erreur

};