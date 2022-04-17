#include "base.h"
#include "repository.h"

namespace bub {

	tutorial_repo::tutorial_repo() {
		this->vect = bub::vector<tutorial>{};
	}

	tutorial_repo::tutorial_repo(const tutorial_repo& repo) {
		this->vect = repo.vect;
	}

	void tutorial_repo::operator=(const tutorial_repo& repo) {
		this->vect = repo.vect;
	}

	tutorial_repo::~tutorial_repo() {
		//
	}

	void tutorial_repo::add(const tutorial& tut) {
		// check if it already exists with that title
		for (auto t : this->vect) {
			if (t.get_title() == tut.get_title()) {
				throw std::exception("Entity already exists");
			}
		}
		this->vect.add(tut);
	}

	void tutorial_repo::remove(const tutorial& tut) {
		for (int i = 0; i < this->vect.size(); i++) {
			if (this->vect[i] == tut) {
				this->vect.remove(i);
				return;
			}
		}
	}

	bub::vector<tutorial> tutorial_repo::get_all() const {
		return this->vect;
	}

	tutorial* tutorial_repo::find_title(std::string title) {
		for (tutorial& t : this->vect)
			if (t.get_title() == title)
				return &t;
		return nullptr;
	}
}