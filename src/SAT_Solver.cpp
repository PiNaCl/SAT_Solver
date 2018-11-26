/*
 * Main.cpp
 *
 *  Created on: 30 oct. 2018
 *      Author: Napti
 */
#include "Solver.h"
#include "Utils.h"

int main() {
	cout << "Entree";
	pair<vector<vector<int>>, int> couple = fileToVect("misc/example.cnf");
	vector<vector<int>> phi = couple.first;
	int nb_var = couple.second;
	Solver test = Solver(phi, nb_var);
	vector<vector<int>> test_value = vector<vector<int>>();
	vector<vector<int>> simplify_test = test.simplify(phi, 1);
}
/*	pair<vector<vector<int>>,int> couple = fileToVect("utils/example2.cnf");
		vector<vector<int>> phi = couple.first;
		int nb_var = couple.second;
		Solver test = Solver(phi, nb_var);
		test.backtracking()
		afficheFormule(phi);
		afficheFormule(phi_prime);
		vector<int> model = vector<int>(nb_var+1,0);
		bool sat = backtracking(phi,model);
		if (sat){
			cout << "SATISFIABLE" << endl;
			for (int i=1; i<model.size(); i++){
				if (model[i]!=0)
					cout << i*model[i] << " ";
				else
					cout << -i << "U "; //Temporary, U for undefined as it have not been tested for this model
			}
		} else {
			cout << "INSATISFAISABLE" << endl;
		}
		//TODO fonction select_var
	}*/
