#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace common {
    std::vector<std::string> read_file(std::string file_name);
    std::vector<std::string> read_file_qt(std::string file_name);
};
