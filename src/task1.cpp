#include <header.hpp>

void saveToFile(const std::string& filename, const std::vector<std::string>& data){
    std::ofstream file{std::filesystem::path{filename}};
    for(const auto& line : data) file << line << " ";
    //The file will be automatically closed when the stream goes out of scope
}
void loadFromFile(const std::string& filename, std::vector<std::string>& outData){
    std::ifstream file{std::filesystem::path{filename}};
    for(std::string word=""; file >> word; outData.push_back(word));
}