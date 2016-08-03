## C++ concepts and Haskell type classes

### Pavel Filonov (pavel.filonov@kaspersky.com)


## Motivation

1. GCC 6.1 Released with C++ concepts support (-fconcepts) <!-- .element: class="fragment" -->
2. A lot of questions about difference between this tow instruments <!-- .element: class="fragment" -->
 * How are c++ concepts different to Haskell type classes? (SO) <!-- .element: class="fragment" -->
 * Understanding C++ Concepts through Haskell Type Classes <!-- .element: class="fragment" -->
 * A Comparison of C++ Concepts and Haskell Type Classes <!-- .element: class="fragment" -->
 * Concepts for C++1y: The Challenge <!-- .element: class="fragment" -->
3. You must be insane to mix c++ and haskell in one talk! <!-- .element: class="fragment" -->



## The problem with C++ templates

The programmer has a set of problems and he decided to use C++

```cpp  
class Problem {
public:
    // ...
};

int main() {
    set<Problem> to_do;

    to_do.insert(Problem());

    return 0;
}
``` 
<!-- .element: class="fragment" -->


## this is ~~spart~~a problem!

<pre  style="font-size: 10pt; white-space: pre-wrap; word-wrap: break-word; ">
In file included from <span style="font-weight: bold">/usr/include/c++/6/bits/stl_tree.h:65:0</span>,
                 from <span style="font-weight: bold">/usr/include/c++/6/set:60</span>,
                 from <span style="font-weight: bold">SetOfProblems.cpp:1</span>:
/usr/include/c++/6/bits/stl_function.h: In instantiation of ‘<span style="font-weight: bold">constexpr bool std::less&lt;_Tp&gt;::operator()(const _Tp&amp;, const _Tp&amp;) const [with _Tp = Problem]</span>’:
<span style="font-weight: bold">/usr/include/c++/6/bits/stl_tree.h:1806:11:</span>   required from ‘<span style="font-weight: bold">std::pair&lt;std::_Rb_tree_node_base*, std::_Rb_tree_node_base*&gt; std::_Rb_tree&lt;_Key, _Val, _KeyOfValue, _Compare, _Alloc&gt;::_M_get_insert_unique_pos(const key_type&amp;) [with _Key = Problem; _Val = Problem; _KeyOfValue = std::_Identity&lt;Problem&gt;; _Compare = std::less&lt;Problem&gt;; _Alloc = std::allocator&lt;Problem&gt;; std::_Rb_tree&lt;_Key, _Val, _KeyOfValue, _Compare, _Alloc&gt;::key_type = Problem]</span>’
<span style="font-weight: bold">/usr/include/c++/6/bits/stl_tree.h:1859:28:</span>   required from ‘<span style="font-weight: bold">std::pair&lt;std::_Rb_tree_iterator&lt;_Val&gt;, bool&gt; std::_Rb_tree&lt;_Key, _Val, _KeyOfValue, _Compare, _Alloc&gt;::_M_insert_unique(_Arg&amp;&amp;) [with _Arg = Problem; _Key = Problem; _Val = Problem; _KeyOfValue = std::_Identity&lt;Problem&gt;; _Compare = std::less&lt;Problem&gt;; _Alloc = std::allocator&lt;Problem&gt;]</span>’
<span style="font-weight: bold">/usr/include/c++/6/bits/stl_set.h:492:40:</span>   required from ‘<span style="font-weight: bold">std::pair&lt;typename std::_Rb_tree&lt;_Key, _Key, std::_Identity&lt;_Key&gt;, _Compare, typename __gnu_cxx::__alloc_traits&lt;_Alloc&gt;::rebind&lt;_Key&gt;::other&gt;::const_iterator, bool&gt; std::set&lt;_Key, _Compare, _Alloc&gt;::insert(std::set&lt;_Key, _Compare, _Alloc&gt;::value_type&amp;&amp;) [with _Key = Problem; _Compare = std::less&lt;Problem&gt;; _Alloc = std::allocator&lt;Problem&gt;; typename std::_Rb_tree&lt;_Key, _Key, std::_Identity&lt;_Key&gt;, _Compare, typename __gnu_cxx::__alloc_traits&lt;_Alloc&gt;::rebind&lt;_Key&gt;::other&gt;::const_iterator = std::_Rb_tree_const_iterator&lt;Problem&gt;; std::set&lt;_Key, _Compare, _Alloc&gt;::value_type = Problem]</span>’
<span style="font-weight: bold">SetOfProblems.cpp:15:27:</span>   required from here
<span style="font-weight: bold">/usr/include/c++/6/bits/stl_function.h:387:20:</span> <span style="font-weight: bold; color: #aa0000">error: </span>no match for ‘<span style="font-weight: bold">operator&lt;</span>’ (operand types are ‘<span style="font-weight: bold">const Problem</span>’ and ‘<span style="font-weight: bold">const Problem</span>’)
       { return <span style="font-weight: bold; color: #aa0000">__x &lt; __y</span>; }
                <span style="font-weight: bold; color: #aa0000">~~~~^~~~~</span>
