#include <string>
#include <iostream>
#include <cassert>
#include <sstream>

class Nameble {
public:
    virtual ~Nameble() {}
    virtual std::string name() const = 0;
};

class Simpson: public Nameble {
public:
    enum class Name {
        Bart,
        Lisa,
        Homer,
        Marge,
    };
    constexpr Simpson(Name _name) noexcept
        : name_{_name} {}

    std::string name() const override {
        switch (name_) {
        case Name::Bart:
            return "Bart Simpson";
        case Name::Lisa:
            return "Lisa Simpson";
        case Name::Homer:
            return "Homer Simpson";
        case Name::Marge:
            return "Marge Simpson";
        default:
            assert(false);
        }
    }

private:
    Name name_;
};

class Griffin: public Nameble {
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

    std::string name() const override {
        switch (name_) {
        case Name::Peter:
            return "Peter Griffin";
        case Name::Lois:
            return "Lois Griffin";
        case Name::Chris:
            return "Chris Griffin";
        case Name::Stewie:
            return "Stewie Griffin";
        case Name::Brian:
            return "Brian Griffin";
        default:
            assert(false);
        }
    }

private:
    Name name_;
};

std::string greeting(const Nameble& person) {
    return "Hello, " + person.name();
}

int main() {
    std::cout << greeting(Simpson{Simpson::Name::Bart}) << "\n";
    std::cout << greeting(Griffin{Griffin::Name::Lois}) << "\n";
    return 0;
}
