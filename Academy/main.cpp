#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define delimiter "\n---------------------\n"
#define DEBUG

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	int age;

public:
	const std::string& get_last_name() const
	{
		return last_name;
	}
	const std::string& get_first_name() const
	{
		return first_name;
	}
	int get_age() const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}
	//	consrtuctors
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
#ifdef DEBUG
		cout << "HConstructor:\t" << this << endl;
#endif // DEBUG

	}
	virtual ~Human()
	{
#ifdef DEBUG
		cout << "HDestructor:\t" << this << endl;
#endif // DEBUG

	}
	//	Methods
	virtual void info() const
	{
		cout << last_name << " " << first_name << " " << age << endl;
	}
	virtual void write_to_file(const string FIleName) const
	{
		std::fstream fout;
		fout.open(FIleName, std::fstream::app);
		fout << endl << last_name << "|" << first_name << "|" << age << "|";
		fout.close();
	}
	/*std::ostream& operator<< (std::ostream& os)
	{
		return os << this->last_name << " " << this->first_name << " " << this->age;
	}*/
};   //Human
std::ostream& operator<< (std::ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age();
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating; //успеваемость
	double attendance; //посещаемость
public:
	const std::string& get_speciality() const
	{
		return speciality;
	}
	const std::string& ret_group() const
	{
		return group;
	}
	double get_rating() const
	{
		return rating;
	}
	double get_attendance() const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//	Constructors
	Student
	(
		HUMAN_TAKE_PARAMETERS,
		STUDENT_TAKE_PARAMETERS
	):Human (HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
#ifdef DEBUG
		cout << "SConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Student()
	{
#ifdef DEBUG
		cout << "SDestructor:\t" << this << endl;
#endif // DEBUG
	}
	//	Methods
	void info() const override
	{
		Human::info();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
	void write_to_file(const string FIleName) const override
	{
		Human::write_to_file(FIleName);
		std::fstream foutS;
		foutS.open(FIleName, std::fstream::app);
		foutS << speciality << "|" << group << "|" << rating << "|" << attendance << "|";
		foutS.close();
	}
}; //Student
std::ostream& operator<< (std::ostream& os, const Student& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " " << obj.get_speciality() << " " << obj.ret_group() << " " << obj.get_rating() << " " << obj.get_attendance ();
}

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher :public Human
{
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality() const
	{
		return speciality;
	}
	int get_experience() const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}
	// constructors
	Teacher
	(
		HUMAN_TAKE_PARAMETERS,
		TEACHER_TAKE_PARAMETERS
	) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
#ifdef DEBUG
		cout << "TConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Teacher()
	{
#ifdef DEBUG
		cout << "TDestructor:\t" << this << endl;
#endif // DEBUG


	}
	// Methods
	void info() const override
	{

		Human::info();
		cout << speciality << " " << experience << endl;
	}
	void write_to_file (const string FileName) const override
	{
		Human::write_to_file(FileName);
		std::ofstream foutT;
		foutT.open(FileName, std::fstream::app);
		foutT << speciality << "|" << experience << "|";
		foutT.close();
	}
};  //Teacher
std::ostream& operator<< (std::ostream& os, const Teacher& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " " << obj.get_speciality() << " " << obj.get_experience();
}

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject() const
	{
		return subject;
	}
	Graduate(
		HUMAN_TAKE_PARAMETERS,
		STUDENT_TAKE_PARAMETERS,
		const std::string& subject
	):Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		this->subject = subject;
#ifdef DEBUG

		cout << "GConstructor:\t" << this << endl;
#endif // DEBUG

	}
		~Graduate()
	{
#ifdef DEBUG

			cout << "GDestructor:\t" << this << endl;
#endif // DEBUG

	}
		void info()const override
		{ 
			Student::info();
			cout << subject << endl;
		}
		void write_to_file(const string FileName) const override
		{
			Student::write_to_file(FileName);
			std::ofstream foutG;
			foutG.open(FileName, std::fstream::app);
			foutG << subject << "|";
			foutG.close();
		}
};  //Graduate
std::ostream& operator<< (std::ostream& os, const Graduate& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " " << obj.get_speciality() << " " << obj.ret_group() << " " << obj.get_rating() << " " << obj.get_attendance() << " " << obj.get_subject();
}


//#define INHERITANCE
//#define POLYMORPHISM
#define STD_COUT
//#define WRITE_GROUP_TO_FILE
//#define TEST_READ_GROUP_FROM_FILE
//#define READ_GROUP_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	Human human("Montana", "Antonio", 25);
	human.info();

	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 99);
	student.info();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.info();

	Graduate graduate("Schreder", "Hank", 40, "Criminalistic", "WW_220", 40, 60, "How to catch Heisenberg");
	graduate.info();
#endif // INHERITANCE

#ifdef POLYMORPHISM
	Human* group[] =
	{
		new Human("Montana", "Antonio", 25),
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 99),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schreder", "Hank", 40, "Criminalistic", "WW_220", 40, 60, "How to catch Heisenberg"),
		new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons disrtibution", 20)
	};
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->info();
		cout << delimiter;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // POLYMORPHISM

#ifdef STD_COUT

	Human human("Montana", "Antonio", 25);
	cout << "Human: " << human << endl;

	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 99);
	cout << "Student: " << student << endl;

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	cout << "Teacher: " << teacher << endl;

	Graduate graduate("Schreder", "Hank", 40, "Criminalistic", "WW_220", 40, 60, "How to catch Heisenberg");
	cout << "Graduate: " << graduate << endl;
#endif // STD_COUT

	string FileName = "GroupFile.txt";
