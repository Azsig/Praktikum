#include <iostream>
#include <string>
#include <vector>


struct AsciiConvEntry {
    std::string binary;
    char ascii;
};

std::vector<AsciiConvEntry> AsciiConv = {
    {"0000", 'A'}, {"0001", 'B'}, /* Tambahkan data biner lainnya dengan pasangan ASCII */
    {"0010", 'C'}, {"0011", 'D'}, {"0100", 'E'}, {"0101", 'F'}, {"0110", 'G'}, {"0111", 'H'},
    {"1000", 'I'}, {"1001", 'J'}, {"1010", 'K'}, {"1011", 'L'}, {"1100", 'M'}, {"1101", 'N'},
    {"1110", 'O'}, {"1111", 'P'}, // Dan seterusnya...
};

std::string convertData(const std::vector<std::string>& before) {
    std::string after = "";
    bool error;
    
    for (const std::string& bin_code : before) {
        error = true;
        for (const AsciiConvEntry& entry : AsciiConv) {
            if (bin_code == entry.binary) {
                after += entry.ascii;
                std::cout << after << std::endl;
                error = false;
                break;
            }
        }
        if (error) {
            std::cout << "Character not on the list" << std::endl;
        }
    }
    
    return after;
}

int main() {
    std::vector<std::string> before = {"1000", "0001", "0010", "0011"}; // Contoh input
    std::string result = convertData(before);
    std::cout << "Hasil: " << result << std::endl;
    return 0;
}
