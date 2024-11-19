#include <gtest/gtest.h>
#include "iso3166.hpp"

void set_testing_environment(bool in);

TEST(iso3166, basic)
{
    set_testing_environment(true);
    Country c = Country::byName("Afghanistan");
    EXPECT_EQ(c.name, "Afghanistan");
    EXPECT_EQ(c.alpha2, "AF");
    EXPECT_EQ(c.alpha3, "AFG");
    EXPECT_EQ(c.numeric, 4);
}
