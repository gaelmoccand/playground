#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <experimental/vector>
#include <map>


template <typename T>
void erase(std::vector<T>& vec, const T& elem)
{
    vec.erase(std::remove(begin(vec), end(vec), elem), end(vec));
}

void erase(std::string& str, const char elem)
{
    str.erase(std::remove(begin(str), end(str), elem), end(str));
}

void disp(const std::vector<int>& vec)
{
    std::cout << "{";
    for(const auto& el : vec )
    {
        std::cout << el << " ,";
    }
    std::cout << "}\n";
}

int main() {
    using namespace std;


    vector<int> myvec{1, 2, 3, 4, 5, 6, 7, 8, 8, 9, 9, -1, -2, 7};
    string mystr{"Hi Folks !  !"};

    disp(myvec);
    cout << mystr << "\n\n";

    // 1. remove element at specific position
    myvec.erase(myvec.begin() + 1);
    mystr.erase(mystr.begin() + 1);
    cout << "remove the 2nd element  erase(myvec.begin() + 1); :\n";
    disp(myvec);
    cout << mystr << "\n\n";
    // for a subrange (important for next point)
    cout << "remove the first 2 elements erase(myvec.begin(), myvec.begin() + 2); :\n";
    myvec.erase(myvec.begin(), myvec.begin() + 2); // erase the first 2 el.
    mystr.erase(0, 2);
    disp(myvec);
    cout << mystr << "\n\n";    

    // 2. remove element that match a specific value
    // using erase_remove C++ idiom

    cout << "std::remove(begin(myvec), end(myvec), 6);\n";
    auto iter = std::remove(begin(myvec), end(myvec), 6);
    myvec.erase(iter, end(myvec));
    disp(myvec);

    cout << "erase(std::remove(begin(mystr), end(mystr), '!'), end(mystr));\n";
    mystr.erase(std::remove(begin(mystr), end(mystr), '!'), end(mystr));
    cout << mystr << "\n\n";

    cout << "remove all element == 7\n";
    erase(myvec, 7);
    disp(myvec);

    cout << "remove all element == s\n";
    erase(mystr,'s');               
    cout << mystr << "\n\n";

    // 3. remove element with predicate using  < C++20
    // The most practical use for remove and remove_if is to remove elements from a range.

    auto negativeNumber = [](auto const & elem) { return elem < 0;};
    auto it = std::remove_if(myvec.begin(), myvec.end(), negativeNumber);
    myvec.erase(it, myvec.end());
    cout << "remove all negative Number \n";
    disp(myvec); cout << "\n\n";

    // 4. remove adjacent duplicates using unique

    myvec.erase(std::unique(myvec.begin(),myvec.end()),myvec.end());
    cout << "remove adjacent dulpicates \n";
    disp(myvec); cout << "\n\n";

    // 5. erase and erase_if finally available in C++20
    experimental::erase(myvec,8);
    cout << "erase value 8 in  C++ 20 \n";
    disp(myvec); cout << "\n\n";

    auto divisibleBy3 = [](auto const& elem) { return (elem % 3) == 0; };
    experimental::erase_if(myvec, divisibleBy3);
    cout << "erase value divisible by 3 in  C++ 20 \n";
    disp(myvec);
}
