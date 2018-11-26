/*
 * utils.h
 *
 *  Created on: 30 oct. 2018
 *      Author: Napti
 */

#ifndef __UTILS_H
#define __UTILS_H


#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<vector>
#include <iterator>

using namespace std;

pair<vector<vector<int>>,int > fileToVect(string name_file);

void afficheFormule (vector<vector<int>> formule);

bool test_empty_clause(const vector<vector<int>>& formula);

vector<int> split(string &line);

#endif  // __READCNF_H




