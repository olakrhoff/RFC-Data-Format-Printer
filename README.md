# RFC-Data-Format-Printer

This program reads a file containing names of variables and corresponding number of bits for the variable, and prints the names in a formatted grid based on the number of bits. This is the notation often seen in RFC documents. The example is from RFC 791, Internet Header Format.

## Prerequisites

- C++ compiler
- Standard C++ library
- Input file containing names and bit numbers

## Compilation


## Usage

Run the program with the following command:

./<program_name> <file_path>

Replace `<program_name>` with the name of the compiled program and `<file_path>` with the path to the input file.

Example usage:

./main example_input_file.txt

Gives this:

     0                   1                   2                   3                  
     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |Version|  IHL  |Type of Service|         Total Length          |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |        Identification         |Flags|     Fragment Offset     |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    | Time to Live  |   Protocol    |        Header Checksum        |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |                        Source Address                         |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |                      Destination Address                      |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |                    Options                    |    Padding    |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

## File Format

The input file should follow a specific format. Each line should contain a name followed by a space-colon-space, then the corresponding bit number. Here's an example of the file format:

    John : 8
    Alice : 4
    Bob : 6

See the `example_input_file.txt` for a real usage example.

## Limitations

The program is very strict for now:

- If a name has more characters than the assigned bit number, or if a name exceeds the total number of available bits left in a line, the program will exit (with an explanation as to where the fault happend :) ).

## Future work

There are much to improve and add to this little tool:

- Output to file, with an optional name (and location)
- Take a folder of files to process, and process them all. (Option to stitch them all in one file)

## License

This code is released under the [MIT License](LICENSE).
