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




pair<vector<vector<int>>,int> fileToVect(string nameFile){
	cout << "Entre dans fileToVect" << endl;
	ifstream infile(nameFile);
	bool nextClause = true;
	if(!infile.is_open()){
		cout << "Impossible d'ouvrir le fichier";
		return {};
	}else{
		cout << "Entre dans le else" << endl;
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
				cout << "nb var : " << nombreVariable << endl;
				cout << "nb clause : " << nbClauses << endl;
				com_it=true;
			}
		}
		for(int clause = 0 ; clause < nbClauses; clause++){
 			string buff;
			getline(infile, buff);
			cout << buff;
			formule.push_back(split(buff));
		}
		cout << "Clause 0 : " <<formule[0][0] << " " << formule[0][1] << " " << endl;
		cout << "Clause 1 : " << formule[1][0] << " " << formule[1][1] << " " << formule[1][1] << endl;
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
	cout<<endl;
	return clause;
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
