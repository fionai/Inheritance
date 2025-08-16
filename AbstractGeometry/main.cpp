#include <iostream>
using namespace std;
#include<Windows.h>

namespace Geometry
{
	enum Color //Enumeration
	{
		Red = 0x000000FF,
		Green = 0x0000FF00,
		Blue = 0x00FF0000,
		Yellow = 0x0000FFFF,
		Violet = 0x00FF00FF
	};

	class Shape
	{
		Color color; //���� ������
	public:
		void set_color(Color color)
		{
			this->color = color;
		}
		Color get_color() const
		{
			return color;
		}
		virtual double get_area()const = 0;
		virtual double get_perimeter() const = 0;
		virtual void draw() const = 0;
		Shape(Color color) : color(color) {}
		virtual void info() const
		{
			cout << "������� ������: " << get_area() << endl;
			cout << "�������� ��������: " << get_perimeter() << endl;
			draw();
		}

	};
	class Square : public Shape
	{
		double side;
	public:
		void set_side(double side)
		{
			this->side = side;
		}
		double get_side() const
		{
			return side;
		}
		double get_area() const override
		{
			return side * side;
		}
		double get_perimeter()const override
		{
			return side * 4;
		}
		void draw() const override
		{
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
		}
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		void info() const override
		{
			cout << typeid(*this).name() << endl;
			cout << "������� ��������: " << get_side() << endl;
			Shape::info();

		}
	};

	class Rectangle :public Shape
	{
		double side_1;
		double side_2;
	public:
		void set_side_1(double side_1)
		{
			this->side_1 = side_1;
		}
		void set_side_2(double side_2)
		{
			this->side_2 = side_2;
		}
		double get_side_1() const
		{
			return side_1;
		}
		double get_side_2() const
		{
			return side_2;
		}
		double get_area() const override
		{
			return side_1 * side_2;
		}
		double get_perimeter() const override
		{
			return (side_1 + side_2) * 2;
		}
		void draw() const override
		{
			//cout << "������������� " << endl;
			//�������� ���� �������
			HWND hwnd = GetConsoleWindow();
			//�������� �������� ���������� ����������� ����
			HDC hdc = GetDC(hwnd); //�������� ���������� (DeviceContext) - ��, �� ��� �� ����� ��������
			//��� �� ����� ��������
			HPEN hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0)); //Pen ������ ������ ������
			//PS_SOLID - �������� �����
			// 1 - ������� ����� 1 �������
			//RGB - ����� �������� �����

			//������� �����, ������� ��������� ������� ������:
			HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));

			//��������, ��� � �� ��� ����� ��������
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//�������� ������ �-�� ��� ���������
			::Rectangle(hdc, 200, 100, 500, 500);

			//������� ��������, ��������� �� ���� ������� �������
			DeleteObject(hPen);
			DeleteObject(hBrush);

			//�������� ���������� �������� �������, ������� ����� ����������:
			ReleaseDC(hwnd, hdc);

		}
		Rectangle(double side_1, double side_2, Color color) :Shape(color)
		{
			set_side_1(side_1);
			set_side_2(side_2);
		}
		void info() const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Side 1: " << get_side_1() << endl;
			cout << "Side 2: " << get_side_2() << endl;
			Shape::info();
		}

	};

}

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::Blue);
	Geometry:: Square square(5, Geometry::Color::Red);
	square.info(); 
	Geometry::Rectangle rectangle(20, 15, Geometry::Color::Red);
	rectangle.info();
}