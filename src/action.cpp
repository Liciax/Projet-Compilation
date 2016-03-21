#include "action.hpp"

using namespace std;

type_pile pile;
// type_dico dicoT, dicoNT;

// int recherche(type_dico & dico, std::string symb) {
// 	unsigned int i;
// 	for (i = 0; i < dico.size(); ++i) {
// 		if(dico[i] == code) {
// 			return code;
// 		}
// 	}
// 	dico.push_back(code);
// 	return code;
// }

void empiler(type_pile & pile, Node * p) {
	pile.push(p);
}


Node * depiler(type_pile & pile) {
	Node * p = new Node();
	p = pile.top();
	pile.pop();
	return p;
}

void g0_action(Atom *pa, int scanAction, std::map<int, Node*>& G0, type_tableSymbole & tabSymb, type_pile & pile, std::string symbole) {
	Node * t1 = new Node();
	Node * t2 = new Node();

	switch (pa->action) {
		case 1: {
			cout << "1 " << endl;
			t1 = depiler(pile);
			t2 = depiler(pile);
			Atom* p = (Atom*)t2;
			G0[(p->code)] = t1;
			ImprimeArbre(G0[(p->code)],0);
		}
			break;
		case 2: {
			cout << "2 " << endl;
			//recherche renvoie le code du terminal si elle le trouve
			// sinon le stocke dans dicot ou dicont et le renvoie
			empiler(pile, GenAtom(/*recherche(dicoNT, pa->code)*/ recherche_symb_ac_add(symbole,tabSymb), scanAction, pa->type));
		}
			break;
		case 3: {
			cout << "3 " << endl;
			t1 = depiler(pile);
			t2 = depiler(pile);
			empiler(pile, GenUnion(t2, t1));
		}
			break;
		case 4: {
			cout << "4 " << endl;
			t1 = depiler(pile);
			t2 = depiler(pile);
			empiler(pile, GenConc(t2, t1));
		}
			break;
		case 5: {
			cout << "5 " << endl;
			if (pa->type == TERMINAL) {
				empiler(pile, GenAtom(recherche_symb_ac_add(symbole,tabSymb), pa->action, TERMINAL));
			} else {
				empiler(pile, GenAtom(recherche_symb_ac_add(symbole,tabSymb), scanAction, NONTERMINAL));
			}
		}
			break;
		case 6: {

			cout << "7 " << endl;
			t1 = depiler(pile);
			empiler(pile, GenStar(t1));
		}
			break;
		case 7: {

			cout << "8 " << endl;
			t1 = depiler(pile);
			empiler(pile, GenUn(t1));
		}
			break;
	}
}