NonDeterministic Finite Automata  - Iosif Gabriel,143
Faculty of Mathematics and Informatics, University of Bucharest

I simulated an NFA using the set, string, vector library from C++ merging with overloading operators.

The grammar, states and final states are sets, because they have to be unique.

Delta (transition function) is declared as a vector of  struct because I need to know: where to begin, the rule of transition and where it ends.

I overloaded the “>>” operator for easier reading.

Evaluation is a bool method with the word as a header input. It searches the word, letter by letter and transition by transition and puts each good transition in a set. At the final, if it encounters a final state in the set it means that the word was accepted.



