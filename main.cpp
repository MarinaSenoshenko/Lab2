#include "config_handler.h"

int main(int argc, char* argv[1]) {
	string file_name = "workflow.txt";

	try {
		if (argc != 2) {
			throw WorkflowException("Bad number of args");
		}
		file_name = argv[1];
		ConfExecutor ex(file_name);
		ex.Execute();
	}

	catch (WorkerException& exc1) {
		std::cout << exc1.what() << std::endl;
		return 1;
	}
	catch (WorkflowException& exc2) {
		std::cout << exc2.what() << std::endl;
		return 1;
	}

	return 0;
}
