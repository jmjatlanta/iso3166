#include <filesystem>
#include <string>

static std::string dataDir;

void set_data_dir(const std::string& in) { dataDir = in; }

std::filesystem::path get_data_dir()
{
    return std::filesystem::path{dataDir};
}
