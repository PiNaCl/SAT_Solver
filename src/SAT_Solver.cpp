/*
 * Main.cpp
 *
 *  Created on: 30 oct. 2018
 *      Author: Napti
 */
#include "Solver.h"
#include "Utils.h"

int main(int argc, char** argv) {
	string path;
	if(argc >= 2) {
		path = argv[1];
	} else {
		cout << "usage : sat $pathToDimacFile$, one argument required."<<endl;
		return -1;
	}
	try  {
		//Read the dimac file
		pair<vector<vector<int>>, int> couple = fileToVect(path);
		vector<vector<int>> phi = couple.first;
		int nb_var = couple.second;

		// Create the solver with formula and the number of variable for solving
		Solver solver = Solver(phi, nb_var);

		//Run the solver
		solver.solve();

		//Get the solution
		vector<int> solution = solver.getModel();

		//print it
		if (solution.empty() && !solver.isSat()) {
			cout << "UNSATISFIABLE" << endl;
		} else {
			cout << "SATISFIABLE" << endl << "solution size = " << solution.size()<<endl;
			for (int i=0; i<solution.size(); i++){
				// If there is no value assigned to solution[i], then the formula is satisfied without them
				solution[i] ==0 ? cout << -i-1 << " " : cout << solution[i] << " ";
			}
		}
	} catch (exception &e) {
		cerr << e.what();
	}
}