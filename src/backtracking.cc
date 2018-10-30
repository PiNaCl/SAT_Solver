#include "backtracking.h"
#include "utils.h"

vector<vector<int> > simplify(vector<vector<int>> formule, int value) {
	int neg_value = -value;
	int actual_clause = 0;
	int actual_literal = 0;
	while (actual_clause < formule.size()) {
		while (actual_literal < formule[actual_clause].size()) {
			if (formule[actual_clause][actual_literal] == value) {
				formule.erase(formule.begin() + actual_clause);
				actual_clause--;
				break;
			} else if (formule[actual_clause][actual_literal] == neg_value) {
				formule[actual_clause].erase(formule[actual_clause].begin() + actual_literal);
				actual_literal--;
			}
			actual_literal++;
		}
		actual_clause++;
	}
	return formule;
}


void affectValue(vector<int>& model, int index, int value) {
	if(model[index] ==0)
		model[index] = value; //is it really 1 ?
	else
		cout << "M";
}
/**
 * Backtracking method,
 *
 * input : a formula and a model
 *
 * output : true if the formula is satisfiable (the model is modified by adress)
 * false if the formula is unsatisfiable
 */
bool backtracking(vector<vector<int>> formule, vector<int>& model) {
	int index = abs(formule[0][0]); //Select the index of a value (which is the +-value) //TODO select value method
	vector<vector<int>> positive_simplify_formule = simplify(formule, index); //Phi'
	if (positive_simplify_formule.empty()) {
		affectValue(model, index, 1); //add the value to model, the formula is satisfied
		return true;

	} else {
		if (test_empty_clause(positive_simplify_formule)) {
			vector<vector<int>> negative_simplify_formule = simplify(formule, -index);
			if (negative_simplify_formule.empty()) {
				affectValue(model, index, -1);
				return true; //the actual model satisfy the formula
			} else {

				if (test_empty_clause(negative_simplify_formule)) {
					return false; //Unsatisfiable formula
				} else {
					affectValue(model, index, 1);
					return backtracking(negative_simplify_formule, model);
				}
			}
		} else {
			affectValue(model, index, -1);
			return backtracking(positive_simplify_formule, model);
		}
	}
}

