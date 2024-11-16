#include <header.hpp>

void saveToFile(const std::string& filename, const std::vector<Book>& data){
    std::ofstream file{std::filesystem::path{filename}};
    for(const auto& book : data) file << book.Author << "\n" << book.Title << "\n" << book.Year << "\n";
}
void loadFromFile(const std::string& filename, std::vector<Book>& outData){
    std::ifstream file{std::filesystem::path{filename}};
    int i = 0;
    Book tmp_book{};
    for(std::string line=""; std::getline(file,line,'\n'); i = (++i % 3)){
        if(i == 0){
            tmp_book = Book{};
            tmp_book.Author = line;
        }
        if(i == 1){
            tmp_book.Title = line;
        }
        if(i == 2){
            tmp_book.Year = std::stod(line);
            outData.push_back(tmp_book);
        }
    }
}