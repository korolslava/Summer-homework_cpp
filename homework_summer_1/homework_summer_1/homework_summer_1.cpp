#include "University.h"

int main()
{
	Student students[] = {
		Student("Alice", 3.5f),
		Student("Bob", 3.8f),
		Student("Charlie", 3.2f)
	};

	Faculty faculty("Computer Science", 3, students);

	Faculty faculties[] = { faculty };
	University university("Tech University", "New York", faculties);

	University university_copy = university;
	cout << "Copy of University created." << endl;
	University university_assigned;

	university_assigned = university;
	cout << "University assigned." << endl;

	University university_moved(std::move(university));
	cout << "University moved." << endl;

	university.print_all_university();
	return 0;
}
