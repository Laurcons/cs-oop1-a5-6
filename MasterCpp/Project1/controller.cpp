#include "base.h"
#include "controller.h"

namespace bub {

	tutorial_controller::tutorial_controller(tutorial_repo& repo) :
		repo(repo) {}

	tutorial_controller::tutorial_controller(const bub::tutorial_controller& t) :
		repo(t.repo) {}

	void tutorial_controller::operator=(const tutorial_controller& t) {
		this->repo = t.repo;
	}

	void tutorial_controller::add_tutorial(
		std::string title,
		std::string presenter,
		int minutes, int seconds,
		int likes,
		std::string link
	) {
		bub::tutorial tut{
			title,
			presenter,
			bub::duration {minutes, seconds},
			likes,
			link
		};
		this->repo.add(tut);
	}

	tutorial& tutorial_controller::edit_start(std::string title) {
		// find by title
		tutorial* t = this->repo.find_title(title);
		if (t == nullptr)
			throw std::exception("Entity not found");
		return *t;
	}

	void tutorial_controller::edit_end(
		tutorial& tut,
		std::string newTitle,
		std::string newPresenter,
		int newMin, int newSec,
		int newLikes, std::string newLink
	) {
		tut.set_title(newTitle)
			.set_presenter(newPresenter)
			.set_duration(bub::duration{ newMin, newSec })
			.set_likes(newLikes)
			.set_link(newLink);
	}

	void tutorial_controller::remove(std::string title) {
		tutorial* tut = this->repo.find_title(title);
		if (tut == nullptr)
			throw std::exception("Entity not found");
		this->repo.remove(*tut);
	}

	bub::vector<tutorial> tutorial_controller::get_all() {
		return this->repo.get_all();
	}

}