#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Automata 
{
	set<char> Q, S, F;      // a finite set of states  Q. A finite set of input symbols Sigma (grammar), a set of final states F
	char q0;                // initial state   it's char because we can call them p,q,r,s,t etc or just numbers, or q0,q1....
	struct transition {
		char InitialState, word, DestinationState;   
	};
	vector<transition> delta;   

public:
	friend istream& operator>>(istream& file, Automata& Automat);
	bool Evaluation(string Word);
};

