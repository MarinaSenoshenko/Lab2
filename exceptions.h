#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <exception>
#include <string>
#include <system_error>

class FileException : public std::runtime_error {
public:
	FileException(std::string fileName);
};

class BlockBeginningException : public std::exception {
public:
	const char *what() const noexcept override;
};

class BlockSyntaxException : public std::exception {
private:
	std::string msg;

public:
	BlockSyntaxException(std::string const& code_line, int pos);
	const char* what() const noexcept override;
};

class BlockInvalidWorkerNameException : public std::exception {
private:
	std::string msg;

public:
	BlockInvalidWorkerNameException(std::string const& invalid_name);
	const char* what() const noexcept override;
};

class BlockArgumentsException : public std::exception {
public:
	const char* what() const noexcept override;
};

class BlockEndException : public std::exception {
public:
	const char* what() const noexcept override;
};

class SequenceBeginningException : public std::exception {
public:
	const char* what() const noexcept override;
};

class SequenceEndException : public std::exception {
public:
	const char* what() const noexcept override;
};

class SequenceStructureException : public std::exception {
public:
	const char* what() const noexcept override;
};

class WorkerRunTimeException : public std::exception {
public:
	const char* what() const noexcept override;
};

class IException : public std::exception {
protected:
	const char* text{};
public:
	virtual const char* what() = 0;
};

class WorkflowException : public IException {
public:
	explicit WorkflowException(const char* new_text) {
		text = new_text;
	}
	const char* what() override;
};

class WorkerException : public IException {
public:
	explicit WorkerException(const char* new_text) {
		text = new_text;
	}
	const char* what() override;
};
#endif
