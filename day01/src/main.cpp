// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "/home/job/Development/adventofcode-2022/day01/src/main.cpp2"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

using namespace std;



// split: (s: string, inout delim: char) -> vector<string> = {
//   ss: stringstream = (s);
//   item: string = ();
//   elems: vector<string> = ();
//   ss.getline(out item, delim);
//   cout << item;
// //   while (std::getline(ss, item, delim)) {
// //     elems.push_back(out item);
// //     // elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
// //   }
//   return elems;
// }

vector<string> split(istream &s, char delim) {
  string item {};
  vector<string> elems;
  while (getline(s, item, delim)) {
    elems.push_back(item);
    // elems.push_back(move(item)); // if C++11 (based on comment from @mchiasson)
  }
  return elems;
}

#line 36 "/home/job/Development/adventofcode-2022/day01/src/main.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 34 "/home/job/Development/adventofcode-2022/day01/src/main.cpp2"


[[nodiscard]] auto main() -> int{
    string input_filename {"input.txt"}; 
    // cout<<"current path: "<<fs::current_path()<<"\n";
    auto input_file {fstream(input_filename)}; 
    if (!(CPP2_UFCS_0(is_open, std::move(input_file)))) {
        cout << "Openening file " << std::move(input_filename) << " failed\n";
        return -1; 
    }

    cout << "Hello\n";

    return 0; 
}

