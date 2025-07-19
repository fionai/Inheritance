#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	// 1. Создаем поток
	std::ofstream fout;

	//2. Открываем поток
	fout.open("File.txt", std::fstream::app);

	//3. Пишем в поток
	fout << "Hello, Files!\n";

	//4. Потоки как холодильник, если он был открыт, его надо закрыть
	fout.close();

	system("notepad File.txt"); //сразу открывает  
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE	
	//1. Сшздаем и открываем поток
	std::ifstream fin("File.txt");

	//2.проверяем, открылся ли поток
	if (fin.is_open())
	{
		while (!fin.eof()) // eof() - end of file
		{
			const int SIZE = 256;
			char sz_buffer[SIZE] = {};
			//fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}

#endif // READ_FROM_FILE


}