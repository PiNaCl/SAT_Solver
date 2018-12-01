/*
 * Backtracking2.cpp
 *
 *  Created on: 25 nov. 2018
 *      Author: Kitei
 */

#include "Solver.h"
#include "Utils.h"

using namespace std;

Solver::Solver(vector<vector<int>> formule, int nbVariable) {
	this->formule = formule;
	this->nbVariable = nbVariable;
	sat= false;
	this->model = vector<int>();
	this->look_var = vector<bool>(nbVariable, false);
}

Solver::~Solver() {
}

/*
 * simplify : Fonction permettant la simplification d'une formule, par la valeur d'une des variables.
 * <param> vector <vector<int> formule : formule � simplifier
 * <param> int value : valeur de la variable actuelle.
 * <returns> : la formule simplifi�e
 */

// vector<vector<int> > Solver::simplify(vector<vector<int>> formule, int value) {
// 	cout << "############   entrée dans Simplify ########" << endl << "formule avant simplification "<<endl;
// 	afficheFormule(formule);
// 	int actual_clause = 0;
// 	int actual_literal = 0;
// 	while (actual_clause < formule.size()) {
// 		while (actual_literal < formule[actual_clause].size()) {
// 			if (formule[actual_clause][actual_literal] == value) {
// 				formule.erase(formule.begin() + actual_clause);
// 				actual_clause--;
// 				break;
// 			} else if (formule[actual_clause][actual_literal] == -value) {
// 				formule[actual_clause].erase(formule[actual_clause].begin() + actual_literal);
// 				actual_literal--;
// 			}
// 			actual_literal++;
// 		}
// 		actual_clause++;
// 	}
// 	afficheFormule(formule);
// 	cout << " ####fin de simplify###";
// 	return formule;
//}
vector<vector<int>> Solver::simplify(vector<vector<int>> formule, int value) {
	cout << "############   entrée dans Simplify ########" << endl << "formule avant simplification "<<endl;
	afficheFormule(formule);
	vector<vector<int>>::iterator clause_it = formule.begin();
	while (clause_it != formule.end()) {
		vector<int>::iterator lit_it = clause_it->begin();
		while (lit_it != clause_it->end()) {
			if (value == *lit_it) {
				clause_it = formule.erase(clause_it);
				break;
			} else if (*lit_it == -value) {
				int size = clause_it -> size();
				clause_it->erase(lit_it);
			//	clause_it.prev();
				clause_it->resize(size-1);
				clause_it->shrink_to_fit();
				cout << "Valeur literal_it"<< *++lit_it << endl;
				++clause_it;
			}else{
				++clause_it;
				++lit_it;
				if (clause_it == formule.end())
					break;
			}
		}
	}

	afficheFormule(formule);
	cout << " ####fin de simplify###";
	return formule;
}

vector<int> Solver::backtracking(vector<vector<int>> formule, int var){
	cout << "actual_model [";
	for (auto i : model) {
		cout << i << ", ";
	}
	cout << "]" << endl <<"--------------entrée dans le backtracking ---------------"<<endl;

	int i = 0;
	cout << "nombres de clause = " << formule.size()<<endl;
	for (vector<int> clause : formule) {
		if(clause.empty()) {
			return {};
		}
	}
	if(formule.empty()){
		cout << "la formule est vide on retourne "<< var <<endl;
		return {var};
	}
	int next_var = nextVar(formule, var);
	cout << "apres nextVar : " << next_var << endl;
	vector<int> back_simpl = backtracking(simplify(formule, next_var), next_var);
	if(back_simpl.empty())
		return backtracking(simplify(formule, -next_var), -next_var);
	else {
		back_simpl.push_back(var);
		return back_simpl;
	}

}

int Solver::nextVar(const vector<vector<int>> &formule, int var){
	cout << "~~~~~~~~~Choix de nouvelle variable~~~~~~~~~~~" <<endl;
	var = abs(var);
	this->look_var[var]=true;
	if(formule.empty()){
		cout << "Formule vide, on retourne : " << var;
		return var;
	}
	for(int clause_it = 0 ; clause_it < formule.size(); clause_it++){
		for(int literal_it = 0 ; literal_it < formule[clause_it].size() ; literal_it++){
			if(!look_var[literal_it]){
				return formule[clause_it][literal_it];
			}
		}
	}
	return var;
}

// void Solver::affectValue(int index, int value) {
// 	if(this->model[index] ==0)
// 		this->model[index] = value; //is it really 1 ?
// 	else
// 		cout << "M";
// }


void Solver::solve () {
	model = backtracking( formule,1 );
}

/**
 * Getter de la Classe
 */

const vector<vector<int> >& Solver::getFormule() const {
	return formule;
}

const vector<bool>& Solver::getLookVar() const {
	return look_var;
}

const vector<int>& Solver::getModel() const {
	return model;
}

int Solver::getNbVariable() const {
	return nbVariable;
}

bool Solver::isSat() const {
	return sat;
}
