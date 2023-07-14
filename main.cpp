#include <iostream>
#include <fstream>

using namespace std;

#define BITS_PER_LINE 32

void print_space_line()
{
    for (int i = 0; i < BITS_PER_LINE * 2 + 1; ++i)
    {
        if (i % 2 == 0)
            cout << "+";
        else
            cout << "-";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Not correct amount of arguments. Expected 1, but got " << argc - 1 << endl;
        cout << "Usage: ./<program_name> <file_path>" << endl;
        cout << "Example: ./main example/path/to/file.txt" << endl;
        return EXIT_FAILURE;
    }
    
    const char *file_path = argv[1];
    cout << file_path << endl;
    // Open the file
    ifstream file(file_path);
    if (!file.is_open())
    {
        cout << "Failed to open the file." << endl;
        return 1;
    }
    
    // Add top line
    for (int i = 0; i <= BITS_PER_LINE / 10; ++i)
    {
        cout << " " << i << string(9 * 2, ' ');
    }
    cout << endl;
    
    // Add bit number line
    for (int i = 0; i < BITS_PER_LINE; ++i)
    {
        cout << " " << i % 10;
    }
    cout << endl;
    
    // Print top space line
    print_space_line();
    // Read and process the file contents
    string line;
    string name;
    int bits {};
    int bits_used {};
    while (getline(file, line))
    {
        if (bits_used == 0)
            cout << "|";
        name = line.substr(0, line.find(" :"));
        bits = stoi(line.substr(line.find(": ") + 2, line.length() - line.find(" :")));
        
        if (bits + bits_used > BITS_PER_LINE)
        {
            cout << "Sorry, name: " << name << " had to many bits (" << bits << "), and did not fit in the current line" << endl;
            return EXIT_FAILURE;
        }
        
        if ((int)name.length() > bits * 2)
        {
            cout << "Sorry, name: " << name << " is longer than the number of bits assigned: " << bits;
            return EXIT_FAILURE;
        }
        
        int padding_bits = (bits * 2) - 1 - name.length();
        cout << string(padding_bits / 2, ' ') << name << string(padding_bits - (padding_bits / 2), ' ') << "|";
        bits_used += bits;
        if (bits_used == BITS_PER_LINE)
        {
            cout << endl;
            print_space_line();
            bits_used = 0;
        }
    }
    
    // Close the file
    file.close();
    
    
    return EXIT_SUCCESS;
}
