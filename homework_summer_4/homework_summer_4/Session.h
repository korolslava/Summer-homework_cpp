#pragma once
#include "Movie.h"

enum SessionType {
	Regular,
	ThreeD,
	IMAX
};

enum Hall {
	Hall1,
	Hall2,
	Hall3
};

class Session {
	Movie movie;
	SessionType type;
	int startTime;
	Hall hall;
public:
	Session() : movie(), type(Regular), startTime(0), hall(Hall1) {}
	Session(const Movie& m, SessionType t, int st, Hall h)
		: movie(m), type(t), startTime(st), hall(h) {
	}
	Session(const Session& s)
		: movie(s.movie), type(s.type), startTime(s.startTime), hall(s.hall) {
	}
	Session& operator=(const Session& s) {
		if (this != &s) {
			movie = s.movie;
			type = s.type;
			startTime = s.startTime;
			hall = s.hall;
		}
		return *this;
	}
	Session(Session&& s) noexcept
		: movie(std::move(s.movie)), type(s.type), startTime(s.startTime), hall(s.hall) {
		s.startTime = 0;
	}
	Session& operator=(Session&& s) noexcept {
		if (this != &s) {
			movie = std::move(s.movie);
			type = s.type;
			startTime = s.startTime;
			hall = s.hall;
			s.startTime = 0;
		}
		return *this;
	}
	~Session() {
		cout << "Session destructor called for movie: " << movie.getTitle() << endl;
	}

	const Movie& getMovie() const { return movie; }
	SessionType getType() const { return type; }
	int getStartTime() const { return startTime; }
	Hall getHall() const { return hall; }

	void setMovie(const Movie& m) { movie = m; }
	void setType(SessionType t) { type = t; }
	void setStartTime(int st) { startTime = st; }
	void setHall(Hall h) { hall = h; }


	void print() const {
		cout << "Session: " << movie.getTitle() << ", Type: " << type
			<< ", Start Time: " << startTime << ", Hall: " << hall << endl;
		movie.print();
	}
};