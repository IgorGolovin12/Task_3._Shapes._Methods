#include <iostream>
#include <string>
#include <windows.h>

class Figure
{
protected:
	int sides_count_ = 0;
	std::string name_ = "Фигура";
	int side_a_;
	int side_b_;
	int side_c_;
	int side_d_;
	int corner_A_;
	int corner_B_;
	int corner_C_;
	int corner_D_;
public:
	Figure() {}
	Figure(int sides, std::string name)
	{
		sides_count_ = sides;
		name_ = name;
	}
	int get_sides_count() {	return sides_count_; }
	std::string get_sides_name() {	return name_; }
	int get_side_a_() { return side_a_; }
	int get_side_b_() { return side_b_; }
	int get_side_c_() { return side_c_; }
	int get_side_d_() { return side_d_; }
	int get_corner_A_() { return corner_A_; }
	int get_corner_B_() { return corner_B_; }
	int get_corner_C_() { return corner_C_; }
	int get_corner_D_() { return corner_D_; }
	virtual bool check()
	{
		if (sides_count_ == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		if (check())
		{
			std::cout << "Правильная" << std::endl;
		}
		else
		{
			std::cout << "Неправильная" << std::endl;
		}		
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << std::endl;

	}
};

class Triangele :  public Figure
{
public:
	Triangele() {}
	Triangele(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C) 
	{
		name_ = "Треугольник";
		sides_count_ = 3;
		side_a_ = side_a;
		side_b_ = side_b;
		side_c_ = side_c;
		corner_A_ = corner_A;
		corner_B_ = corner_B;
		corner_C_ = corner_C;
	}
	virtual bool check()
	{
		if ((sides_count_ == 3) && (corner_A_+corner_B_+corner_C_ == 180))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		if (check())
		{
			std::cout << "Правильная" << std::endl;
		}
		else
		{
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << get_side_a_() << " b=" << get_side_b_() << " c=" << get_side_c_() << std::endl;
		std::cout << "Углы: " << "A=" << get_corner_A_() << " B=" << get_corner_B_() << " C=" << get_corner_C_() << std::endl;
		std::cout << std::endl;
	}
};

class RightTriangle : public Triangele
{
public:
	RightTriangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
	{
		name_ = "Прямоугольный треугольник";
		sides_count_ = 3;
		side_a_ = side_a;
		side_b_ = side_b;
		side_c_ = side_c;
		corner_A_ = corner_A;
		corner_B_ = corner_B;
		corner_C_ = corner_C;
	}
	virtual bool check()
	{
		if (corner_C_ == 90)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		if (check())
		{
			std::cout << "Правильная" << std::endl;
		}
		else
		{
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << get_side_a_() << " b=" << get_side_b_() << " c=" << get_side_c_() << std::endl;
		std::cout << "Углы: " << "A=" << get_corner_A_() << " B=" << get_corner_B_() << " C=" << get_corner_C_() << std::endl;
		std::cout << std::endl;
	}
};

class IsoscelesTriangle : public Triangele
{
public:
	IsoscelesTriangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
	{
		name_ = "Равнобедренный треугольник";
		sides_count_ = 3;
		side_a_ = side_a;
		side_b_ = side_b;
		side_c_ = side_c;
		corner_A_ = corner_A;
		corner_B_ = corner_B;
		corner_C_ = corner_C;
	}
	virtual bool check()
	{
		if ((side_a_ == side_c_) && (corner_A_ == corner_C_))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		if (check())
		{
			std::cout << "Правильная" << std::endl;
		}
		else
		{
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << get_side_a_() << " b=" << get_side_b_() << " c=" << get_side_c_() << std::endl;
		std::cout << "Углы: " << "A=" << get_corner_A_() << " B=" << get_corner_B_() << " C=" << get_corner_C_() << std::endl;
		std::cout << std::endl;
	}
};

class EquilateralTriangle : public Triangele
{
public:
	EquilateralTriangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
	{
		name_ = "Равносторонний треугольник";
		sides_count_ = 3;
		side_a_ = side_a;
		side_b_ = side_b;
		side_c_ = side_c;
		corner_A_ = corner_A;
		corner_B_ = corner_B;
		corner_C_ = corner_C;
	}
	virtual bool check()
	{
		if ((side_a_ == side_b_) && (side_b_ == side_c_) && (corner_A_ == corner_B_) && (corner_B_ == corner_C_) && corner_A_ == 60)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		if (check())
		{
			std::cout << "Правильная" << std::endl;
		}
		else
		{
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << get_side_a_() << " b=" << get_side_b_() << " c=" << get_side_c_() << std::endl;
		std::cout << "Углы: " << "A=" << get_corner_A_() << " B=" << get_corner_B_() << " C=" << get_corner_C_() << std::endl;
		std::cout << std::endl;
	}
};

class Quadrilateral : public Figure
{
public:
	Quadrilateral() {}
	Quadrilateral(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
	{
		name_ = "Четырехугольник";
		sides_count_ = 4;
		side_a_ = side_a;
		side_b_ = side_b;
		side_c_ = side_c;
		side_d_ = side_d;
		corner_A_ = corner_A;
		corner_B_ = corner_B;
		corner_C_ = corner_C;
		corner_D_ = corner_D;
	}
	virtual bool check()
	{
		if ((sides_count_ == 4) && (corner_A_ + corner_B_ + corner_C_ + corner_D_ == 360))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		if (check())
		{
			std::cout << "Правильная" << std::endl;
		}
		else
		{
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << get_side_a_() << " b=" << get_side_b_() << " c=" << get_side_c_() << " d=" << get_side_d_() << std::endl;
		std::cout << "Углы: " << "A=" << get_corner_A_() << " B=" << get_corner_B_() << " C=" << get_corner_C_() << " D=" << get_corner_D_() << std::endl;
		std::cout << std::endl;
	}
};

class Rectangle_A : public Quadrilateral
{
public:
	Rectangle_A(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
	{
		name_ = "Прямоугольник";
		sides_count_ = 4;
		side_a_ = side_a;
		side_b_ = side_b;
		side_c_ = side_c;
		side_d_ = side_d;
		corner_A_ = corner_A;
		corner_B_ = corner_B;
		corner_C_ = corner_C;
		corner_D_ = corner_D;
	}
	virtual bool check()
	{
		if ((side_a_ == side_c_) && (side_b_ == side_d_) && (corner_A_ == corner_B_) && (corner_B_ == corner_C_) && (corner_C_ == corner_D_) && corner_A_ == 90)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		if (check())
		{
			std::cout << "Правильная" << std::endl;
		}
		else
		{
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << get_side_a_() << " b=" << get_side_b_() << " c=" << get_side_c_() << " d=" << get_side_d_() << std::endl;
		std::cout << "Углы: " << "A=" << get_corner_A_() << " B=" << get_corner_B_() << " C=" << get_corner_C_() << " D=" << get_corner_D_() << std::endl;
		std::cout << std::endl;
	}
};

class Square : public Quadrilateral
{
public:
	Square(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
	{
		name_ = "Квадрат";
		sides_count_ = 4;
		side_a_ = side_a;
		side_b_ = side_b;
		side_c_ = side_c;
		side_d_ = side_d;
		corner_A_ = corner_A;
		corner_B_ = corner_B;
		corner_C_ = corner_C;
		corner_D_ = corner_D;
	}
	virtual bool check()
	{
		if ((side_a_ == side_c_) && (side_c_ == side_b_) && (side_b_ == side_d_) && (corner_A_ == corner_B_) && (corner_B_ == corner_C_) && (corner_C_ == corner_D_) && corner_A_ == 90)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		if (check())
		{
			std::cout << "Правильная" << std::endl;
		}
		else
		{
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << get_side_a_() << " b=" << get_side_b_() << " c=" << get_side_c_() << " d=" << get_side_d_() << std::endl;
		std::cout << "Углы: " << "A=" << get_corner_A_() << " B=" << get_corner_B_() << " C=" << get_corner_C_() << " D=" << get_corner_D_() << std::endl;
		std::cout << std::endl;
	}
};

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
	{
		name_ = "Параллелограмм";
		sides_count_ = 4;
		side_a_ = side_a;
		side_b_ = side_b;
		side_c_ = side_c;
		side_d_ = side_d;
		corner_A_ = corner_A;
		corner_B_ = corner_B;
		corner_C_ = corner_C;
		corner_D_ = corner_D;
	}
	virtual bool check()
	{
		if ((side_a_ == side_c_) && (side_b_ == side_d_) && (corner_A_ == corner_C_) && (corner_B_ == corner_D_))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		if (check())
		{
			std::cout << "Правильная" << std::endl;
		}
		else
		{
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << get_side_a_() << " b=" << get_side_b_() << " c=" << get_side_c_() << " d=" << get_side_d_() << std::endl;
		std::cout << "Углы: " << "A=" << get_corner_A_() << " B=" << get_corner_B_() << " C=" << get_corner_C_() << " D=" << get_corner_D_() << std::endl;
		std::cout << std::endl;
	}
};

class Rhomb : public Quadrilateral
{
public:
	Rhomb(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
	{
		name_ = "Ромб";
		sides_count_ = 4;
		side_a_ = side_a;
		side_b_ = side_b;
		side_c_ = side_c;
		side_d_ = side_d;
		corner_A_ = corner_A;
		corner_B_ = corner_B;
		corner_C_ = corner_C;
		corner_D_ = corner_D;
	}
	virtual bool check()
	{
		if ((side_a_ == side_c_) && (side_c_ == side_b_) && (side_b_ == side_d_) && (corner_A_ == corner_C_) && (corner_B_ == corner_D_))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual void print_info()
	{
		std::cout << get_sides_name() << ":" << std::endl;
		if (check())
		{
			std::cout << "Правильная" << std::endl;
		}
		else
		{
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << get_side_a_() << " b=" << get_side_b_() << " c=" << get_side_c_() << " d=" << get_side_d_() << std::endl;
		std::cout << "Углы: " << "A=" << get_corner_A_() << " B=" << get_corner_B_() << " C=" << get_corner_C_() << " D=" << get_corner_D_() << std::endl;
		std::cout << std::endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Figure F;
	Triangele T (10, 20, 30, 50, 60, 70);
	RightTriangle RT (10, 20, 30, 50, 60, 90);
	IsoscelesTriangle IT (10, 20, 10, 50, 60, 50);
	EquilateralTriangle ET (30, 30, 30, 60, 60, 60);
	Quadrilateral Q (10, 20, 30, 40, 50, 60, 70, 80);
	Rectangle_A RA (10, 20, 10, 20, 90, 90, 90, 90);
	Square S(20, 20, 20, 20, 90, 90, 90, 90);
	Parallelogram P(20, 30, 20, 30, 30, 40, 30, 40);
	Rhomb R(30, 30, 30, 30, 30, 40, 30, 40);
	Figure* ptr_F = &F;
	ptr_F->print_info();
	ptr_F = &T;
	ptr_F->print_info();
	ptr_F = &RT;
	ptr_F->print_info();
	ptr_F = &IT;
	ptr_F->print_info();
	ptr_F = &ET;
	ptr_F->print_info();
	ptr_F = &Q;
	ptr_F->print_info();
	ptr_F = &RA;
	ptr_F->print_info();
	ptr_F = &S;
	ptr_F->print_info();
	ptr_F = &P;
	ptr_F->print_info();
	ptr_F = &R;
	ptr_F->print_info();
	return EXIT_SUCCESS;
}