#include <iostream>
#include <string>
#include <vector>
#include <algorithm>   


using namespace std;

// GLOBAL constants for each character


//  Character : !
    const std::vector<std::string> possible_exclmark = { "exclamation", "exclamation symbol" , "exclamation mark"};
    const string possible_exclmark_message = "! | 33";
//  ***********************
//  Character : "
    const std::vector<std::string> possible_exclmark = { "double quotation", "double quotation marks" , "double quotes"};
    const string possible_exclmark_message = "\" | 34";
//  ***********************
//  Character : #
    const std::vector<std::string> possible_hash = { "number sign", "hash" , "pound" , "double quotes"};
    const string possible_exclmark_message = "# | 35";
//  ***********************
//  Character : $
    const std::vector<std::string> possible_dollar = { "dollar", "dollar symbol", "dollar sign" };
    const string possible_exclmark_message = "$ | 36";
//  ***********************
//  Character : %
    const std::vector<std::string> possible_percent = { "percent", "percent symbol", "percent sign" , "percentage" };
    const string possible_exclmark_message = "% | 37";
//  ***********************
//  Character : &
    const std::vector<std::string> possible_ampersand = { "percent", "percent symbol", "percent sign" , "percentage" };
    const string possible_exclmark_message = "& | 38";
//  ***********************
//  Character : '
    const std::vector<std::string> possible_exclmark = { "apostrophe", "single quote", "single quotation"  };
    const string possible_exclmark_message = "' | 39";
//  ***********************
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
    std::string lower(term);
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    for (const std::string &possible_name : possible_names)
    {
        if (possible_name.compare(lower) == 0)
            return true;
    }
    return false;
}
void searchTerm(string term) {
    bool one_found = false;
    if ( lookupTerm(term,possible_tilde) ) {
        cout << possible_tilde_message << endl;
        one_found = true;
    }
    ( ! one_found ) ? Error(3) : Error(0);
}

int main(int argc, char *argv[]) {
    // Get arguments and fail if more than one or nothign was given
	(argc != 2 ) ? Error(2) : Error(0);
    string term = argv[1];
    
    // See if it matches something known and if it does, print the pertaining message about it.
    searchTerm(term);
    
    
    return 0;
}
