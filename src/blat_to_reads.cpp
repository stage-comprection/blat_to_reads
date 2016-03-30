#include <vector>
#include <string>
#include <fstream>
#include <iostream>


// Splits a std::string into a std::vector of std::strings according to a specified delimiter (default: \t)
std::vector<std::string> split(std::string str, const std::string delimiter){

    std::vector<std::string> output;
    size_t pos;

    while ((pos = str.find(delimiter)) != std::string::npos){
        output.push_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.length());
    }

    output.push_back(str.substr(0, pos));

    return output;
}


int main (int argc, char *argv[]) {

    if (argc < 2){
        std::cout << "Usage: blat | blat_to_reads output_file" << std::endl;
        return -1;
    }

    std::string outputFilePath = argv[1];
    std::ofstream outputFile;
    outputFile.open(outputFilePath.c_str());

    char line[5000];
    uint lineCount = 1;
    std::string readID;

    while(std::cin.getline(line, 5000)){

        std::cout<<line<<std::endl;

        ++lineCount;

        if (lineCount == 2){

            readID = split(std::string(line), "\t")[4];

        } else if (lineCount == 4){

            lineCount = 0;
            outputFile << ">" << readID << "\n" << line << "\n";
        }

    }

    return 0;
}



