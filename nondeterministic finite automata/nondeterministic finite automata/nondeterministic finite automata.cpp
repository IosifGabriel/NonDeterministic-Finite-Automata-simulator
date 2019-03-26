#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Automata.h"
using namespace std;

ifstream f("dateDFA.in");
ifstream g("dateNFA.in");

int main() {
	Automata DFA,NFA;
	f >> DFA;
	g >> NFA;
	string WordNFA,WordDFA;
	f >> WordDFA;
	g >> WordNFA;

	cout << "DFA" << endl;
	if (DFA.Evaluation(WordDFA))
		cout << "Word is accepted"<<endl;
	else
		cout << "Word is not accepted"<<endl;

	cout << "NFA"<<endl;
	if (NFA.Evaluation(WordNFA))
		cout << "Word is accepted" << endl;
	else
		cout << "Word is not accepted" << endl;

	f.close();
	g.close();
	return 0;
}
