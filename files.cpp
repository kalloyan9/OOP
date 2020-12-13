#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // strlen & etc.

#define MAX_LEN 1024

#define FILE_TXT "file.txt"
#define FILE_BIN "file.bin"

int writeInFile(void)
{
        // writing in file        
        std::string info;
        std::getline(std::cin, info); // getline for std::string

        // 1st tag for output, 2nd tag for APPEND to end of file
        std::fstream out(FILE_TXT, std::ios::out | std::ios::app);
        if (!out)
                return -1;
        else{
                out << info << std::flush;

                out.close();
        }
        // writing
        return 0;
}

int readFromFile(void)
{
        // reading from file
        std::string info;
        std::fstream in(FILE_TXT, std::ios::in);
        if (!in)
                return -1;
        else{
                std::getline(in, info);

                in.close();
        }        
        std::cout << info;
        return 0;
}

// binary files:
int writeInBinary(void)
{
        std::string info;
        std::getline(std::cin, info); // getline for std::string

        // 1st tag for output, 2nd tag for APPEND to end of file, 3rd tag for binary
        std::fstream outBin(FILE_BIN, std::ios::out | std::ios::app | std::ios::binary);
        if (!outBin)
                return -1;
        else{
                // writing must be done with write function from fstream lib
                
                char str[MAX_LEN]; // helper var for writing in binary files
                int len; // helper var for the length of str

                strcpy(str, &info[0]);
                len = strlen(str);
                outBin.write((const char*) &len, sizeof(len));
                outBin.write((const char*) str, len + 1); // len + 1 for the '\0'
                outBin.flush();
                
                outBin.close();
        }
        return 0;
}

int readFromBinary(void)
{
        std::fstream inBin(FILE_BIN, std::ios::in | std::ios::app | std::ios::binary);
        if (!inBin)        
                return -1;
        else{
                // reading must be done with read funcion from fstream lib

                char str[MAX_LEN]; // helper var for reading from binary files
                int len; // helper var for the lenght of str

                inBin.read((char*) &len, sizeof(len));
                inBin.read(str, len);

                inBin.close();
        }
        return 0;
}


int main()
{

        return 0;
}