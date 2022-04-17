#pragma once
#include <exception>
#include <string>

namespace bub {

	class repo_exception : public std::exception
	{
		std::string msg;
	public:
		repo_exception() : msg("Repo exception") {}
		repo_exception(std::string msg) : msg(msg) {}
		const char* what() {
			return this->msg.c_str();
		}
	};

}