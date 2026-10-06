#include "optional.h"

#ifdef PPC_USE_BOOST_TEST
# include <boost/test/unit_test.hpp>
# ifndef __clang__
// Vermeiden der boost::unit_test::ut__detail::nil_t Warnung
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Weffc++"
# endif
#endif

#ifdef USE_GTEST
# include <gtest/gtest.h>
#endif

#ifdef USE_SIMPLETEST
# include "../lib/simpletest.h"
#endif

class Test
{
public:
    Test(int v = 0) : mValue(v)
    {
        TRACE;
    }
    int mValue;
};

bool operator==(const Test& lhs, const Test& rhs)
{
    TRACE;
    return lhs.mValue == rhs.mValue;
}

#ifdef USE_GTEST
TEST(Optional, Initialize1)
{
    Optional<int> x1;
    EXPECT_FALSE(x1);
    
    Optional<int> x2(1);
    EXPECT_TRUE(x2);
    EXPECT_EQ(1, x2);
    EXPECT_EQ(1, *x2);
}

TEST(Optional, Ctor2)
{
    Optional<Test> x1;
    BOOST_CHECK(!x1);
    
    trace() << "A";
    Optional<Test> x2(1);
    Test x3(1);
    trace() << "B";
    BOOST_CHECK(x2);
    trace() << "C";
    BOOST_CHECK(x2 == x3);
    // nicht moeglich, weil bei Instanziierung eines Templates
    // keine implizite Typwandlung ausgefuehrt wird.
    //    BOOST_CHECK(x2 == 1);
    
}

#endif

#ifdef PPC_USE_BOOST_TEST

BOOST_AUTO_TEST_SUITE(OptionalTestSuite)

BOOST_AUTO_TEST_CASE(Ctor)
{
    Optional<int> x1;
    BOOST_CHECK(!x1);
    
    Optional<int> x2(1);
    BOOST_CHECK(x2);
    BOOST_CHECK(1 == x2);
    BOOST_CHECK(1 == *x2);
}

BOOST_AUTO_TEST_CASE(Ctor2)
{
    Optional<Test> x1;
    BOOST_CHECK(!x1);
    
    trace() << "A";
    Optional<Test> x2(1);
    Test x3(1);
    trace() << "B";
    BOOST_CHECK(x2);
    trace() << "C";
    BOOST_CHECK(x2 == x3);
    // nicht moeglich, weil bei Instanziierung eines Templates
    // keine implizite Typwandlung ausgefuehrt wird.
    //    BOOST_CHECK(x2 == 1);
    
}

BOOST_AUTO_TEST_SUITE_END()

// ab hier wieder mit den globalen Einstellungen compilieren
# ifndef __clang__
#  pragma GCC diagnostic pop
# endif

#endif
