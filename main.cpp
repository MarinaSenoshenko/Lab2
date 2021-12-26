#include "config.h"
#include "constants.h"

int main(int argc, char** argv) {
	string file_name = "workflow.txt";
	try {
		if (argc != ARGS_NUMBER) {
			file_name = argv[FIRST_ARG];
			ConfigExecutor ex(file_name);
			ex.Execute();
		}
	}

	catch (exception& ex) {
		cout << "System error: " << ex.what() << endl;
		return EXIT;
	}

	return 0;
}

