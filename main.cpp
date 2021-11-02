#include <iostream>
#include "directories.h"
#include <fstream>
#include <array>
using namespace std;

int main() {

    // Part 1 - Phone Number Correction
    std::cout << "-------------------- Phone Number ---------------\n";
    FixPhoneNumber("654.9873");
    FixPhoneNumber("325.654.9873");
    FixPhoneNumber("654-9873");
    FixPhoneNumber("325-654-9873");
    FixPhoneNumber("(325)654-9873");
    FixPhoneNumber("6549873");
    FixPhoneNumber("3256549873");

    // Part 2 - Name Correction
    std::cout << "-------------------- Name -----------------------\n";
    FixName("Baggins, Bilbo");
    FixName("Bilbo Baggins");
    FixName("Baggins, Bilbo B.");
    FixName("Bilbo B. Baggins");
    FixName("Bilbo Baxby Buttons Baggins");
    FixName("Baggins, Bilbo Baxby Buttons");

    // Part 3 - Email Correction
    std::cout << "------------------------ Email ------------------\n";
    FixEmail("baggins@gmail.com");
    FixEmail("baggins@gmail");
    FixEmail("baggins");
    FixEmail("baggins@yahoo");
    FixEmail("baggins@yahoo.com");
    FixEmail("baggins.bill");
    FixEmail("baggins.bill@gmail");

    // Part 4 - Formatting and compiling data for each person
    std::cout << "---------------------- Phone, Name & Email ------\n";
    WriteFormatted("234.543.6543","Will Powers",
                   "collins297@gmail.com", std::cout);
    WriteFormatted("543.6543","Will Powers",
                   "big@gone.com", std::cout);
    WriteFormatted("234.543.6543","Will Jonathan Scott Powers",
                   "big@gone.com", std::cout);

    //Part 5 - Reading and writing data to a file
    std::cout << "Hello, please enter 2 files you would"
                 " like to open" << std::endl;

    std::string FirstFile;
    std::cout << "First File" << std::endl;
    std::cin  >> FirstFile;
    // "ifstream" is from the fstream class. Its purpose is to create a type
    // of object that has input already stored within a file.
    // the concatenated argument after "In" (the object) opens a file.
    // "../../" I premade this string to move up within the directory 2 times.
    ifstream In("../../" + FirstFile);

    while (In.is_open())
        {
        // ".rdbuf" reads a file in a pretty format.(Ususally the exact way it
        // is formatted within the file)
        std::cout << In.rdbuf() << endl;
        break;
        }
    if (In.fail())
        {
        std::cout << "Sorry, the first file you entered does"
                     " not exist. Please run the program again.";
        return 1;
        }
    In.close();

    std::string SecondFile;
    std::cout << "Second File" << std::endl;
    std::cin >> SecondFile;
    ifstream SecondIn("../../" + SecondFile);

    if(SecondIn.is_open())
        {
        std::cout << SecondIn.rdbuf() << endl;
        }
    if (SecondIn.fail())
        {
        std::cout << "Sorry, the second file you entered does"
                     " not exist. Please Try again.";
        return 1;
        }
    SecondIn.close();

    std::cout << "Type in a name of a new file. We will write data to the file.\n";
    std::string OutputFile;
    cin >> OutputFile;
    // "ofstream" is form the "fstream" class. It creates a type for a file
    // to be written to. similar to "ifstream" but to write to a file.
    ofstream Out("../../" + OutputFile);

    if (Out.is_open())
        {
            WriteFormatted("234.543.6543","Will Powers",
                           "collins297@gmail.com", Out);
            WriteFormatted("543.6543","Will Powers",
                           "big@gone.com", Out);
            WriteFormatted("234.543.6543","Will Jonathan Scott Powers",
                           "big@gone.com", Out);
        }
    Out.close();

    return 0;
}