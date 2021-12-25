#include <exception>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include "config_handler.h"
#include "workflow_executor.h"

int main(int argc, char** argv) {
    try {
        if (argc != 2) {
            throw WorkflowException("Bad number of args");
        }
        ConfigHandler config_handler(argv[1]);
        WorkflowExecutor& workflow_executor = config_handler.ProcessConfigFile();
        workflow_executor.Execute();
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
