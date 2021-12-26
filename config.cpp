#include "config.h"
#include "constants.h"

ConfigExecutor::ConfigExecutor(const string fileName) : file_name(file_name) {}


void ConfigExecutor::Execute() {

	shared_ptr<Worker> work;

	bool out = false;
	unsigned int currId;
	ConfigParser parser(file_name);
	
	parser.Parse();

	cmds = parser.GetCmds();
	ex_ord = parser.GetOrder();

	while (!ex_ord.empty()) {
		currId = ex_ord.front();
		ex_ord.pop();

		work = createWorker(cmds[currId]);

		if (out != work->GetIO().first) {
			throw logic_error("execution order is invalid");
		}
		out = work->GetIO().second;
		work->Execute();
	}
	if (out) {
		throw logic_error("execution order is invalid!");
	}
	
}

shared_ptr<Worker> ConfigExecutor::createWorker(const string cmd) {
	regex reg("([A-Za-z0-9]+)( *)([A-Za-z0-9_.]*)( *)([A-Za-z0-9_.]*)( *)");
	smatch res;
	regex_search(cmd, res, reg);

	if (res[FIRST_ARG] == "readfile") {
		return make_shared<Reader>(&data, res[THIRD_ARG]);
	}
	if (res[FIRST_ARG] == "sort") {
		return make_shared<Sorter>(&data);
    }
	if (res[FIRST_ARG] == "replace") {
		return make_shared<Replacer>(&data, res[THIRD_ARG], res[FIFTH_ARG]);
	}
	if (res[FIRST_ARG] == "grep") {
		return make_shared<Grepper>(&data, res[THIRD_ARG]);
	}
	if (res[FIRST_ARG] == "dump") {
		return make_shared<Dumper>(&data, res[THIRD_ARG]);
	}
	if (res[FIRST_ARG] == "writefile") {
		return make_shared<Writer>(&data, res[THIRD_ARG]);
	}

	throw logic_error("Can not execute this command \"" + res[1] + "\" in " + file_name);
}
