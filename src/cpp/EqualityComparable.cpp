template<class T>
concept bool EqualityComparable =
    requires(T a, T b) {
        {a == b} -> bool;
        {a != b} -> bool;
    };

bool equal(const EqualityComparable& lhs, const EqualityComparable &rhs) {
    return lhs == rhs;
}

class Foo {
public:
    friend bool operator==(const Foo& lhs, const Foo& rhs) {
        return lhs.number == rhs.number;
    }

public:
    int number;

};

inline bool operator!=(const Foo& lhs, const Foo& rhs) {
    return !(lhs == rhs);
}

int main() {
    equal(1, 3);
    Foo a, b;
    equal(a, b);
    return 0;
}