#include <iostream>
#include <fstream>
#include <string>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age
//#define DEBUG

class Human
{
	static const int TYPE_WIDTH = 10;
	static const int LAST_NAME_WIDTH = 18;
	static const int FIRST_NAME_WIDTH = 15;
	static const int AGE_WIDTH = 3;
	//static int count;  //ОШИБКА REDEFINITION!!!!
	std::string last_name;
	std::string first_name;
	int age;
	static int count;
public:
	static int get_count()
	{
		return count;
	}
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
		count++;
#ifdef DEBUG
		cout << "HConstructor:\t" << this << endl;
#endif // DEBUG

	}
	virtual ~Human()
	{
		count--;
#ifdef DEBUG
		cout << "HDestructor:\t" << this << endl;
#endif // DEBUG

	}
	//	Methods
	virtual std::ostream& info(std::ostream& os) const
	{
		//return os << last_name << " " << first_name << " " << age;
		os << std::left;
		os.width(TYPE_WIDTH);
		os << std::string(typeid(*this).name() + 6) + ":";
		os.width(LAST_NAME_WIDTH);
		os << last_name;
		os.width(FIRST_NAME_WIDTH);
		os << first_name;
		os.width(AGE_WIDTH);
		os << age;
		return os;
	}
	virtual std::istream& scan(std::istream& is)
	{
		return is >> last_name >> first_name >> age;
	}
}; // end of Human
int Human::count = 0;
std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	//return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age();
	return obj.info(os);
}
std::istream& operator>> (std::istream& is, Human& obj)
{
	return obj.scan(is);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student :public Human
{
	static const int SPECIALITY_WIDTH = 22;
	static const int GROUP_WIDTH = 8;
	static const int RATING_WIDTH = 5;
	std::string speciality; //спецИальность
	std::string group; //Группа
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
	 std::ostream& info(std::ostream& os) const override
	{
		 Human::info(os);
		 os.width(SPECIALITY_WIDTH);
		 os << speciality;
		 os.width(GROUP_WIDTH);
		 os << group;
		 os.width(RATING_WIDTH);
		 os << rating;
		 os.width(RATING_WIDTH);
		 os << attendance;
		 return os;
		//Human::info(os) << " ";
		//return os << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
	 std::istream& scan(std::istream& is) override
	 {
		 /*char* buffer = new char[SPECIALITY_WIDTH + 2];
		 Human::scan(is);
		 is.read(buffer, 22);
		 speciality = buffer;
		 is >> group;
		 is >> rating;
		 is >> attendance;
		 return is; */
	
		 return Human::scan(is) >> speciality >> group >> rating >> attendance;
	 }
}; //end of Student

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher :public Human
{
	static const int  SPECIALITY_WIDTH = 22;
	static const int EXPERIENCE_WIDTH = 3;
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
	std::ostream& info(std::ostream& os) const override
	{
		Human::info(os);
		os.width(SPECIALITY_WIDTH);
		os << speciality;
		os.width(EXPERIENCE_WIDTH);
		os << experience;
		return os;
		//Human::info(os) << " ";
		//return os << speciality << " " << experience << endl;
	}
	std::istream& scan(std::istream& is) override
	{
		char* buffer = new char[SPECIALITY_WIDTH] {};
		Human::scan(is);
		buffer[SPECIALITY_WIDTH - 1] = 0;
		is.read(buffer, SPECIALITY_WIDTH);
		buffer[SPECIALITY_WIDTH-1] = 0;
		speciality = buffer + 1;
		is >> experience;
		delete[] buffer;
		return is;
		//return Human::scan(is) >> speciality >> experience;
	}
}; //end of Teacher

class Graduate :public Student
{
	static const int SUBJECT_WIDTH = 20;
	std::string subject;
public:
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
		std::ostream& info(std::ostream& os)const override
		{ 
			Student::info(os);
			os.width(SUBJECT_WIDTH);
			os << subject;
			return os;
			//Student::info(os) << " ";
			//return os << subject << endl;
		}
		std::istream& scan(std::istream& is) override
		{
			return std::getline(Student::scan(is), subject);
		}
}; //end of Graduate

void Print(Human* group[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *group[i] << endl;
	}
	cout << "Количество людей: " << group[0]->get_count() << endl;
}
void Save(Human** group, const int n, const char filename[])
{
	std::ofstream fout(filename);

	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	system((std::string("start notepad ") + filename).c_str());
}
Human* HumanFactory(/*const*/ std::string& type)
{
	Human* human = nullptr;
	if (strstr(type.c_str(), "Human"))
		human = new Human("", "", 0);
	if (strstr(type.c_str(), "Student"))
		human = new Student("", "", 0, "", "", 0, 0);
	if (strstr(type.c_str(), "Graduate"))
		human = new Graduate("", "", 0, "", "", 0, 0, "");
	if (strstr(type.c_str(), "Teacher"))
		human = new Teacher("", "", 0, "", 0);
	return human;
}
Human** Load(const char filename[])
{
	int n = 0;
	Human** group = nullptr;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		std::string buffer;
		while (!fin.eof())
		{
			std::getline(fin, buffer);
			if (buffer.size() != 0) n++;
		}
		cout << "Количество объектов: " << n << endl;
		group = new Human * [n] {};
		fin.clear();
		fin.seekg(0);

		for (int i = 0; i < n; i++)
		{
			std::getline(fin, buffer, ':');
			group[i] = HumanFactory(buffer);
			fin >> *group[i];
		}
	}
	fin.close();
	return group;
}
void Clear(Human** group, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
}

//#define INHERITANCE
//#define POLYMORPHISM
//#define WRITE_TO_FILE 


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

	char filename[] = "group.txt";

#ifdef POLYMORPHISM

	Human* group[] =
	{
		new Human("Montana",	"Antonio",	25),
		new Student("Pinkman",	"Jessie",	22, "Chemistry",			"WW_220",	95, 99),
		new Teacher("White",	"Walter",	50, "Chemistry",			25),
		new Graduate("Schreder", "Hank",	40, "Criminalistic",		"WW_220",	40, 60, "How to catch Heisenberg"),
		new Student("Vercetty", "Tommy",	30, "Theft",				"Vice",		98, 99),
		new Teacher("Diaz",		"Ricardo",	50, "Weapons disrtibution",	20),
		new Graduate("Targarian", "Daineris", 22, "Flight", "GoT", 91, 92, "How to make smoke"),
		new Teacher("Schwartzenegger", "Arnold", 85, "Heavy Metal", 60)
	};
	std::ofstream fout(filename);

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		//group[i]->info();
		cout << *group[i] << endl;
		fout << *group[i] << endl;
		cout << delimiter;
	}
	fout.close();
	system((std::string("start notepad ") + filename).c_str());
	cout << "Количество людей: " << group[0]->get_count() << endl;
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
	cout << "Количество людей: " << Human::get_count() << endl;
#endif // POLYMORPHISM

#ifdef WRITE_TO_FILE
	Human* group[] =
	{
		new Human("Montana",	"Antonio",	25),
		new Student("Pinkman",	"Jessie",	22, "Chemistry",			"WW_220",	95, 99),
		new Teacher("White",	"Walter",	50, "Chemistry",			25),
		new Graduate("Schreder", "Hank",	40, "Criminalistic",		"WW_220",	40, 60, "How to catch Heisenberg"),
		new Student("Vercetty", "Tommy",	30, "Theft",				"Vice",		98, 99),
		new Teacher("Diaz",		"Ricardo",	50, "Weapons disrtibution",	20),
		new Graduate("Targarian", "Daineris", 22, "Flight", "GoT", 91, 92, "How to make smoke"),
		new Teacher("Schwartzenegger", "Arnold", 85, "Heavy Metal", 60)
	};
	Print(group, sizeof(group) / sizeof(group[0]));
	Save(group, sizeof(group) / sizeof(group[0]), filename);
	Clear(group, sizeof(group) / sizeof(group[0]));
#endif // WRITE_TO_FILE

	Human** group = Load(filename);
	Print(group, 8);
}