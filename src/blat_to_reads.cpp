#include <vector>
#include <string>
#include <fstream>
#include <iostream>


std::string to_upper_case(std::string sequence){

    std::string output= "";

    for (uint i=0; i<sequence.size(); ++i){

        switch (sequence[i]){

            case 'a':
                output += 'A';
                break;
            case 't':
                output += 'T';
                break;
            case 'g':
                output += 'G';
                break;
            case 'c':
                output += 'C';
                break;
            case 'n':
                output += 'N';
                break;
            default:
                std::cerr << "Error converting to uppercase : " << sequence <<std::endl;
                exit(0);
        }
    }

    return output;
}




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

    if (argc < 3){
        std::cout << "Usage: blat | blat_to_reads input_file output_file" << std::endl;
        return -1;
    }

    std::string inputFilePath = argv[1];
    std::string outputFilePath = argv[2];
    std::ifstream inputFile;
    std::ofstream outputFile;
    inputFile.open(inputFilePath.c_str());
    outputFile.open(outputFilePath.c_str());

    uint lineCount = 1;
    std::string line, readID;

    while(std::getline(inputFile, line)){

        ++lineCount;

//        std::cout<<lineCount<<" "<<line<<std::endl;

        if (lineCount == 2){

            readID = split(line, " ")[4];

        } else if (lineCount == 4){

            lineCount = 0;
            outputFile << ">" << readID << "\n" << to_upper_case(line) << "\n";

        }

    }

    return 0;
}



