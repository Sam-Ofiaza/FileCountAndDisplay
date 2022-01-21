#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::vector;

int main(int argc, char * argv[]) {

    if(argc < 2) {
        cout << "Invalid option: use -d, -f, or -b.\n";
        return 1;
    }

    vector<string> input;
    string line;

    while(getline(cin, line)) {
        input.push_back(line);
    }

    if(strcmp(argv[1], "-d") == 0) {
        cout << input[0] << "\n";
    }
    else if(strcmp(argv[1], "-f") == 0) {
        cout << input[1] << "\n";
    }
    else if(strcmp(argv[1], "-b") == 0) {
        cout << input[2] << "\n";
    }

    return 0;
}
