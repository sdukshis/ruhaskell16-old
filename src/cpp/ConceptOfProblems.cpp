#include <set>
#include <memory>
#include <string>

template<typename T>
concept bool
LessComparable()
{
  return requires (T a, T b)
  {
    { a < b } -> bool;
  };
}


template<LessComparable Key>
class set: public std::set<Key> {
public:
    using std::set<Key>::set;
};

class Problem {
public:
    // ...
};

int main() {
    set<Problem> to_do;

    to_do.insert(Problem());

    return 0;
}
/*
ConceptOfProblems.cpp: In function ‘int main()’:
ConceptOfProblems.cpp:31:16: error: template constraint failure
     set<Problem> to_do;
                ^
ConceptOfProblems.cpp:31:16: note:   constraints not satisfied
ConceptOfProblems.cpp:31:16: note:   concept ‘LessComparable<Problem>()’ was not satisfied
ConceptOfProblems.cpp:33:11: error: request for member ‘insert’ in ‘to_do’, which is of non-class type ‘int’
     to_do.insert(Problem());
*/