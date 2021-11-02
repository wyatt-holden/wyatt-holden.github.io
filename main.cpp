#include <iostream>
#include "carton.h"
#include <array>
#include <fstream>

using namespace std;

int main() {
  // Create a constant int that will specify the size of the arrays
  // in this program. Set it to 20.
  const int kArraySize = 20;

  // Write the value of the constant to cout.
  cout << "\nConstant to specify size of array: \n" << kArraySize;

  // Create a Carton object using the default constructor.
    Carton DefaultConstructor = Carton();

  // Use the getters to write the length, width, and height of
  // the Carton to cout.
  cout << "\nFirst Carton information:\n"
  << "Length: " << DefaultConstructor.GetLength() << endl
  << "Width: " << DefaultConstructor.GetWidth() << endl
  << "Height: " << DefaultConstructor.GetHeight() << endl;

  // Create a Carton object using the non-default constructor.
  Carton Constructor = Carton(1, 2, 3);

  // Use the getters to write the length, width, and height of
  // the Carton to cout.
  cout << "\nSecond Carton information:\n"
  << "Length: " << Constructor.GetLength() << endl
  << "Width: " << Constructor.GetWidth() << endl
  << "Height: " << Constructor.GetHeight() << endl;

  // Create an array of Cartons. Use the constant defined earlier for the
  // size of the array.
  array <Carton, kArraySize> CartonsArray;

  // Update the first three elements of the array by adding Carton objects
  // created with the non-default constructor.
  CartonsArray[0] = Carton(4,5,6);
  CartonsArray[1] = Carton(7, 8, 9);
  CartonsArray[2] = Carton(10, 11, 12);

  // Loop through the first three elements in the array, use the getters
  // to write the length, width, and height of the Cartons.
  cout << "\nDetails of three Cartons in an array:\n";
  for (int i = 0; i < 3; i++)
  {
      cout << CartonsArray[i].GetLength() << endl;
      cout << CartonsArray[i].GetWidth() << endl;
      cout << CartonsArray[i].GetHeight() << endl;
  }

  // Use the WriteData method to print the data of the two Cartons you
  // have created to cout.
  cout << "\nData of two Cartons:\n";
    DefaultConstructor.WriteData(cout);
    Constructor.WriteData(cout);

  // Use the WriteCarton method to print sentences about the two Cartons you
  // have created to cout.
  cout << "\nReport of two Cartons:\n";
    DefaultConstructor.WriteCarton(cout);
    std::cout << std::endl;
    Constructor.WriteCarton(cout);

  // Loop through the first three elements in the array and write carton data
  // and information using the WriteData and WriteCarton methods.
  // Notice the WriteData method adds an endl and the WriteCarton does not.
  // Add an endl after calling the WriteCarton method.
  cout << "\nReport and data of three Cartons in an array:\n";
  for (int i = 0; i < 3; i++)
  {
      CartonsArray[i].WriteData(cout);
      CartonsArray[i].WriteCarton(cout);
      cout << endl;
  }

  // Print out the volume of two Cartons you have created to cout.
  cout << "\nVolumes of two Cartons:\n";
    cout << DefaultConstructor.Volume() << endl;
    cout << Constructor.Volume();

  // Loop through the first three elements in the array and print out
  // the volume of the Cartons in the array.
  cout << "\nVolumes of the first three Cartons in the array:\n";
  for (int i = 0; i < 3; i++)
  {
      cout << CartonsArray[i].Volume() << ' ';
  }

  // Create another array of Cartons. Use the constant defined earlier for the
  // size of the array.
  array <Carton, kArraySize> CartonsArray2;

  // Define and open an ifstream object. Test that the ifstream opens.
  // Then read the data from file named
  // cartons.txt and store them in this array.
  ifstream In("../../cartons.txt");
  float length, width, height;
  int index = 0;
  while (In >> length)
  {
      In >> width;
      In >> height;
      CartonsArray2[index] = Carton(length, width, height);
      index++;
  }

  // Write the Carton data to file named carton_data.txt. First, define and
  // open an ofstream object using that filename. Then loop through the
  // array from Part 7 and use WriteData to write the data for
  // each Carton. Put each Carton on a single line. Do not include blank lines.
  // Include all the valid Cartons in the array and none of the default Cartons.
    ofstream Out("cartons_data.txt");;
    for(int i = 0; i < index; i++)
    {
        CartonsArray2[i].WriteData(Out);
    }
    Out.close();

  // Write a Carton report to file named carton_report.txt. First, define and
  // open an ofstream object using that filename. Then loop through the
  // array from Part 7 and use WriteCarton to write a sentence for
  // each Carton. Put each Carton on a single line. Include all the valid
  // Cartons in the array and none of the default Cartons.
    ofstream Out2("cartons_report.txt");;
    for(int i = 0; i < index; i++)
    {
        CartonsArray2[i].WriteCarton(Out2);
        cout << endl;
    }
    Out2.close();
    In.close();
  return 0;
}