In file included from <span style="font-weight: bold">/usr/include/c++/6/bits/stl_algobase.h:64:0</span>,
                 from <span style="font-weight: bold">/usr/include/c++/6/bits/stl_tree.h:63</span>,
                 from <span style="font-weight: bold">/usr/include/c++/6/set:60</span>,
                 from <span style="font-weight: bold">SetOfProblems.cpp:1</span>:
<span style="font-weight: bold">/usr/include/c++/6/bits/stl_pair.h:369:5:</span> <span style="font-weight: bold; color: #00aaaa">note: </span>candidate: template&lt;class _T1, class _T2&gt; constexpr bool std::operator&lt;(const std::pair&lt;_T1, _T2&gt;&amp;, const std::pair&lt;_T1, _T2&gt;&amp;)
     <span style="font-weight: bold; color: #00aaaa">operator</span>&lt;(const pair&lt;_T1, _T2&gt;&amp; __x, const pair&lt;_T1, _T2&gt;&amp; __y)
     <span style="font-weight: bold; color: #00aaaa">^~~~~~~~</span>
</pre>


                        <pre style="font-size: large; white-space: pre-wrap; word-wrap: break-word; ">
<span style="font-weight: bold">/usr/include/c++/6/bits/stl_pair.h:369:5:</span> <span style="font-weight: bold; color: #00aaaa">note: </span>  template argument deduction/substitution failed:
In file included from <span style="font-weight: bold">/usr/include/c++/6/bits/stl_tree.h:65:0</span>,
                 from <span style="font-weight: bold">/usr/include/c++/6/set:60</span>,
                 from <span style="font-weight: bold">SetOfProblems.cpp:1</span>:
<span style="font-weight: bold">/usr/include/c++/6/bits/stl_function.h:387:20:</span> <span style="font-weight: bold; color: #00aaaa">note: </span>  ‘<span style="font-weight: bold">const Problem</span>’ is not derived from ‘<span style="font-weight: bold">const std::pair&lt;_T1, _T2&gt;</span>’
       { return <span style="font-weight: bold; color: #00aaaa">__x &lt; __y</span>; }
                <span style="font-weight: bold; color: #00aaaa">~~~~^~~~~</span>
In file included from <span style="font-weight: bold">/usr/include/c++/6/bits/stl_algobase.h:67:0</span>,
                 from <span style="font-weight: bold">/usr/include/c++/6/bits/stl_tree.h:63</span>,
                 from <span style="font-weight: bold">/usr/include/c++/6/set:60</span>,
                 from <span style="font-weight: bold">SetOfProblems.cpp:1</span>:
