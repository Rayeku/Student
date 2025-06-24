#include "Point.hpp"

float	side(const Point &va, const Point &vb, const Point &point)
{
	float	result = 0;

	result = ((vb.showX() - point.showX()) * (va.showY() - point.showY())) - ((vb.showY() - point.showY()) * (va.showX() - point.showX()));
	return (result);
}

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &point)
{
	float	check_0;
	float	check_1;
	float	check_2;

	check_0 = side(a, b, point);
	check_1 = side(b, c, point);
	check_2 = side(c, a, point);
	return (check_0 > 0 && check_1 > 0 && check_2 > 0) || (check_0 < 0 && check_1 < 0 && check_2 < 0);
}
