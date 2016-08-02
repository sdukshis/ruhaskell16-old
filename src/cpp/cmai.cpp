#include <string>
#include <iostream>

// concept
template<class T>
concept bool Stringable = 
    requires(const T& a) {
        {to_string(a)} -> std::string;
    };

// modelling
class Person {
public:
    friend std::string to_string(const Person&) {return "hello";}
};

// algorithm
std::string bold(Stringable s) {
    return "<b>" + to_string(s) + "</b>";
}

Person make_person() {
    return Person{};
}

// instantiation
int main() {
    std::cout << bold(make_person());

    return 0;
}