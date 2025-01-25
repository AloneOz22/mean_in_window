#include <random>
#include <iostream>
#include <sstream>
#include <mean_in_window.hpp>


template <class T>
std::vector<T> get_input_vector(std::size_t size){
    std::random_device device;
    std::mt19937 engine {device()};
    std::uniform_real_distribution<T> distribution {0, 10};
    auto gen = [&](){ return distribution(engine); };
    std::vector<T> result(size);
    std::generate(result.begin(), result.end(), gen);
    return result;
}

int main(int argc, char** argv){
    
    std::size_t data_size;
    std::size_t window_size;
    if (argc == 3){
        std::istringstream data_size_stream(argv[1]);
        std::istringstream window_size_stream(argv[2]);
        data_size_stream >> data_size;
        window_size_stream >> window_size;
        if (data_size_stream.fail() || window_size_stream.fail()) {
            std::cerr << "Incorrect input sizes!\n";
            return 1;
        }
    }
    else {
        data_size = 5;
        window_size = 2;
    }
    
    const std::vector<float> data = get_input_vector<float>(data_size);

    std::cout << "Input vector values: ";    
    for (const auto& value : data){
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    std::vector<float> result;
    try{
        result = mean_in_window<float>(data, window_size);
    }
    catch(std::invalid_argument &exception){
        std::cerr << exception.what() << std::endl;
        return -1;
    }
    

    std::cout << "Output vector values: ";    
    for (const auto& value : result){
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}