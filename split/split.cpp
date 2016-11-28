// split.cpp : input string and delimiter and outputs the strings seperated
//by the delimiter
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string target, string delimiter);
//precondition: input a line and delimiter
//postcondition: returns vector with strings seperated by the delimiter

int main()
{
	string line, delim_string;
	vector<string> vec_result;
	int vec_size(0);
	char delim_char;

	cout << "Enter string to split:\n";
	getline(cin,line);
	cout << "Enter delimiter string:\n";
	cin.get(delim_char);
	delim_string = delim_char;
	
	vec_result = split(line, delim_string);
	vec_size = vec_result.size();

	cout << "The substrings are: ";
	for (int i = 0; i < vec_size; i++) {
		if (i == 0)
			cout << "\"" << vec_result[i] << "\", ";
		else if ((i > 0) && (i < vec_size - 1))
			cout << "\"" << vec_result[i] << "\", ";
		else //last substring
			cout << "\"" << vec_result[i] << "\"" << endl; }

	return 0;
}

vector<string> split(string target, string delimiter)
{
	int start(0), stop(0), sub_length(0);
	string sub;
	vector<string> result;

	while ((stop < target.length()) && (stop != -1)) {
		stop = target.find(delimiter, start);
		sub_length = (stop - start);
		sub = target.substr(start, sub_length);
		result.push_back(sub);
		start = (stop + 1); }

	return result;
}