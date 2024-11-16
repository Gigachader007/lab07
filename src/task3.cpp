#include <header.hpp>

void saveToFile(const std::string& filename, const Groups& groups){
    std::ofstream file{std::filesystem::path{filename}};
    for(auto [name, students] : groups){
        file << name << " " << students.size() << std::endl;
        for(const auto& student : students){
            file << student.Name << " " << student.Year << " " << student.RecordBook.size() << " ";
            for(auto [subj_name, mark] : student.RecordBook){
                file << subj_name << " " << mark << " ";
            }
            file << std::endl;
        }
    }
}
void loadFromFile(const std::string& filename, Groups& outGroups){
    std::ifstream file{std::filesystem::path{filename}};
    std::string group_name = "";
    std::size_t count = 0;
    while (file >> group_name >> count)
    {
        std::vector<Student> students(count);
        for(auto& student : students){
            std::size_t subcount = 0;
            file >> student.Name >> student.Year >> subcount;
            for(auto i = 0; i < subcount; ++i){
                std::string subj_name;
                int mark;
                file >> subj_name >> mark;
                student.RecordBook.insert({subj_name,(Score)mark});
            }
        }
        outGroups.insert({group_name,students});
    }
}