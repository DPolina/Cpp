#include <iostream> 
#include <iomanip> 
#include <string> 

using namespace std;

struct Student {

	char name[30];
	double mark;
	int course;

};

void inStudent(Student* data, int k) {

	for (int i = 0; i < k; i++)
	{
		cout << "Student " << i + 1 << ":\n";
		cin.ignore();

		cout << "name: ";
		cin.getline(data[i].name, sizeof(data[i].name));
		cout << "mark: ";
		cin >> data[i].mark;
		cout << "course: ";
		cin >> data[i].course;
	}
}


void outStudent(Student& data) {
	cout << setw(25) << left << data.name << setw(4) << data.mark << setw(10) << data.course;
	cout << "\n";
}

void outStudents(Student* data, int k) {

	for (int i = 0; i < k; i++) {

		outStudent(data[i]);
	}
}

void averageMark(Student* data, int k, int curs) {

	if (k <= 0) {
		return;
	}

	double overall_mark = 0;
	int count = 0;

	for (int i = 0; i < k; i++) {
		if (data[i].course == curs) {
			overall_mark += data[i].mark;
			count++;
		}
	}
	double average_mark = overall_mark / count;

	cout << "/nAVERAGE MARK : " << average_mark;
}

int main() {

	int k, curs;
	cout << "Enter the amount of students: "; 
	cin >> k;
	Student* data = new Student[k];

	inStudent(data, k);
	cout << "\n";
	outStudents(data, k);
	cout << "\nENTER COURSE: "; 
	cin >> curs;
	averageMark(data, k, curs);

	delete[]data;
}