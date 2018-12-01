/*
 * Main.cpp
 *
 *  Created on: 30 oct. 2018
 *      Author: Napti
 */
#include "Solver.h"
#include "Utils.h"

int main(int argc, char** argv) {

	for (int i =0; i < argc; i++) {
		cout << argv[i] <<endl;
	}
	cout << "Entree";
	string path;
	if(argc >= 2) {
		cout << argv[0]; 
		path = argv[1];
		cout << &path;
		cout << "fichier : " << path;
	}
	try  {
		pair<vector<vector<int>>, int> couple = fileToVect(path);
	
	vector<vector<int>> phi = couple.first;
	int nb_var = couple.second;
	Solver solver = Solver(phi, nb_var);
	solver.solve();
	vector<int> solution = solver.getModel();
	if (solution.empty()) {
		cout << "INSATISFAISABLE" << endl;
	} else {
		cout << "SATISFIABLE" << endl << "solution size = " << solution.size();
		for (int i=0; i<solution.size(); i++){
			if(solution[i]!=0)
				cout << (i+1) * solution[i] << " ";
			else
				cout << -1 * (i+1) << " " ;
		}
	}
} catch (exception &e) {
	cerr << e.what();
}

}