#ifdef WRITE_GROUP_TO_FILE
	std::ofstream fout;
	fout.open(FileName);	//открываем файл на ПЕРЕзапись
	fout << "Our group:";	//очищаем файл в начале каждого запуска программы
	fout.close();

	Human* group[] =
	{
		new Human("Montana", "Antonio", 25),
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 99),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schreder", "Hank", 40, "Criminalistic", "WW_220", 40, 60, "How to catch Heisenberg"),
		new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons disrtibution", 20)
	};
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->write_to_file(FileName);
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}


	//string sys_command;
	//sys_command = "notepad " + FileName + "\0";
	//cout << sys_command;
	
#ifdef DEBUG
	system("notepad GroupFile.txt");	//нельзя передать имя файла из переменной??  
#endif // DEBUG


#endif // WRITE_GROUP_TO_FILE

#ifdef TEST_READ_GROUP_FROM_FILE
	//============TEST============
	int n = 6;
	Human** groupTEST = new Human * [n];
	groupTEST[0] = new Human("", "", 0);
	groupTEST[0]->set_first_name("Montana");
	groupTEST[0]->set_last_name("Antonio");
	groupTEST[0]->set_age(25);
	cout << *groupTEST[0];
	//============TEST============  
#endif // TEST_READ_GROUP_FROM_FILE


#ifdef READ_GROUP_FROM_FILE
	std::ifstream fin(FileName);

	int n = 0;
	if (fin.is_open())
	{
		//просто считаем строки. Количество строк-1 - это количество элементов в группе
		while (!fin.eof())
		{
			const int SIZE = 1024;
			char line_buf[SIZE] = {};
			fin.getline(line_buf, SIZE);
#ifdef DEBUG
			cout << n << ": " << line_buf << endl;
#endif // DEBUG

			n++;
		}
		n--;
		fin.close();
	} //посчитали строки
	else 	{	std::cerr << "Error: file not found.\n";	}
	if (!n) 	{	cout << "0 group members is found in file \"" << FileName << "\"\n";	}
	else if (n > 0)     //если есть строки, предположительно с элементами классов, 
						// снова открываем файл, создаем group и тд
	{
		Human** group_from_file = new Human* [n];
		std::ifstream fin(FileName);
		if (fin.is_open())
		{
			int n_current = 0;  //текущий элемент строки (порядковый номер)
			const int SIZE = 1024;
			char str[SIZE] = {};
			fin.getline(str, SIZE); // первую строку считываем впустую, она нам не нужна
			while (!fin.eof())
			{
				for (int i = 0; i < n; i++)
				{
					//char str[SIZE] = {};
					char* pch;
					//int current_int = 0;
					fin.getline(str, SIZE);
					// сохраняем копию строки
					char str_buf[SIZE] = {};
					int j = 0;
					do
					{
						str_buf[j] = str[j];
						j++;
					} while (str[j]);
					//ENd OF сохраняем копию строки

					//анализируем и обрабатываем строки:

					int n_elements = 0; // количество элементов в строке
					pch = strtok(str, "|");
					while (pch)
					{
#ifdef DEBUG
						cout << pch << " ";
#endif // DEBUG

						pch = strtok(NULL, "|");
						n_elements++;
					}  //просто посчитали количество переменных в строке и ничего и ними не делали
#ifdef DEBUG
					cout << " - " << n_elements << endl;
#endif // DEBUG

					char* ln = strtok(str_buf, "|");
					char* fn = strtok(NULL, "|");
					int age_tmp = atoi(strtok(NULL, "|"));
					switch (n_elements) //в зависимости от количества элементов создаем нужный класс в группе
					{
					case 3: {
						group_from_file[n_current] = new Human(ln, fn, age_tmp);
						break;
					}
					case 5: {
						char* sp = strtok(NULL, "|");
						int exp = atoi(strtok(NULL, "|"));
						group_from_file[n_current] = new Teacher(ln, fn, age_tmp, sp, exp);
						break;
					}
					case 7: {
						char* sp = strtok(NULL, "|");
						char* gr = strtok(NULL, "|");
						int rate = atoi(strtok(NULL, "|"));
						int att = atoi(strtok(NULL, "|"));
						group_from_file[n_current] = new Student(ln, fn, age_tmp, sp, gr, rate, att);
						break;
					}
					case 8: {
						char* sp = strtok(NULL, "|");
						char* gr = strtok(NULL, "|");
						int rate = atoi(strtok(NULL, "|"));
						int att = atoi(strtok(NULL, "|"));
						char* subj = strtok(NULL, "|");
						group_from_file[n_current] = new Graduate(ln, fn, age_tmp, sp, gr, rate, att, subj);
						break;
					}
					}
					//END OF анализируем и обрабатываем строки.

					n_current++;
				}  //END OF for
			}  //while (!fin.eof())
			fin.close();

			//=======================DELETE!!!==============================
			for (int i = 0; i < n; i++)  //sizeof(group_from_file) / sizeof(group_from_file[0]) - не работает!!!
			{
				cout << delimiter;
#ifdef DEBUG
				cout << "INFO(): ";
#endif // DEBUG

				group_from_file[i]->info();
#ifdef DEBUG
				cout << "COUT: " << *group_from_file[i] << endl;
#endif // DEBUG

			}
			for (int i = 0; i < n; i++)
			{
				delete group_from_file[i];
			}
			delete[] group_from_file;

		}  //if (fin.is_open())
		else { std::cerr << "Error: file not found.\n"; }
	}

#endif // READ_GROUP_FROM_FILE

}