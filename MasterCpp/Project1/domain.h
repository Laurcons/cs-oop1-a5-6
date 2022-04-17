#pragma once
#include <string>
#include <iostream>

namespace bub {

	// Structure for a duration in minutes and seconds.
	struct duration {
		int m;
		int s;

		bool operator==(const bub::duration& other) const {
			return this->m == other.m && this->s == other.s;
		}
	};

	// Class for storing data about a Tutorial.
	class tutorial {
	private:
		std::string title;
		std::string presenter;
		bub::duration duration;
		int likes;
		std::string link;
	public:
		// Creates a tutorial with some default values.
		tutorial() {
			this->title = "";
			this->presenter = "";
			this->duration = bub::duration{ 0, 0 };
			this->likes = 0;
			this->link = "";
		};
		// Creates a tutorial with custom values.
		tutorial(
			std::string title,
			std::string presenter,
			bub::duration duration,
			int likes,
			std::string link
		) :
			title{ title },
			presenter{ presenter },
			duration{ duration },
			likes{ likes },
			link{ link }
		{}
		// Copies a tutorial.
		tutorial(const tutorial& t) :
			title{ t.title },
			presenter{ t.presenter },
			duration{ t.duration },
			likes{ t.likes },
			link{ t.link }
		{}
		// Assigns a tutorial to itself.
		tutorial& operator=(const tutorial& t) {
			this->title = t.title;
			this->presenter = t.presenter;
			this->duration = t.duration;
			this->likes = t.likes;
			this->link = t.link;
			return *this;
		}

		// Retrieves the title of the tutorial.
		std::string get_title() const { return this->title; }
		// Sets the title of the tutorial. Returns itself.
		tutorial& set_title(std::string title) { this->title = title; return *this; }
		// Gets the presenter of the tutorial.
		std::string get_presenter() const { return this->presenter; }
		// Sets the presenter of the tutorial. Returns itself. 
		tutorial& set_presenter(std::string presenter) { this->presenter = presenter; return *this; }
		// Gets the duration of the tutorial.
		bub::duration get_duration() const { return this->duration; }
		// Sets the duration of the tutorial. Returns itself.
		tutorial& set_duration(bub::duration duration) { this->duration = duration; return *this; }
		// Gets the like count of the tutorial.
		int get_likes() const { return this->likes; }
		// Sets the like count of the tutorial. Returns itself.
		tutorial& set_likes(int likes) { this->likes = likes; return *this; }
		// Increments the like count by one. Returns itself.
		tutorial& inc_likes() { this->likes++; return *this; }
		// Gets the link of the tutorial.
		std::string get_link() const { return this->link; }
		// Sets the link of the tutorial. Returns itself.
		tutorial& set_link(std::string link) { this->link = link; return *this; }

		// Operator for checking equality.
		bool operator==(const tutorial& other) {
			return this->title == other.title;
		}
		// Operator for checking inequality.
		bool operator!=(const tutorial& other) {
			return !(*this == other);
		}

		// Operator for out stream.
		friend std::ostream& operator<<(std::ostream& os, const tutorial& t) {
			return os
				<< "\"" << t.title << "\" "
				<< "by " << t.presenter << ", "
				<< t.duration.m << ":" << t.duration.s << " "
				<< t.likes << " likes, at " << t.link;
		}

	};

}