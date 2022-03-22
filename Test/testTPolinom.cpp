#include "gtest.h"
#include "../Polinom/TPolinom.h"


TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom l);
}

TEST(TPolinom, can_create_copied_polinom)
{
	TPolinom p1;
	ASSERT_NO_THROW(TPolinom p(p1));
}

TEST(TPolinom, copied_polinom_has_its_own_memory)
{
	TPolinom p1;
	TPolinom p2(p1);
	EXPECT_EQ(false, &p1 == &p2);
}

TEST(TPolinom, after_create_polinom_is_empty)
{
	TPolinom p;
	EXPECT_EQ(true, p.isEmpty());
}

TEST(TPolinom, can_add_monom)
{
	TPolinom p;
	p.addMonom(TMonom(2, 2, 2, 2));
	ASSERT_EQ(p.toString(), "2*x^2*y^2*z^2 ");
}

TEST(TPolinom, can_add_up_polinoms1)
{
	TPolinom p1, p2;
	p1.addMonom(TMonom(1, 2, 3, 4));
	p1.addMonom(TMonom(2, 1, 2, 2));
	p1.addMonom(TMonom(2, 3, 3, 3));

	p2.addMonom(TMonom(2, 3, 1, 5));
	p2.addMonom(TMonom(-2, 3, 3, 3));
	p2.addMonom(TMonom(5, 1, 1, 1));
	TPolinom res = p1 + p2;
	ASSERT_EQ(res.toString(), "2*x^3*y^1*z^5 + 1*x^2*y^3*z^4 + 2*x^1*y^2*z^2 + 5*x^1*y^1*z^1 ");
}

TEST(TPolinom, can_add_up_polinoms2)
{
	TPolinom p1, p2;
	p1.addMonom(TMonom(1, 2, 3, 4));
	p1.addMonom(TMonom(2, 1, 2, 2));
	p1.addMonom(TMonom(2, 0, 3, 3));

	p2.addMonom(TMonom(-2, 0, 3, 3));
	p2.addMonom(TMonom(4, 8, 3, 3));
	p2.addMonom(TMonom(5, 1, 1, 1));
	TPolinom res = p1 + p2;
	ASSERT_EQ(res.toString(), "4*x^8*y^3*z^3 + 1*x^2*y^3*z^4 + 2*x^1*y^2*z^2 + 5*x^1*y^1*z^1 ");
}

TEST(TPolinom, can_add_up_polinoms3)
{
	TPolinom p1, p2;
	p1.addMonom(TMonom(-5, 1, 1, 1));
	p1.addMonom(TMonom(2, 1, 2, 2));
	p1.addMonom(TMonom(2, 0, 3, 3));

	p2.addMonom(TMonom(-2, 1, 2, 2));
	p2.addMonom(TMonom(4, 8, 3, 3));
	p2.addMonom(TMonom(5, 1, 1, 1));
	TPolinom res = p1 + p2;
	ASSERT_EQ(res.toString(), "4*x^8*y^3*z^3 + 2*x^0*y^3*z^3 ");
}

TEST(TPolinom, can_add_up_polinoms4)
{
	TPolinom p1, p2;
	p1.addMonom(TMonom(6, 2, 6, 1));
	p1.addMonom(TMonom(2, 1, 2, 2));
	p1.addMonom(TMonom(2, 0, 3, 3));

	p2.addMonom(TMonom(-2, 1, 2, 8));
	p2.addMonom(TMonom(4, 8, 3, 3));
	p2.addMonom(TMonom(5, 1, 1, 1));
	TPolinom res = p1 + p2;
	ASSERT_EQ(res.toString(), "4*x^8*y^3*z^3 + 6*x^2*y^6*z^1 + -2*x^1*y^2*z^8 + 2*x^1*y^2*z^2 + 5*x^1*y^1*z^1 + 2*x^0*y^3*z^3 ");
}

TEST(TPolinom, can_add_up_polinoms5)
{
	TPolinom p1, p2;
	p1.addMonom(TMonom(6, 2, 6, 1));
	p1.addMonom(TMonom(2, 1, 2, 2));
	p1.addMonom(TMonom(2, 0, 3, 3));

	p2.addMonom(TMonom(-6, 2, 6, 1));
	p2.addMonom(TMonom(-2, 1, 2, 2));
	p2.addMonom(TMonom(-2, 0, 3, 3));
	TPolinom res = p1 + p2;
	ASSERT_EQ(res.toString(), "");
}

TEST(TPolinom, can_substact_polinoms)
{
	TPolinom p1, p2;
	p1.addMonom(TMonom(1, 2, 3, 4));
	p2.addMonom(TMonom(3, 2, 3, 4));
	TPolinom res = p1 - p2;
	ASSERT_EQ(res.toString(), "-2*x^2*y^3*z^4 ");
}

TEST(TPolinom, can_muliply_by_const)
{
	TPolinom p1;
	p1.addMonom(TMonom(1, 2, 3, 4));
	TPolinom res = p1 * 3;
	ASSERT_EQ(res.toString(), "3*x^2*y^3*z^4 ");
}

TEST(TPolinom, can_muliply_by_monom)
{
	TPolinom p1;
	p1.addMonom(TMonom(1, 2, 3, 4));
	TMonom m(3, 2, 3, 4);
	TPolinom res = p1 * m;
	ASSERT_EQ(res.toString(), "3*x^4*y^6*z^8 ");
}

TEST(TPolinom, can_muliply_by_polinom)
{
	TPolinom p1, p2;
	p1.addMonom(TMonom(1, 1, 2, 3));
	p1.addMonom(TMonom(2, 2, 3, 4));
	p2.addMonom(TMonom(3, 3, 4, 5));
	p2.addMonom(TMonom(5, 1, 1, 1));
	TPolinom res = p1 * p2;
	ASSERT_EQ(res.toString(), "6*x^5*y^7*z^9 + 3*x^4*y^6*z^8 + 10*x^3*y^4*z^5 + 5*x^2*y^3*z^4 ");
}

TEST(TPolinom, can_compare_polinoms)
{
	TPolinom p1, p2;
	p1.addMonom(TMonom(1, 2, 3, 4));
	p2.addMonom(TMonom(1, 2, 3, 4));
	ASSERT_EQ(true, p1 == p2);
}

TEST(TPolinom, throws_when_create_monom_with_negative_degrees)
{
	ASSERT_ANY_THROW(TMonom m(2, 0, -3, 0));
}