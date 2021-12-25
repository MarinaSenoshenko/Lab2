#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include "exceptions.h"

using namespace std;


class Worker {
public:
	virtual void Execute() = 0;
	virtual pair<bool, bool> GetIO() const = 0;
};

class Reader : public Worker {
protected:
	const string fileName;
	vector<string>* data;
public:
	Reader(vector<string>* data, const string fileName = "");
	virtual void Execute();
	virtual pair<bool, bool> GetIO() const;
};

class Grepper : public Worker {
private:
	vector<string>* data;
	vector<string> new_data;
	const string word;
public:
	Grepper(vector<string>* data, const string word = "");
	virtual void Execute();
	virtual pair<bool, bool> GetIO() const;
};

class Writer : public Worker {
private:
	string fileName;
	vector<string>* data;
public:
	Writer(vector<string>* data, string fileName = "");
	virtual void Execute();
	virtual pair<bool, bool> GetIO() const;
};

class Sorter : public Worker {
private:
	vector<string>* data;
public:
	Sorter(vector<string>* data);
	virtual void Execute();
	virtual pair<bool, bool> GetIO() const;
};

class Replacer : public Worker {
private:
	vector<string>* data;
	const string word1;
	const string word2;
public:
	Replacer(vector<string>* data, const string word1 = "", const string word2 = "");
	virtual void Execute();
	virtual pair<bool, bool> GetIO() const;
};

class Dumper : public Worker {
private:
	const string fileName;
	vector<string>* data;
public:
	Dumper(vector<string>* data, const string fileName = "");
	virtual void Execute();
	virtual pair<bool, bool> GetIO() const;
};
