#include <gtest/gtest.h>
#include "iso3166.hpp"

void set_data_dir(const std::string& in);

TEST(iso3166, basic)
{
    set_data_dir("./test/test_resources");
    Country c = Country::byName("Afghanistan");
    EXPECT_EQ(c.name, "Afghanistan");
    EXPECT_EQ(c.alpha2, "AF");
    EXPECT_EQ(c.alpha3, "AFG");
    EXPECT_EQ(c.numeric, 4);
}
