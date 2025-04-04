#include <fstream>
#include <string>
#include <vector>

class PersistenceManager {
public:
    static void saveData(const std::string &filename, const std::vector<std::string> &data) {
        std::ofstream file(filename);
        if (!file) throw std::runtime_error("Failed to open file for writing.");
        for (const auto &line : data) file << line << "\n";
    }

    static std::vector<std::string> loadData(const std::string &filename) {
        std::ifstream file(filename);
        if (!file) throw std::runtime_error("Failed to open file for reading.");
        std::vector<std::string> data;
        std::string line;
        while (std::getline(file, line)) data.push_back(line);
        return data;
    }
};
