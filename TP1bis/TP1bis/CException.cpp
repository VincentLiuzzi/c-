#include "CException.h"

CException::CException()
{
	cpEXCmessage=0;
}

/*CException::CException(CException &objet)
{
	this.uiEXCValeur = objet.uiEXCValeur;
}*/

CException::CException(unsigned int uiValeur, char* uiMessage)
{
	uiEXCValeur = uiValeur;
}

CException::~CException()
{
	delete cpEXCmessage;
}

unsigned int CException::EXCReadError()
{
	return uiEXCValeur;
}

char * CException::EXCReadMessage()
{
	return cpEXCmessage;
}

void CException::EXCwriteMessage(char* cpMessage)
{
	cpEXCmessage= _strdup(cpMessage);
}

void CException::EXCwriteError(unsigned int uiValeur)
{
	uiEXCValeur=uiValeur;
}
