#include "wk7Stack.h"

int main(){
	Stack st;
	st.push(3);
	st.push(1);
	st.push(4);
	st.push(1);
	st.push(5);
	st.push(9);
	st.push(2);

	cout << st << endl;

	cout << "now popping off the Stack entries one-by-one onto an undo Stack" << endl << endl;
	Stack stUndo;
	while (!st.empty()){
		int x = st.top();
		stUndo.push(x);
		st.pop();
	}
	cout << "Stack is now: " << st << endl;
	cout << "Undo stack is now: " << stUndo << endl;
	cout << "...done." << endl;

	return 0;

}