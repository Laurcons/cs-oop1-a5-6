#pragma once
#include "vector.h"
#include "domain.h"

namespace bub {

	// Repository of Tutorials
	class tutorial_repo {
	private:
		bub::vector<tutorial> vect;
	public:
		// Creates a Tutorial Repository.
		tutorial_repo();
		// Copies a Tutorial repository.
		tutorial_repo(const tutorial_repo&);
		// Assigns a Tutorial repository to itself.
		void operator=(const tutorial_repo&);
		// Destructs a Tutorial Repository.
		~tutorial_repo();
		// Adds a new Tutorial to the repository. If a Tutorial with the same title exists, it will throw.
		void add(const tutorial& tut);
		// Retrieves a list of all the tutorials in the repository.
		bub::vector<tutorial> get_all() const;
		// Retrieves a Tutorial from the repository by its title.
		tutorial* find_title(std::string);
		// Removes a Tutorial from the repository.
		void remove(const tutorial& tut);
	};

}