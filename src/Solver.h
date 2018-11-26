/*
 * Backtracking2.h
 *
 *  Created on: 25 nov. 2018
 *      Author: Kitei
 */

#ifndef SOLVER_H_
#define SOLVER_H_

#include <vector>

using namespace std;

class Solver {
public:
	Solver(vector<vector<int>> formule, int nbVariable);
	virtual ~Solver();
	vector<vector<int>> simplify(vector<vector<int>>,int value);
	vector<int> backtracking(vector<vector<int>> formule, int var);
	void affectValue(int index, int value);
	int next_var(const vector<vector<int>>& formule, int var);
	const vector<vector<int> >& getFormule() const;
	const vector<bool>& getLookVar() const;
	const vector<int>& getModel() const;
	int getNbVariable() const;
	bool isSat() const;

private:
	vector<vector<int>> formule;
	vector<int> model;
	int nbVariable;
	bool sat;
	vector<bool> look_var;

};

#endif /* SOLVER_H_ */
