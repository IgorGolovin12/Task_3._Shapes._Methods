#include <iostream>
#include <string>
#include <windows.h>

class Figure
{
protected:
	int sides_count_ = 0;
	std::string name_ = "Фигура";
	int side_a_ = 0;
	int side_b_ = 0;
	int side_c_ = 0;
	int side_d_ = 0;
	int corner_A_ = 0;
	int corner_B_ = 0;
	int corner_C_ = 0;
	int corner_D_ = 0;
public:
	int get_sides_count()
	{
		return sides_count_;
	}
	std::string get_sides_name()
	{
		return name_;
	}
	virtual std::string check()
	{
		if (sides_count_ == 0)
		{
			return "Правильная";
		}
		else
		{
			return "Неправильная";
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		std::cout << check() << std::endl;
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << std::endl;
		
    }

class Triangele :  public Figure
{
public:
	Triangele(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C) 
	{
		name_ = "Треугольник";
		side_counter = 3;
		side_a_ = side_a;
		side_b_ = side_b;
		side_c_ = side_c;
		corner_A_ = corner_A;
		corner_B_ = corner_B;
		corner_C_ = corner_C;
	}
	virtual std::string check()
	{
		if (sides_count_ == 3 && corner_A_+corner_B_+corner_C_ == 180)
		{
			return "Правильная";
		}
		else
		{
			return "Неправильная";
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		std::cout << check() << std::endl;
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << side_a_ << " b=" << side_b_ << " c=" << side_c_ << std::endl;
		std::cout << "Углы: " << "A=" << corner_A_ << " B=" << corner_B_ << " C=" << corner_C_ << std::endl;
		std::cout << std::endl;
	}
};

class RightTriangle : public Triangele
{
public:
	RightTriangle(int side_a, int side_b, int side_c, int corner_A, int corner_B)
	{
		name_ = "Прямоугольный треугольник";
		side_a_ = side_a;
		side_b_ = side_b;
		side_c_ = side_c;
		corner_A_ = corner_A;
		corner_B_ = corner_B;
		corner_C_ = 90;
	}
	virtual std::string check()
	{
		if (corner_C_ == 90)
		{
			return "Правильная";
		}
		else
		{
			return "Неправильная";
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		std::cout << check() << std::endl;
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << side_a_ << " b=" << side_b_ << " c=" << side_c_ << std::endl;
		std::cout << "Углы: " << "A=" << corner_A_ << " B=" << corner_B_ << " C=" << corner_C_ << std::endl;
		std::cout << std::endl;
	}
};

class IsoscelesTriangle : public Triangele
{
public:
	IsoscelesTriangle(int side_a, int side_b, int corner_A, int corner_B)
	{
		name_ = "Равнобедренный треугольник";
		side_a_ = side_c_ = side_a;
		side_b_ = side_b;
		corner_A_ = corner_C_ = corner_A;
		corner_B_ = corner_B;
	}
	virtual std::string check()
	{
		if (side_a_ == side_c_ && corner_A_ == corner_C_)
		{
			return "Правильная";
		}
		else
		{
			return "Неправильная";
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		std::cout << check() << std::endl;
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << side_a_ << " b=" << side_b_ << " c=" << side_c_ << std::endl;
		std::cout << "Углы: " << "A=" << corner_A_ << " B=" << corner_B_ << " C=" << corner_C_ << std::endl;
		std::cout << std::endl;
	}
};

class EquilateralTriangle : public Triangele
{
public:
	EquilateralTriangle(int side_a)
	{
		name_ = "Равносторонний треугольник";
		side_a_ = side_b_ = side_c_ = side_a;
		corner_A_ = corner_B_ = corner_C_ = 60;
	}
	virtual std::string check()
	{
		if (side_a_ == side_b_ == side_c_ && corner_A_ == corner_B_ == corner_C_ == 60)
		{
			return "Правильная";
		}
		else
		{
			return "Неправильная";
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		std::cout << check() << std::endl;
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << side_a_ << " b=" << side_b_ << " c=" << side_c_ << std::endl;
		std::cout << "Углы: " << "A=" << corner_A_ << " B=" << corner_B_ << " C=" << corner_C_ << std::endl;
		std::cout << std::endl;
	}
};

class Quadrilateral : public Figure
{
public:
	Quadrilateral() : Figure(4, "Четырехугольник") {}
	Quadrilateral(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D) : Figure(4, "Четырехугольник")
	{
		side_a_ = side_a;
		side_b_ = side_b;
		side_c_ = side_c;
		side_d_ = side_d;
		corner_A_ = corner_A;
		corner_B_ = corner_B;
		corner_C_ = corner_C;
		corner_D_ = corner_D;
	}
	virtual std::string check()
	{
		if (sides_count_ == 4 && corner_A_ + corner_B_ + corner_C_ + corner_D_ == 360)
		{
			return "Правильная";
		}
		else
		{
			return "Неправильная";
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		std::cout << check() << std::endl;
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << side_a_ << " b=" << side_b_ << " c=" << side_c_ << " d=" << side_d_ << std::endl;
		std::cout << "Углы: " << "A=" << corner_A_ << " B=" << corner_B_ << " C=" << corner_C_ << " D=" << corner_D_ << std::endl;
		std::cout << std::endl;
	}
};

class Rectangle_A : public Quadrilateral
{
public:
	Rectangle_A(int side_a, int side_b)
	{
		name_ = "Прямоугольник";
		side_a_ = side_c_ = side_a;
		side_b_ = side_d_ = side_b;
		corner_A_ = corner_B_ = corner_C_ = corner_D_ = 90;
	}
	virtual std::string check()
	{
		if (side_a_ == side_c_ && side_b_ == side_d_ && corner_A_ == corner_B_ ==  corner_C_ == corner_D_ == 90)
		{
			return "Правильная";
		}
		else
		{
			return "Неправильная";
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		std::cout << check() << std::endl;
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << side_a_ << " b=" << side_b_ << " c=" << side_c_ << " d=" << side_d_ << std::endl;
		std::cout << "Углы: " << "A=" << corner_A_ << " B=" << corner_B_ << " C=" << corner_C_ << " D=" << corner_D_ << std::endl;
		std::cout << std::endl;
	}
};

class Square : public Quadrilateral
{
public:
	Square(int side_a)
	{
		name_ = "Квадрат";
		side_a_ = side_c_ = side_b_ = side_d_ = side_a;
		corner_A_ = corner_B_ = corner_C_ = corner_D_ = 90;
	}
	virtual std::string check()
	{
		if (side_a_ == side_c_ == side_b_ == side_d_ && corner_A_ == corner_B_ == corner_C_ == corner_D_ == 90)
		{
			return "Правильная";
		}
		else
		{
			return "Неправильная";
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		std::cout << check() << std::endl;
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << side_a_ << " b=" << side_b_ << " c=" << side_c_ << " d=" << side_d_ << std::endl;
		std::cout << "Углы: " << "A=" << corner_A_ << " B=" << corner_B_ << " C=" << corner_C_ << " D=" << corner_D_ << std::endl;
		std::cout << std::endl;
	}
};

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(int side_a, int side_b, int corner_A, int corner_B)
	{
		name_ = "Параллелограмм";
		side_a_ = side_c_ = side_a;
		side_b_ = side_d_ = side_b;
		corner_A_ = corner_C_ = corner_A;
		corner_B_ = corner_D_ = corner_B;
	}
	virtual std::string check()
	{
		if (side_a_ == side_c_ && side_b_ == side_d_ && corner_A_ == corner_C_ && corner_B_ == corner_D_)
		{
			return "Правильная";
		}
		else
		{
			return "Неправильная";
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		std::cout << check() << std::endl;
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << side_a_ << " b=" << side_b_ << " c=" << side_c_ << " d=" << side_d_ << std::endl;
		std::cout << "Углы: " << "A=" << corner_A_ << " B=" << corner_B_ << " C=" << corner_C_ << " D=" << corner_D_ << std::endl;
		std::cout << std::endl;
	}
};

class Rhomb : public Quadrilateral
{
public:
	Rhomb(int side_a, int corner_A, int corner_B)
	{
		name_ = "Ромб";
		side_a_ = side_c_ = side_b_ = side_d_ = side_a;
		corner_A_ = corner_C_ = corner_A;
		corner_B_ = corner_D_ = corner_B;
	}
	virtual std::string check()
	{
		if (side_a_ == side_c_ == side_b_ == side_d_ && corner_A_ == corner_C_ && corner_B_ == corner_D_)
		{
			return "Правильная";
		}
		else
		{
			return "Неправильная";
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		std::cout << check() << std::endl;
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << side_a_ << " b=" << side_b_ << " c=" << side_c_ << " d=" << side_d_ << std::endl;
		std::cout << "Углы: " << "A=" << corner_A_ << " B=" << corner_B_ << " C=" << corner_C_ << " D=" << corner_D_ << std::endl;
		std::cout << std::endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Figure F;
	Figure* ptr_F = &F;
	ptr_F->print_info();
	return EXIT_SUCCESS;
}