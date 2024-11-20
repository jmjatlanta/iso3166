#include "iso3166.hpp"
#include <vector>
#include <filesystem>
#include "file_utils.hpp"
#include "csv.h"

static std::vector<Country> countries;
std::string to_string(const Country& in)
{
    return in.name;
}

bool read_csv(const std::string& fileName)
{
    io::CSVReader<11, io::trim_chars<' ', '\t'>, io::double_quote_escape<',', '\"'>, 
            io::throw_on_overflow, io::no_comment> in(fileName);
    in.read_header(io::ignore_extra_column, "name", "alpha-2", "alpha-3", "country-code", 
            "iso_3166-2", "region", "sub-region", "intermediate-region", 
            "region-code", "sub-region-code", "intermediate-region-code");
    Country row;
    bool retval = false;
    std::string iso_3166_2;
    std::string region;
    std::string sub_region;
    std::string intermediate_region;
    std::string region_code;
    std::string sub_region_code;
    std::string intermediate_region_code;
    while(in.read_row(row.name, row.alpha2, row.alpha3, row.numeric, 
            iso_3166_2, region, sub_region, intermediate_region, 
            region_code, sub_region_code, intermediate_region_code))
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
    std::string lhs = in;
    std::transform(lhs.begin(), lhs.end(), lhs.begin(), ::tolower);
    auto itr = std::find_if(countries.begin(), countries.end(), [&lhs](const Country& curr)
            { 
                std::string rhs = curr.name;
                std::transform(rhs.begin(), rhs.end(), rhs.begin(), ::tolower);
                return lhs == rhs; 
            });
    if (itr == countries.end())
        return Country{};
    return *itr;
}

bool Country::nameExists(const std::string& in)
{
    return byName(in).numeric != std::numeric_limits<uint16_t>::max();
}
