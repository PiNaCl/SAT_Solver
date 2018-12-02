/*
 * utils.cc
 *
 *  Created on: 30 oct. 2018
 *      Author: Napti
 */

#include "Utils.h"


bool test_empty_clause(const vector<vector<int>>& formula) {
	for (vector<int> clause : formula) {
		if (clause.empty())
			return true;
	}
	return false;
}

//Read a dimac file, and create a double that contain  the forumla
pair<vector<vector<int>>,int> fileToVect(string nameFile){
	ifstream infile(nameFile);
	bool nextClause = true;
	if(!infile.is_open()){
		throw "Impossible d'ouvrir le fichier";
		
	}else{
		int nombreVariable, nbClauses;
		vector<vector<int>> formule;
		bool com_it = false;
		while(!com_it){
			string buff;
			getline(infile, buff);
			if(buff.find("c") == 0)
				continue;
			if(buff.find("p") == 0){
				vector<string> lineList;
				istringstream streamLine(buff);
				copy( istream_iterator<string>(streamLine), istream_iterator<string>(), back_inserter(lineList ));
				nombreVariable = stoi(lineList[2]);
				nbClauses = stoi(lineList[3]);
				com_it=true;
			}
		}
		for(int clause = 0 ; clause < nbClauses; clause++){
 			string buff;
			getline(infile, buff);
			formule.push_back(split(buff));
			formule[clause].pop_back();
		}
	//afficheFormule(formule);
		return make_pair(formule, nombreVariable);
	}

}
/**
 * split : fonction qui permet de split une chaîne de mot en un tableau de mots
 * string line : ligne que l'on souhaite séparer en plusieurs mots
 */

vector<int> split(string &line){
	vector<string> lineList;
	istringstream streamLine(line);
	copy( istream_iterator<string>(streamLine), istream_iterator<string>(), back_inserter(lineList ));
	vector<int> clause = vector<int>(lineList.size());
	for(int value = 0 ; value < lineList.size()-1; value++){
		clause[value]= stoi(lineList[value]);
	}
	return clause;
}


/**
*Function that prints a formula, would have been the formula.toString() method if we created the formula class
* used for debug
* param : the vector<vector<int>> that need to be printed
**/

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
		ss << "]" ;//<< endl;
	}
	ss << "]"<< endl;
	cout << ss.str();
}
