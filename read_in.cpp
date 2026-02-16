#include <iostream> 
#include <fstream>
#include <string> 
#include <nlohmann/json.hpp> 
using json = nlohmann::json; 



int main(){
    std:: string file_path = "tags.json"; 
    std::ifstream i(file_path); 
    if (!i.is_open()) {
        std::cerr<< "Could not open file: " << file_path << std::endl; 
        return 1; 
    }
    json j; 
    try {
        i>> j; 
    } catch (json::parse_error& e){
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        return 1;
    }
    if (j.is_null()) {
        std::cerr << "JSON is null" << std::endl; 
        return 1;  

    }
    std::cout << "JSON loaded successfully: " << std::endl; 
    std:: cout << j.dump(4) << std::endl; 
return 0; 
}



