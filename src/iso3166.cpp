#include "iso3166.hpp"
#include <vector>
#include <filesystem>
#include "csv.h"

static std::vector<Country> countries;
std::string to_string(const Country& in)
{
    return in.name;
}

std::filesystem::path get_data_dir()
{
    return std::filesystem::path{"."};
}

bool read_csv(const std::string& fileName)
{
    io::CSVReader<4, io::trim_chars<' ', '\t'>, io::double_quote_escape<',', '\"'>, io::throw_on_overflow, io::no_comment> in(fileName);
    in.read_header(io::ignore_extra_column, "Country", "Alpha-2 code", "Alpha-3 code", "Numeric");
    Country row;
    bool retval = false;
    while(in.read_row(row.name, row.alpha2, row.alpha3, row.numeric))
    {
        retval = true;
        countries.push_back(row);
    }
    return retval;
}

bool initialize()
{
    if (countries.size() == 0)
    {
        std::filesystem::path dataDir = get_data_dir();
        dataDir /= "iso3166.csv";
        if (std::filesystem::exists(dataDir))
        {
            return read_csv(dataDir);
        }
        return false;
    }
    return true;
}

void Country::reset()
{
    countries.clear();
}

Country Country::byName(const std::string& in)
{
    initialize();
    auto itr = std::find_if(countries.begin(), countries.end(), [&in](const Country& curr)
            { return curr.name == in; });
    if (itr == countries.end())
        return Country{};
    return *itr;
}
