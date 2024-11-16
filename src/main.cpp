#include <header.hpp>
#include <iostream>
#include <sstream>

int main(){
    std::string song_text = // Starship - We Built This City
R"( 
We built this city
We built this city on rock and roll
Built this city
We built this city on rock and roll
Say you don't know me or recognize my face
Say you don't care who goes to that kind of place
Knee deep in the hoopla, sinking in your fight
Too many runaways eating up the night
Marconi plays the mamba, listen to the radio, don't you remember?
We built this city, we built this city on rock and roll
We built this city, we built this city on rock and roll
Built this city, we built this city on rock and roll
Someone's always playing corporation games
Who cares, they're always changing corporation names
We just want to dance here, someone stole the stage
They call us irresponsible, write us off the page
)";

    std::stringstream ss(song_text);
    std::vector<std::string> words{};
    for(std::string word = ""; ss >> word; words.push_back(word));

    std::string filename = "./my_file.txt";
    saveToFile(filename,words);
    words.clear();
    loadFromFile(filename,words);
    for(auto& word : words){
        std::cout << word << " ";
    }

    std::vector<Book> books = {{"Лев Николаевич Толстой", "Война и мир", 1867},{"Николай Васильевич Гоголь", "Мёртвые души", 1842}};
    saveToFile("./books.txt",books);
    books.clear();
    loadFromFile("./books.txt",books);
    std::cout << std::endl << std::endl;
    for(auto& book : books){
        std::cout << book.Author << " - " << book.Title << " - " << book.Year << std::endl;
    }
    
    {
        std::ofstream file("./test.txt");
        std::string tmp = 
R"(
Группа0 2
Николай 2006 3 Ангем 5 Инжграф 4 Матан 5
Андрей 2006 2 Матан 5 Ангем 4
Группа1 1
Олег 2007 1 Матан 5        
)";
        file << tmp;
    }

    Groups grps;
    loadFromFile("./test.txt",grps);
    saveToFile("./test2.txt",grps);
}