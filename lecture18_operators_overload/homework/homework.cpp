#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

#include "complex.h"

#define DEBUG 0

using namespace std;

string remove_spaces(string s) {
	size_t found = s.find_first_of(" ");

	while (found != -1 /*string::npos*/) {
		s.erase(s.begin() + found);
		found = s.find_first_of(" ", found);
	}

	return s;
}

complex str2comp(string right) {
	size_t pos_in_com, pos_start_in_com = 0;
	vector<string> parts;
	complex res(0, 0);

	while ((pos_in_com = right.find_first_of("(,)", pos_start_in_com)) != -1) {
		string part = right.substr(pos_start_in_com, pos_in_com - pos_start_in_com);

		if (part.length() != 0)
			parts.push_back(part);

		pos_start_in_com = pos_in_com + 1;
	}

	if (DEBUG) {
		cout << "\nGot init numbers: \n";
		int num_com = 1;

		for (string s : parts)
			cout << num_com++ << ": \"" << s << '\"' << endl;

		cout << "Number of init numbers: " << parts.size() << endl;
	}

	if (parts.size() == 2)
		res = complex(stod(parts[0]), stod(parts[1]));
	else {
		if (DEBUG)
			cout << "Wrong init numbers!!" << endl;
	}

	return res;
}

complex solve(string s) {
	size_t pos = s.find_first_of("(,-+*/)");
	complex res;
	/* will be soon */

	return res;
}

int main() {
	cout << "You've entered command line (Leave empty line to exit) \n";
	cout << "You can create complex numbers and work with them: \n\n";
	cout << "Init var:\n>>> var_mane = (x, y)\n\n";
	cout << "Enter more than 1 command:\n>>> a=b;c=d;\n\n";
	cout << "Multiply and divide by double inplace:\n>>> a *= 50.32\n\n";
	cout << "Print variables:\n>>> print a\n>>> print b, c\n\n";
	cout << "Assign var to simple operation result:\n>>> a = (0, 1) + (1, 0)\n>>> b = d / (9, 1)\n\n";

	cout << "You are welcome\n";
	map<string, complex> variables;

	while (1) {
		// Enter line of commands
		cout << ">>> ";
		string in;
		getline(cin, in);
		vector<string> commands;

		size_t pos, pos_start = 0;

		while ((pos = in.find(';', pos_start)) != -1) {
			string command = remove_spaces(in.substr(pos_start, pos - pos_start));

			if (command.length() != 0)
				commands.push_back(command);

			pos_start = pos + 1;
		}

		string command = remove_spaces(in.substr(pos_start));

		if (command.length() != 0)
			commands.push_back(command);

		if (commands.size() == 0)
			break;

		if (DEBUG) {
			cout << "\nGot commands: \n";
			int num_com = 1;

			for (string s : commands)
				cout << num_com++ << ": \"" << s << '\"' << endl;

			cout << "Number of commands: " << commands.size() << endl;
		}

		// -----------
		// processing commands
		int num_com = 1;

		for (string command : commands) {
			if (DEBUG)
				cout << "\nSolve command " << num_com++ << endl;

			if ((pos = command.find('=', 0)) != -1) { // assign
				string left, right;
				left = command.substr(0, pos);

				if (pos == -1)
					right = "";
				else
					right = command.substr(pos + 1, command.length());

				if (DEBUG) {
					cout << "Parsed commands parts: \n";
					cout << "left: \"" << left << "\"\t" << "right: \"" << right << "\"" << endl;
				}

				char last_c = left[left.length() - 1];

				if (last_c == '*') {
					left = left.substr(0, left.length() - 1);
					variables[left] *= stod(right);

				} else if (last_c == '/') {
					left = left.substr(0, left.length() - 1);
					variables[left] /= stod(right);

				} else if ((pos = right.find_first_of("+-*/")) !=
				           -1) { // will be replaced by solve(right);
					string l, r;
					l = right.substr(0, pos);
					r = right.substr(pos + 1);
					complex res(0, 0);
					complex L, R;
					size_t on_init;

					if ((on_init = l.find('(')) != -1)
						L = str2comp(l);
					else
						L = variables[l];

					if ((on_init = r.find('(')) != -1)
						R = str2comp(r);
					else
						R = variables[r];

					switch (right[pos]) {
						case '+':
							res = L + R;
							break;

						case '-':
							res = L - R;
							break;

						case '*':
							res = L * R;
							break;

						case '/':
							res = L / R;
							break;
					}

					variables[left] = res;

				} else   // Init
					variables[left] = str2comp(right);

			} else if ((pos = command.find("print", 0)) != -1) { // print
				vector<string> names_to_print;
				size_t pos_q, pos_start = 0;
				string line = command.substr(pos + 5);
				string part;

				while ((pos_q = line.find_first_of(",", pos_start)) != -1) {
					part = line.substr(pos_start, pos_q - pos_start);

					if (part.length() != 0)
						names_to_print.push_back(part);

					pos_start = pos_q + 1;
				}

				part = line.substr(pos_start);

				if (part.length() != 0)
					names_to_print.push_back(part);

				if (DEBUG) {
					cout << "\nGot names: \n";
					int num_com = 1;

					for (string s : names_to_print)
						cout << num_com++ << ": \"" << s << '\"' << endl;

					cout << "Number of names: " << names_to_print.size() << endl;
				}

				for (string name : names_to_print)
					cout << variables[name] << ", ";

				cout << "\b\b \n";
			}

		}

	}

	if (1) {
		for (auto pair : variables)
			cout << "variables[" << pair.first << "] = " << pair.second << endl;
	}

	system("pause");

	return 0;
}