#include "Point.hpp"

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &point);

int	main(void)
{
	// Point test3;
	// Point test(8,2);
	// Point test2(test);
	// Point test1 = test;

	// std::cout << test1.showX() << std::endl;
	// std::cout << test1.showY() << std::endl;
	// std::cout << test2.showX() << std::endl;
	// std::cout << test2.showY() << std::endl;
	// std::cout << test3.showX() << std::endl;
	// std::cout << test3.showY() << std::endl;

	Point a(0,0);
	Point b(2,2);
	Point c(4,0);
	Point p(2,1);
	bool inside1 = bsp(a, b, c, p);
	std::cout << "Is point inside the triangle? " << (inside1 ? "Yes" : "No") << std::endl;

	// Point e(0,0);
	// Point f(2,2);
	// Point g(4,0);
	// Point h(40,40);
	// bool inside2 = bsp(e, f, g, h);
	// std::cout << "Is point inside the triangle? " << (inside2 ? "Yes" : "No") << std::endl;

	// Point i(0,0);
	// Point j(2,2);
	// Point k(4,0);
	// Point l(8,8);
	// bool inside3 = bsp(i, j, k, l);
	// std::cout << "Is point inside the triangle? " << (inside3 ? "Yes" : "No") << std::endl;

	return (0);
}