#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <stdlib.h>




// Generate a random number.  |  I know NOTHING about cryptography in c++ and what would be the best for generating passwords.
// Plz fix if you know a better way.
int rng_int(int min, int max) {
    if (min > max) {
        std::system("clear||cls");
        throw std::invalid_argument("min must be less than or equal to max");
    }
    std::random_device rd;
    std::mt19937 gen(rd()); // Seed the Mersenne Twister PRNG with the random device.
    std::uniform_int_distribution<> dis(min, max); // Create a uniform distribution to generate random integers within the specified range.

    int result = dis(gen);
    return result;
}




// Check to see if user input can be turned into an actual integer.
bool isInt(const std::string & str) {
    int n;
    std::istringstream istreamObject(str);
    istreamObject >> std::noskipws >> n;
    return istreamObject.eof() && !istreamObject.fail();
}




// Need to do to many things just to get user input so I made my own input function.
std::string input(std::string m) {
    std::string i;
    std::system("clear||cls");
    std::cout << m;
    getline(std::cin, i);

    return i;
}





// Our main goodies.
int main() {
    std::system("clear||cls");
    std::string ps_msg = "How long do you want your password?: ";
    std::string length = input(ps_msg);

    std::system("clear||cls");
    std::string count_msg = "How many passwords would you like to generate?: ";
    std::string count = input(count_msg);

    if (isInt(length) && isInt(count))
    {
        int len = std::stoi(length);
        int cnt = std::stoi(count);
        std::string characters = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz01234567890123456789~\"`'!!!!@@@@#$%^&*)(_-+=][}{|\\/><;:?.,";
        // I have multiple of certain characters and numbers because I want them to be used more often.

        std::system("clear||cls");
        for (int i = 0; i < cnt; ++i) {
            std::string password = "";
            for (int j = 0; j < len; ++j) {
                int index = rng_int(0, characters.size()-1);
                char letter = characters[index];
                password += letter;
            }
            std::cout << "Password " << (i + 1) << ": " << password << std::endl;
            std::cout << std::endl;
        }
        return 0;
    }
    else
    {
        std::system("clear||cls");
        throw std::invalid_argument("String(s) can\'t be converted to an int.");
    }

}
