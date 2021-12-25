#include "factories.h"
#include <fstream>

Reader::Reader(vector<string>* data, const string fileName) : data(data), fileName(fileName) {}
Grepper::Grepper(vector<string>* data, const string word) : data(data), word(word) {}
Sorter::Sorter(vector<string>* data) : data(data) {}
Replacer::Replacer(vector<string>* data, const string word1, const string word2) : data(data), word1(word1), word2(word2) {}
Writer::Writer(vector<string>* data, string fileName) : data(data), fileName(fileName) {}



pair<bool, bool> Reader::GetIO() const {
	return make_pair(false, true);
}
pair<bool, bool> Grepper::GetIO() const {
	return make_pair(true, true);
}
pair<bool, bool> Sorter::GetIO() const {
	return make_pair(true, true);
}
pair<bool, bool> Replacer::GetIO() const {
	return make_pair(true, true);
}
pair<bool, bool> Writer::GetIO() const {
	return make_pair(true, false);
}


void Reader::Execute() {
	ifstream input(fileName);
	if (!input) {
		throw FileException(fileName);
	}
	string buffer;
	while (!input.eof()) {
		getline(input, buffer);
		data->push_back(buffer + '\n');
	}
}


void Grepper::Execute() {
	for (auto& it : *data) {
		int pos = it.find(word);
		string buffer = it;
		if (pos >= 0)
			new_data.push_back(it);
	}
	*data = new_data;
}

void Sorter::Execute() {
	std::sort(data->begin(), data->end());

}

void Replacer::Execute() {
	for (auto& it : *data) {
		int pos = it.find(word1);
		if (pos >= 0)
			it.replace(pos, word1.length(), word2);
	}
}

void Writer::Execute() {
	ofstream output(fileName);
	if (!output)
		throw FileException(fileName);

	for (auto& it : *data)
		output << it;
}



