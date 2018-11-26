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
	this->sat= false;
	this->model = vector<int>(nbVariable, 0);
	this->look_var = vector<bool>(nbVariable, false);
}

Solver::~Solver() {
}



/*
 * simplify : Fonction permettant la simplification d'une formule, par la valeur d'une des variables.
 * <param> vector <vector<int> formule : formule à simplifier
 * <param> int value : valeur de la variable actuelle.
 * <returns> : la formule simplifiée
 */
vector<vector<int>> Solver::simplify(vector<vector<int>> formule, int value) {
	const int neg_value = -value;
	auto clause_it = formule.begin();
	while (clause_it != formule.end()) {
		auto lit_it = clause_it->begin();
		while (lit_it != clause_it->end()) {
			if (*lit_it == value) {
				clause_it = formule.erase(clause_it);
				break;
			} else if (*lit_it == neg_value) {
				lit_it = clause_it->erase(lit_it);
				++clause_it;
			}else{
				++clause_it;
				++lit_it;
			}
		}
	}
	return formule;
}



/*bool Solver::backtracking(vector<vector<int>> formule) {
	int index = formule[0][0]; //Select the index of a value (which is the +-value) //TODO select value method
	vector<vector<int>> positive_simplify_formule = simplify(formule, index); //Phi'
	if (positive_simplify_formule.empty()) {
		return true;

	} else {
		if (test_empty_clause(positive_simplify_formule)) {
			vector<vector<int>> negative_simplify_formule = simplify(formule, -index);
			if (negative_simplify_formule.empty()) {
				affectValue(index, 1);
				this->sat = true;
				return true; //the actual model satisfy the formula
			} else {

				if (test_empty_clause(negative_simplify_formule)) {
					affectValue(index, -1);
					this->sat = false;
					return false; //Unsatisfiable formula
				} else {
					affectValue(index, 1);
					return backtracking(negative_simplify_formule);
				}
			}
		} else {
			affectValue(index, -1);
			return backtracking(positive_simplify_formule);
		}
	}
}*/

vector<int> Solver::backtracking(vector<vector<int>> formule, int var){

	for (vector<int> clause : formule) {
		if(clause.empty())
			return {};
	}
	if(formule.empty()){
		return {var};
	}

	int nextVar = next_var(formule, var);

	vector<int> a = backtracking(simplify(formule, nextVar), nextVar);
	if(a.empty())
		return backtracking(simplify(formule, -nextVar), -nextVar);
	else {
		a.push_back(var);
		return a;
	}

}

int Solver::next_var(const vector<vector<int>> &formule, int var){
	this->look_var[var]=true;
	if(!formule.empty()){
		cout << "Formule vide";
		return var;
	}
	for(int clause_it = 0 ; clause_it < formule.size(); clause_it++){
		for(int literal_it = 0 ; literal_it < formule[clause_it].size() ; literal_it++){
			if(!look_var[literal_it]){
				return literal_it;
			}
		}
	}
	return var;
}

void Solver::affectValue(int index, int value) {
	if(this->model[index] ==0)
		this->model[index] = value; //is it really 1 ?
	else
		cout << "M";
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
