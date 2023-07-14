#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Not correct amount of arguments. Expected 1, but got " << argc - 1 << endl;
        cout << "Usage: ./<program_name> <file_path>" << endl;
        cout << "Example: ./main example/path/to/file.txt" << endl;
        return EXIT_FAILURE;
    }
    
    const char* file_path = argv[1];
    cout << file_path << endl;
    // Open the file
    ifstream file(file_path);
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }
    
    // Read and process the file contents
    string line;
    while (getline(file, line)) {
        // Process each line as needed
        cout << line << endl;
    }
    
    // Close the file
    file.close();
    
    
    return EXIT_SUCCESS;
}