<span style="font-weight: bold">/usr/include/c++/6/bits/stl_iterator.h:298:5:</span> <span style="font-weight: bold; color: #00aaaa">note: </span>candidate: template&lt;class _Iterator&gt; bool std::operator&lt;(const std::reverse_iterator&lt;_Iterator&gt;&amp;, const std::reverse_iterator&lt;_Iterator&gt;&amp;)
     <span style="font-weight: bold; color: #00aaaa">operator</span>&lt;(const reverse_iterator&lt;_Iterator&gt;&amp; __x,
     <span style="font-weight: bold; color: #00aaaa">^~~~~~~~</span>
<span style="font-weight: bold">/usr/include/c++/6/bits/stl_iterator.h:298:5:</span> <span style="font-weight: bold; color: #00aaaa">note: </span>  template argument deduction/substitution failed:
In file included from <span style="font-weight: bold">/usr/include/c++/6/bits/stl_tree.h:65:0</span>,
                 from <span style="font-weight: bold">/usr/include/c++/6/set:60</span>,
                 from <span style="font-weight: bold">SetOfProblems.cpp:1</span>:
<span style="font-weight: bold">/usr/include/c++/6/bits/stl_function.h:387:20:</span> <span style="font-weight: bold; color: #00aaaa">note: </span>  ‘<span style="font-weight: bold">const Problem</span>’ is not derived from ‘<span style="font-weight: bold">const std::reverse_iterator&lt;_Iterator&gt;</span>’
       { return <span style="font-weight: bold; color: #00aaaa">__x &lt; __y</span>; }
                <span style="font-weight: bold; color: #00aaaa">~~~~^~~~~</span>
In file included from <span style="font-weight: bold">/usr/include/c++/6/bits/stl_algobase.h:67:0</span>,
                 from <span style="font-weight: bold">/usr/include/c++/6/bits/stl_tree.h:63</span>,
                 from <span style="font-weight: bold">/usr/include/c++/6/set:60</span>,
                 from <span style="font-weight: bold">SetOfProblems.cpp:1</span>:
</pre>


## SOS!

<pre  style="font-size: large; white-space: pre-wrap; word-wrap: break-word; ">
<span style="font-weight: bold">ConceptOfProblems.cpp:</span> In function ‘<span style="font-weight: bold">int main()</span>’:
<span style="font-weight: bold">ConceptOfProblems.cpp:28:16:</span> <span style="font-weight: bold; color: #aa0000">error: </span>template constraint failure
     set&lt;Problem<span style="font-weight: bold; color: #aa0000">&gt;</span> to_do;
                <span style="font-weight: bold; color: #aa0000">^</span>
<span style="font-weight: bold">ConceptOfProblems.cpp:28:16:</span> <span style="font-weight: bold; color: #00aaaa">note: </span>  constraints not satisfied
<span style="font-weight: bold">ConceptOfProblems.cpp:28:16:</span> <span style="font-weight: bold; color: #00aaaa">note: </span>  concept ‘<span style="font-weight: bold">LessComparable&lt;Problem&gt;()</span>’ was not satisfied
</pre>

```cpp
template<typename T>
concept bool LessComparable()
{
  return requires (T a, T b)
  {
    { a < b } -> bool;
  };
}
```
<!-- .element: class="fragment" data-fragment-index="1" -->

Hmmm... I guess I saw it before in <!-- .element: class="fragment" data-fragment-index="2" --> ~~Simpsons~~ Haskell

```haskell
class LessComparable a where
    (<) :: a -> a -> Bool
```
<!-- .element: class="fragment" data-fragment-index="2" -->



### Find the difference
C++ style
```cpp
// Concept
template<class T> concept bool Stringable = 
    requires(const T& a) {
        {to_string(a)} -> std::string;
    };
// Modelling
class Person {
    //...
    friend std::string to_string(const Person&);
};
// Algorithm
std::string bold(Stringable s) {
    return "<b>" + to_string(s) + "</b>";
}
// Instantiation
std::cout << bold(Person{"John", "Smith"}) << "\n";
```


Haskell style
```haskell
-- Type class
class Stringable a where
    toString :: a -> String

-- Instance
data Person = Person {firstname :: String, lastname :: String}

instance Stringable Person where
    toString p = take 1 (firstname p) ++ ". " ++ lastname p
 
-- Algorithm
bold :: (Stringable a) => a -> String
bold a = "<b>" ++ toString a ++ "</b>"

--Instantiation
putStrLn $ bold $ Person "John" "Smith"
```


### We need to go deeper
```haskell
data StringableD a = StringableD {
    toString :: a -> String
}

personStringableDictionary :: StringableD Person
personStringableDictionary = StringlableD {
    toStringD = ...
}

boldD :: StringableD a -> a -> String -- '=>' became '->'
-- the context is now a parameter!
boldD stringableDict a = toStringD stringableDict a 

putStrLn $ bold personStringableDictionary (Person "John" "Smith")
```
Type classes are a way to pass instance dictionaries implicitly


### C++ virtual function
```cpp
// Abstract class
class Stringable {
public:
    virtual ~Stringable() {}
    virtual std::string to_string() const = 0;
};
// Inheretance
class Person: public Stringable {
public:
    std::string to_string() const override { return ...}
};
// Algorithm
std::string bold(const Stringable& s) {
    return "<b>" + s.to_string() + "</b>";
}

std::cout << bold(Person{"John", "Smith"}) << "\n";
```