#ifndef FACTORIES_H_
#define FACTORIES_H_
#include "workers.h"
#include "exeption.h"

class IWorker {
public:
	virtual std::list<std::string>& work(std::list<std::string>& answer_data) = 0;
	virtual void setArgs(const std::list<std::string>& block_data) = 0;
};

class IFactory {
public:
	virtual std::unique_ptr<IWorker> createWorker() = 0;
};
 
class ReadFactory : public IFactory {
public:
	std::unique_ptr<IWorker> createWorker() override { 
		return std::make_unique<ReadFile>(); 
	}
};

class WriteFactory : public IFactory {
public:
	std::unique_ptr<IWorker> createWorker() override { 
		return std::make_unique<ReadFile>(); 
	}
};

class GrepFactory : public IFactory {
public:
	std::unique_ptr<IWorker> createWorker() override { 
		return std::make_unique<ReadFile>(); 
	}
};

class SortFactory : public IFactory {
public:
	std::unique_ptr<IWorker> createWorker() override { 
		return std::make_unique<ReadFile>(); 
	}
};

class ReplaceFactory : public IFactory {
public:
	std::unique_ptr<IWorker> createWorker() override { 
		return std::make_unique<ReadFile>(); 
	}
};

class DumpFactory : public IFactory {
public:
	std::unique_ptr<IWorker> createWorker() override { 
		return std::make_unique<ReadFile>(); 
	}
};

#endif
