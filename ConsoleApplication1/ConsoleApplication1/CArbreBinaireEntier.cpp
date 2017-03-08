// ConsoleApplication1.cpp : définit le point d'entrée pour l'application console.
//

/******** Constructeurs ********/

#include "stdafx.h"
#include "CArbreBinaireEntier.h"
#include <iostream>

using namespace std;

CArbreBinaireEntier::CArbreBinaireEntier()
{
	iABEElement=0;
	pABEFilsDroit=0;
	pABEFilsGauche=0;
}

CArbreBinaireEntier::CArbreBinaireEntier(CArbreBinaireEntier &ABEObjet)
{
	this->iABEElement=ABEObjet.iABEElement;
	if(ABEObjet.pABEFilsDroit!=0)
		this->pABEFilsDroit= new CArbreBinaireEntier(*ABEObjet.pABEFilsDroit);
	else 
		this->pABEFilsDroit=0;

	if(ABEObjet.pABEFilsGauche!=0)
		this->pABEFilsGauche=new CArbreBinaireEntier(*ABEObjet.pABEFilsGauche);
	else 
		this->pABEFilsGauche=0;
}

CArbreBinaireEntier::CArbreBinaireEntier(int iValeur)
{
	this->iABEElement=iValeur;
}

CArbreBinaireEntier::CArbreBinaireEntier(int iValeur, CArbreBinaireEntier * ABEGauche, CArbreBinaireEntier * ABEDroit)
{
	this->iABEElement=iValeur;

	if(ABEGauche!=0)
		this->pABEFilsDroit=ABEGauche;
	else 
		this->pABEFilsDroit=0;

	if(ABEDroit!=0)
		this->pABEFilsGauche=ABEDroit;
	else 
		this->pABEFilsGauche=0;
}

CArbreBinaireEntier::~CArbreBinaireEntier()
{

}

/******** Méthodes ********/

void CArbreBinaireEntier::ABEModifierFGauche(CArbreBinaireEntier * ABEGauche)
{
	delete(this->pABEFilsGauche);
	this->pABEFilsGauche=ABEGauche;
}

void CArbreBinaireEntier::ABEModifierFDroit(CArbreBinaireEntier * ABEDroit)
{
	delete(this->pABEFilsDroit);
	this->pABEFilsDroit=ABEDroit;
}

/******** Surcharges ********/

void CArbreBinaireEntier::operator+(CArbreBinaireEntier ABEA2)
{
	if(this->pABEFilsGauche!=0 && this->pABEFilsDroit!=0)
		*(this->pABEFilsGauche)+*(this->pABEFilsDroit);
	else if (this->pABEFilsDroit!=0)
		this->pABEFilsGauche=this->pABEFilsDroit;

	this->pABEFilsDroit=&ABEA2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CArbreBinaireEntier * C1 = new CArbreBinaireEntier();
	CArbreBinaireEntier * C2 = new CArbreBinaireEntier(3);
	CArbreBinaireEntier * C3 = new CArbreBinaireEntier(*C2);
	CArbreBinaireEntier * C4 = new CArbreBinaireEntier(9,C3,C2);
	CArbreBinaireEntier * C5 = new CArbreBinaireEntier(8);
	CArbreBinaireEntier * C6 = new CArbreBinaireEntier(15);
	CArbreBinaireEntier * C7 = new CArbreBinaireEntier(10000,C5,C6);

	cout << "Element C1 : " << C1->ABELireElement() << endl;
	cout << "Element C2 : " << C2->ABELireElement() << endl;
	cout << "Element C3 : " << C3->ABELireElement() << endl;
	cout << "Element C4 : " << C4->ABELireElement() << endl;

	cout << "Fils Droit C1 : " << C1->ABELireFDroit() << endl;
	cout << "Fils Droit C2 : " << C2->ABELireFDroit() << endl;
	cout << "Fils Droit C3 : " << C3->ABELireFDroit() << endl;
	cout << "Fils Droit C4 : " << C4->ABELireFDroit() << endl;
	cout << "Element fdroit C4 : " << C4->ABELireFDroit()->ABELireElement() << endl;

	cout << "Element C1 avant : " << C1->ABELireElement() << endl;
	C1->ABEModifierElement(156);
	cout << "Element C1 apres : " << C1->ABELireElement() << endl;

	cout << "Fils Droit C2 avant: " << C2->ABELireFDroit() << endl;
	C2->ABEModifierFDroit(C3);
	cout << "Fils Droit C2 apres: " << C2->ABELireFDroit() << endl;

	cout << "Adresse C4 : " << C4 << endl;
	cout << "Fils droit C7 : " << C7->ABELireFDroit() << endl;
	cout << "Fils gauche C7 : " << C7->ABELireFGauche() << endl;
	cout << "Element fdroit C7 : " << C7->ABELireFDroit()->ABELireElement() << endl;
	cout << "Element fgauche C7 : " << C7->ABELireFGauche()->ABELireElement() << endl;

	*C7+*C4;

	cout << "***** C7 + C4*****" << endl;

	cout << "Fils droit C7 : " << C7->ABELireFDroit() << endl;
	cout << "Fils gauche C7 : " << C7->ABELireFGauche() << endl;
	cout << "Element fdroit C7 : " << C7->ABELireFDroit()->ABELireElement() << endl;
	cout << "Element fgauche C7 : " << C7->ABELireFGauche()->ABELireElement() << endl;

	return 0;
}

