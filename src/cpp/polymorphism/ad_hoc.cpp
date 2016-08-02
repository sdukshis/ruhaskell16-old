#include <string>
#include <iostream>
#include <cassert>
#include <sstream>


class Simpson {
public:
    enum class Name {
        Bart,
        Lisa,
        Homer,
        Marge,
    };
    constexpr Simpson(Name _name) noexcept
        : name_{_name} {}

    Name who() const { return name_; }

private:
    Name name_;
};

class Griffin {
public:
    enum class Name {
        Peter,
        Lois,
        Megr,
        Chris,
        Stewie,
        Brian,
    };
    constexpr Griffin(Name _name) noexcept
        : name_{_name} {}

    Name who() const { return name_; }

private:
    Name name_;
};

std::string greeting(const Simpson& person) {
    using Name = Simpson::Name;
    switch (person.who()) {
    case Name::Bart:
        return "Hello, Bart Simpson";
    case Name::Lisa:
        return "Hello, Lisa Simpson";
    case Name::Homer:
        return "Hello, Homer Simpson";
    case Name::Marge:
        return "Hello, Marge Simpson";
    default:
        assert(false);
    }        
}

std::string greeting(const Griffin& person) {
    using Name = Griffin::Name;
    switch (person.who()) {
    case Name::Peter:
        return "Hello, Peter Griffin";
    case Name::Lois:
        return "Hello, Lois Griffin";
    case Name::Chris:
        return "Hello, Chris Griffin";
    case Name::Stewie:
        return "Hello, Stewie Griffin";
    case Name::Brian:
        return "Hello, Brian Griffin";
    default:
        assert(false);
    }
}

int main() {
    std::cout << greeting(Simpson{Simpson::Name::Bart}) << "\n";
    std::cout << greeting(Griffin{Griffin::Name::Lois}) << "\n";
    return 0;
}
