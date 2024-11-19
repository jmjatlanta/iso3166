#include <filesystem>

static bool TESTING_ENV = false;

void set_testing_environment(bool in) { TESTING_ENV = in; }

std::filesystem::path get_data_dir()
{
    if (TESTING_ENV)
        return std::filesystem::path{"/Users/jmjatlanta/Development/cpp/iso3166/test/test_resources"};
    else
        return std::filesystem::path{"."};
}
