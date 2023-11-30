#include "geneML.h"

void readCSV(const std::string& filename, std::vector<int>& labels, std::vector<std::string>& geneData) {
    std::ifstream input(filename);
    std::string line{};
    if (!input.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    while (input) {
        std::getline(input, line);
        int ind {};
        ind = line.find("\r", 0);
        if (ind != std::string::npos) {
            line.erase(ind, 2);
        }

        std::string index, label, sequence, temp;

        std::stringstream lineStr(line);

        std::getline(lineStr, index, ',');
        std::getline(lineStr, label, ',');
        std::getline(lineStr, sequence);

        labels.push_back(std::stoi(label));
        geneData.push_back(sequence);
    }
}

std::vector<std::vector<int>> processSequences(std::vector<std::string>& geneData) {
    std::unordered_map<char, int> charMap;
    std::vector<std::vector<int>> encodedGenes;

    int i = 1;
    for (std::string& sequence : geneData) {
        std::vector<int> encodedSequence;
        for (char c : sequence) {
            if (charMap.find(c) == charMap.end()) {
                charMap[c] = i++;
            }
            encodedSequence.push_back(charMap[c]);
        }
        encodedGenes.push_back(encodedSequence);
    }
    return encodedGenes;
}

int main() {
    std::vector<int> labels;
    std::vector<std::string> data;

    readCSV("antibiotic_gene_data.csv", labels, data);
    std::vector<std::vector<int>> encoded = processSequences(data);

    return 0;
}