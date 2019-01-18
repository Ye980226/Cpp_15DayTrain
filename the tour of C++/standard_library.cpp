#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <regex>
#include<vector>
using namespace std;
// string s{"C++ is a general-purpose programming language"};
void use()
{
    ifstream in("file.txt");
    if (!in)
        cerr << "no  file\n";
    regex pat{R"(\w{2}\s*\d{5}(-\d{4})?)"};
    int lineno = 0;
    for (string line; getline(cin, line);)
    {
        ++lineno;
        smatch matches;
        if (regex_search(line, matches, pat))
        {
            cout << lineno << ": " << matches[0] << '\n';
            if (1 < matches.size() && matches[1].matched) //if there is a sub-pattern//and if it is matched
                cout << "\t: " << matches[1] << '\n';     //submatch
        }
    }
}
void test()
{
    string input = "aa as; asd ++e^asdf asdfg";
    regex pat{R"(\s+(\w+))"};
    for (sregex_iterator p(input.begin(), input.end(), pat); p != sregex_iterator{}; ++p)
        cout << (*p)[1] << '\n';
}
template <typename Target = string, typename Source = string>
Target to(Source arg)
{
    stringstream interpreter;
    Target result;
    if (!(interpreter << arg) || !(interpreter >> result) || !(interpreter >> std::ws).eof())
        throw runtime_error{"to<>() failed"};
    return result;
}

int main()
{
    // regex pat{R"\w{2}\s*\d{5}(-\d{4})?"};
    // int lineno = 0;
    // for (string line; getline(cin, line);)
    // {
    // ++lineno;
    // smatch matches; //s stands for sub/string
    // if (regex_search(line, matches, pat))
    // cout << lineno << ":" << matches[0] << '\n';
    // }
    // test();
    // ostringstream oss;
    // oss << "{}";
    // cout << oss.str() << '\n';
    // auto x1 = to<string, double>(1.2);
    // auto x2 = to<string>(1.2);
    // auto x3 = to<>(1.2);
    // auto x4 = to(1.2);
    
    return 0;
}

// regex_match(): Match a regular expression against a string (of known
// size) (§9.4.2).
// regex_search(): Search for a string that matches a regular expression
// in an (arbitrarily long) stream of data (§9.4.1).
// regex_replace(): Search for strings that match a regular expression in
// an (arbitrarily long) stream of data and replace them.
// regex_iterator: Iterate over matches and submatches (§9.4.3).
// regex_token_iterator: Iterate over non-matches.