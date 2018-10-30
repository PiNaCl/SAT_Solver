#ifndef __BACKTRACKING_H
#define __BACKTRACKING_H

#include<iostream>
#include <sstream>
#include <string>
#include <fstream>
#include<vector>
#include "utils.h"

using namespace std;

vector<vector<int> > simplify(vector<vector<int>> formule, int actual_value);
bool backtracking(vector<vector<int> > formule, vector<int>& model);
	
#endif  // __BACKTRACKING_H


// Vecteur reponse
//vecteur
