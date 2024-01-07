#include <iostream>
#include <fstream>

bool same(double a, double b){
    return std::abs(a - b) < 0.001;
}

bool verify(char * correctFile, char * outputFile, int expectedSize){
    std::ifstream correct(correctFile);
    std::ifstream output(outputFile);

    int row_val, row_out;
    double correct_val, output_val;
    int expectedSq = expectedSize * expectedSize;
    int i = 0;

    while(correct >> row_val && output >> row_out){
        if(row_val != row_out){
            std::cout << "Error: expected row " << row_val << " but found row " << row_out << std::endl;
            return false;
        }

        correct >> correct_val;
        output >> output_val;
        if(!same(correct_val, output_val)){
            std::cout << "Error at index " << i << std::endl;
            std::cout << "Correct: " << correct_val << std::endl;
            std::cout << "Output: " << output_val << std::endl;
            return false;
        }
        i++;
    }


    if(i != expectedSq){
        std::cout << "Error: expected " << expectedSq << " values, but found " << i << std::endl;
        return false;
    }

    return true;
}

int main(int argc, char ** argv){
    if(argc != 4){
        std::cout << "Usage: ./verify <correct file> <output file> <expected size>" << std::endl;
        return 1;
    }

    if(verify(argv[1], argv[2], atoi(argv[3]))){
        std::cout << "Verification Passed!" << std::endl;
        return 0;
    }else{
        std::cout << "Incorrect, not verified!" << std::endl;
        return 1;
    }
}