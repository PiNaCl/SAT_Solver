/*
 * Backtracking2.cpp
 *
 *  Created on: 25 nov. 2018
 *      Author: Kitei
 */

#include "Solver.h"
#include "Utils.h"

using namespace std;

Solver::Solver(vector<vector<int>> formule, int nbVariable)
{
	this->formule = formule;
	this->nbVariable = nbVariable;
	sat= true;
	this->model = vector<int>(nbVariable, 0);
	this->look_var = vector<bool>(nbVariable, false);
}

Solver::~Solver()
{
}

/*
 * simplify : Fonction permettant la simplification d'une formule, par la valeur d'une des variables.
 * <param> vector <vector<int> formule : formule � simplifier
 * <param> int value : valeur de la variable actuelle.
 * <returns> : la formule simplifi�e
 */
vector<vector<int>> Solver::simplify(vector<vector<int>> formule, int value) {
	int actual_clause = 0;
	while (actual_clause < formule.size()) {
	int actual_literal = 0;

		while (actual_literal < formule[actual_clause].size()) {
			if (formule[actual_clause][actual_literal] == value) {
				formule.erase(formule.begin() + actual_clause);
				actual_clause-=1;
				break;
				formule.shrink_to_fit();
			} else if (formule[actual_clause][actual_literal] == -value) {
				formule[actual_clause].erase(formule[actual_clause].begin() + actual_literal);
				actual_literal-=1;
			}
			actual_literal+=1;
		}
		actual_clause+=1;
	}

	return formule;
}

/**
*Not working good.
*model assignement not really working , returns correctly the satisfiability of the problem using the exemples given, but the model returned is not good.
**/
vector<int> Solver::backtracking(vector<vector<int>> formule, int var){

	int i = 0;
	for (vector<int> clause : formule) {
		if(clause.empty()) {
			sat=false;
			return {};
		}
	}
	if(formule.empty()){
		model[abs(var)-1] = var;
		return {var};
	}
	int next_var = nextVar(formule, var);
	vector<int> a = backtracking(simplify(formule, next_var), next_var);
	if(a.empty())
		return backtracking(simplify(formule, -next_var), -next_var);
	else {
		model[abs(var)-1] = var;
		a.push_back(var);
		return a;
	}
}

/**
*Selection of the next var
* function that could be improved in multiple ways, atually just return a var that not have been already selected.
**/
int Solver::nextVar(const vector<vector<int>> &formule, int var){
	var = abs(var);
	this->look_var[var]=true;
	if(formule.empty()){
		return var;
	}
	for (int clause_it = 0; clause_it < formule.size(); clause_it++)
	{
		for (int literal_it = 0; literal_it < formule[clause_it].size(); literal_it++)
		{
			if (!look_var[literal_it])
			{
				return formule[clause_it][literal_it];
			}
		}
	}
	return var;
}


void Solver::solve () {
//	cout << "solving" <<endl;
	backtracking( formule,1 );
}

/**
 * Getter de la Classe
 */

const vector<vector<int>> &Solver::getFormule() const
{
	return formule;
}

const vector<bool> &Solver::getLookVar() const
{
	return look_var;
}

const vector<int> &Solver::getModel() const
{
	return model;
}

int Solver::getNbVariable() const
{
	return nbVariable;
}

bool Solver::isSat() const
{
	return sat;
}
