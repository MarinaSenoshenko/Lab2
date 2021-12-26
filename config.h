#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <map>
#include <queue>
#include "exceptions.h"
#include "factories.h"


class ConfigExecutor {
private:
	const string file_name;
	map<unsigned int, string> cmds;
	queue<unsigned int> ex_ord;
	vector<string> data;
	shared_ptr<Worker> createWorker(const string cmd);
public:
	ConfigExecutor(const string file_name = "");
	void Execute();
};


class ConfigParser {
private:
	const string file_name;
	ifstream input;
	map<unsigned int, string> cmds;
	queue<unsigned int> ex_ord;
public:
	ConfigParser(const string file_name);
	void Parse();
	void ParseBlocksInit();
	void ParseExOrd();
	map<unsigned int, string>& GetCmds();
	queue<unsigned int>& GetOrder();
}
