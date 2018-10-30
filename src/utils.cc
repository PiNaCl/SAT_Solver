/*
 * utils.cc
 *
 *  Created on: 30 oct. 2018
 *      Author: Napti
 */

#include <stdio.h>
#include <string.h>
#include "utils.h"



bool test_empty_clause(const vector<vector<int>>& formula) {
	for (vector<int> clause : formula) {
		if (clause.empty())
			return true;
	}
	return false;
}



pair<vector<vector<int>>,int> fileToVect(string name_file){
	ifstream infile(name_file);
	string line;

	vector<vector<int>> cnf;
	char * word;
	int numLines=0;
	int numCo=0;
	int nb_var;
	while (getline(infile, line)){
		char *copy = new char[line.length()+1];
		strcpy(copy, line.c_str());
		word = strtok(copy," \n");
		if (strcmp(word,"c")!=0){
			if (strcmp(word,"p")==0){
				while (word!=NULL){
					numCo++;
					if (numCo==3){
						nb_var = atoi(word);
					}
					if (numCo==4){
						cnf = vector<vector<int>>(atoi(word));
					}
					word = strtok(NULL," \n");
				}
			} else {
				while (word!=NULL){
					if (strcmp(word,"0")!=0){
						cnf[numLines].push_back(atoi(word));
					}
					word = strtok(NULL," \n");
				}
				numLines++;
			}
		} else {
			while (word!=NULL){
				cout << word;
				word=strtok(NULL," \n");
			}
		}
		free(word);
	}
	for (int i=0; i<cnf.size(); i++){
		for (int j=0; j<cnf[i].size(); j++){
			cout << cnf[i][j] << " ";
		}
		cout << endl;
	}
	return make_pair(cnf,nb_var);
}

void afficheFormule (vector<vector<int>> formule) {
	stringstream ss;
	ss << "Formule[" << endl;
	for(int clause=0; clause < formule.size(); clause++) {
		ss << "[";
		bool first = true;
		for (int x : formule[clause]) {
			if(first) {
				ss << x;
				first = false;
			}
			else
				ss << ", " << x;
		}
		ss << "]" << endl;
	}
	ss << "]"<< endl;
	cout << ss.str();
}
