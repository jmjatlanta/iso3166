#pragma once
#include <string>
#include <cstdint>
#include <limits>

class Country
{
public:
    std::string name;
    std::string alpha2;
    std::string alpha3;
    uint16_t numeric = std::numeric_limits<uint16_t>::max();

    static Country byName(const std::string& in);
    static Country byAlpha2(const std::string& in);
    static Country byAlpha3(const std::string& in);
    static Country byNumeric(uint16_t in);

    /***
     * Reset internal structures and re-read tables
     */
    static void reset();
};

std::string to_string(const Country& in);
