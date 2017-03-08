class CArbreBinaireEntier{
	//Attributs
	private:
		int iABEElement;
		CArbreBinaireEntier* pABEFilsGauche;
		CArbreBinaireEntier* pABEFilsDroit;
	//Constructeurs
	public:
		CArbreBinaireEntier();
		CArbreBinaireEntier(CArbreBinaireEntier &ABEObjet);
		CArbreBinaireEntier(int iValeur);
		CArbreBinaireEntier(int iValeur, CArbreBinaireEntier * ABEGauche, CArbreBinaireEntier * ABEDroit);
		~CArbreBinaireEntier();
	//Méthodes
		int ABELireElement() {return iABEElement;}
		void ABEModifierElement(int iValeur) {iABEElement=iValeur;}
		CArbreBinaireEntier* ABELireFDroit(){return pABEFilsDroit;}
		CArbreBinaireEntier* ABELireFGauche(){return pABEFilsGauche;}
		void ABEModifierFGauche(CArbreBinaireEntier * ABEGauche);
		void ABEModifierFDroit(CArbreBinaireEntier * ABEDroit);

	//Surcharges
		void operator+(CArbreBinaireEntier ABEA2);

};