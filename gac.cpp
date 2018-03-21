#include <iostream>
#include <string>
#include <vector>

using namespace std;

// GLOBAL constants for each character

//  Character : ~
    const std::vector<std::string> possible_tilde = { "tilde", "swung dash" , "ñoqui"};
    const string possible_tilde_message = "~ | 126";
//  ***********************


void Error(int code) {
    
    if ( code == 2 ) {
         cout << "Error! This application only accepts a single argument!!" << endl;
         exit(code);
    }
    if ( code == 3 ) {
         cout << "Error! Your search does not match with any character known by the application!!" << endl;
         exit(code);
    }
}

bool lookupTerm(const std::string& term, const std::vector<std::string>& possible_names) {
    for (const std::string &possible_name : possible_names)
    {
        if (possible_name.compare(term) == 0)
            return true;
    }
    return false;
}
void searchTerm(string term) {
    bool values_found = false;
    if ( lookupTerm(term,possible_tilde) ) {
        cout << possible_tilde_message << endl;
        values_found = true;
    }
    if ( values_found == false )
        Error(3);
}

int main(int argc, char *argv[]) {
    // Get arguments and fail if more than one or nothign was given
	(argc != 2 ) ? Error(2) : Error(0);
    string term = argv[1];
    
    // See if it matches something known and if it does, print the pertaining message about it.
    searchTerm(term);
    
    
    return 0;
}
