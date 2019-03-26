#include "pch.h"
#include "Automata.h"
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

istream& operator>>(istream& file, Automata& Automat)
{
	int NumbOfStates;
	file >> NumbOfStates;
	for (int i = 0; i < NumbOfStates; i++)
	{
		char state;
		file >> state;
		Automat.Q.insert(state);
	}


	int NumbOfCharacters;
	file >> NumbOfCharacters;
	for (int i = 0; i < NumbOfCharacters; i++)
	{
		char character;
		file >> character;
		Automat.S.insert(character);
	}

	int NumbOfTransitions;
	file >> NumbOfTransitions;
	for (int i = 0; i < NumbOfTransitions; i++)
	{
		Automata::transition trans;
		file >> trans.InitialState >> trans.word >> trans.DestinationState;
		Automat.delta.push_back(trans);
	}

	//initial state reading
	file >> Automat.q0;


	int NumbOfFinalStates;
	file >> NumbOfFinalStates;
	for (int i = 0; i < NumbOfFinalStates; i++)
	{
		char state;
		file >> state;
		Automat.F.insert(state);
	}
	return file;
}


bool Automata::Evaluation(string word)
{
	set<char> CurrentStates;
	CurrentStates.insert(q0);

	for (string::iterator letter = word.begin(); letter != word.end() && !CurrentStates.empty(); letter++)
	{
		set<char> NextState;
		for (set<char>::iterator state = CurrentStates.begin(); state != CurrentStates.end(); state++)
		{
			for (vector<Automata::transition>::iterator trans = delta.begin(); trans != delta.end(); trans++)
			{
				if (trans->InitialState == *state  && trans->word == *letter)
					NextState.insert(trans->DestinationState);
			}
		}
		CurrentStates = NextState;
	}

	for (set<char>::iterator state = CurrentStates.begin(); state != CurrentStates.end(); state++)
	{
		if (F.find(*state) != F.end())
			return true;
	}

	return false;

}