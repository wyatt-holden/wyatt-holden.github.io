#include <iostream>
#include <iomanip>
#include <string>

// This function takes in a Phone number and corrects it, using "."
// to separate each sequence of digits
std::string FixPhoneNumber(std::string phone)
{
    //".find()" Is a builtin function used to find a specific element
    // within a string.
    // ".npos" = No Position
    if (phone.find('(') != phone.npos )
        {
            // ".erase" Erases the specified position passed as an argument.
            phone.erase(phone.begin());
        }
    if (phone.find(')') != phone.npos )
        {
            // "replace" can be a bit tricky. It takes different arguments
            // for different reasons.
            // The first 2 arguments are where you would like to start
            // & end the scan of the string to replace argument 3 with
            //wherever argument 4 is found within the start and end positions.
            std::replace(phone.begin(), phone.end(), ')', '.');
        }
    if (phone.find('-') != phone.npos )
        {
            std::replace(phone.begin(), phone.end(), '-', '.');
        }
    else if (phone.size() == 10)
        {
            //".insert" inserts a string at a specified position.
            // Argument 1 is the position within the string where
            // you would like to insert argument 2.
            phone.insert(3, ".");
            phone.insert(7, ".");
        }
    else if (phone.size() == 7)
        {
            phone.insert(3, ".");
        }
    std::cout << phone << std::endl;
    return phone;
}

std::string FixName(std::string name)
{
    //"size_t" is a type to collect the size of an object.
    // "count" counts every specified string (argument 3)
    // within the starting position
    // of argument 1 and ending position of argument 2.
    size_t SpaceCount = std::count(name.begin(), name.end(), ' ');
    int Comma = name.find(',');
    int Space = name.find(' ');
    // ".substr" collects all elements that are in between the
    // starting position of argument 1 and the ending position of argument 2.
    std::string LastName = name.substr(0, Comma);
    std::string FirstName = name.substr(Space +1, Space -3);


    if (Comma == name.npos)
        {
            std::cout << name << std::endl;
        }
    if ((Comma != name.npos) && (SpaceCount == 1))
        {
            name = FirstName + ' ' + LastName;
            std::cout << name << std::endl;
        }
    if ((Comma != name.npos) && (SpaceCount == 2))
        {
            std::string MiddleName =
            name.substr(Comma + Space, name.size());

            name = FirstName + ' ' + MiddleName + ' ' + LastName;
            std::cout << name << std::endl;
        }
    if ((Comma != name.npos) && (SpaceCount == 3))
        {
            std::string MiddleName =
            name.substr(Comma + Space, name.size());

            name = FirstName + ' ' + MiddleName + ' ' + LastName;
            std::cout << name << std::endl;
        }

    return name;
}

std::string FixEmail(std::string email)
{
    int AtSymbol = email.find('@');
    int DotCom = email.find(".com");

    if (AtSymbol == email.npos)
        {
            std::string StudentEmail = email + "@mail.weber.edu";
            std::cout << StudentEmail << std::endl;
            return StudentEmail;
        }
    if ((DotCom == email.npos) && (AtSymbol != email.npos))
        {
            std::string PersonalEmail = email + ".com";
            std::cout << PersonalEmail << std::endl;
            return PersonalEmail;
        }
    if ((DotCom != email.npos) && (AtSymbol != email.npos) && (DotCom > AtSymbol))
        {
            std::cout << email << std::endl;
            return email;
        }
    return email;
}
//"ostream& out" creates a reference object that can be passed as a
// parameter to a function. "ostream" specifically is a type for
// writing to a file.
void WriteFormatted(std::string phone, std::string name,
                    std::string email, std::ostream& out)
{
    int PhoneSpace = 16;
    int NameSpace = 21 - name.size();
    std::string NameThreeDots = name.substr(0, 16) + "...";

    if (name.size() > 19)
        {
            // "out <<" writes the following objects to the output file.
            // "setw" is a Set Width function that creates whitespace
            // the argument is an integer of how many white spaces you
            // would like.
            out << std::setw(PhoneSpace) << phone  << "  " << NameThreeDots
            << std::setw(NameSpace) << "  " << email << std::endl;
        }
    if (name.size() < 19)
        {
            out << std::setw(PhoneSpace) << phone  << "  " << name
            << std::setw(NameSpace) << "  " << email << std::endl;
        }

}
