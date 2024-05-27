#include "monom.h"
#include "gtest.h"


TEST(polynom, can_create_polynom)
{
	EXPECT_NO_THROW(Polynomial p1;);
}

TEST(polynom, can_create_negative_polynom)
{
	Polynomial p1;
	EXPECT_NO_THROW(p1.addMonom(-1, 321));
}

TEST(polynom, can_added_polynom_no_error)
{
	Polynomial p1;
	p1.addMonom(-1, 321); // add a monom with coefficient 1 and degree 321 (x^3 y^2 z^1)

	Polynomial p2;
	p2.addMonom(4, 345); // add a monom with coefficient 4 and degree 345 (x^3 y^4 z^5)

	EXPECT_NO_THROW(Polynomial p3 = p1 + p2);

}

TEST(polynom, can_mult_polynom_no_error)
{
	Polynomial p1;
	p1.addMonom(-1, 321); // add a monom with coefficient 1 and degree 321 (x^3 y^2 z^1)

	Polynomial p2;
	p2.addMonom(4, 345); // add a monom with coefficient 4 and degree 345 (x^3 y^4 z^5)

	EXPECT_NO_THROW(Polynomial p3 = p1 * p2);

}

TEST(polynom, cant_mult_polynom_large_degrees)
{
	Polynomial p1;
	p1.addMonom(-8, 520); // add a monom with coefficient -8 and degree 321 (x^5 y^2 z^0)

	Polynomial p2;
	p2.addMonom(-4, 485); // add a monom with coefficient -4 and degree 345 (x^4 y^8 z^5)

	EXPECT_ANY_THROW(Polynomial p3 = p1 * p2);

}

TEST(polynom, can_mult_polynom_with_const_no_error)
{
	Polynomial p1;
	p1.addMonom(9, 321); // add a monom with coefficient 1 and degree 321 (x^3 y^2 z^1)


	EXPECT_NO_THROW(Polynomial p3 = p1 * 12);

}

TEST(polynom, can_subtract_polynom_no_error)
{
	Polynomial p1;
	p1.addMonom(-1, 321); // add a monom with coefficient 1 and degree 321 (x^3 y^2 z^1)

	Polynomial p2;
	p2.addMonom(4, 345); // add a monom with coefficient 4 and degree 345 (x^3 y^4 z^5)

	EXPECT_NO_THROW(Polynomial p3 = p1 - p2);

}