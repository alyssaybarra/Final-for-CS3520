#include "geneML.h"
using namespace mlpack;
using namespace arma;

void readCSV(const std::string& filename, std::vector<int>& labels, std::vector<std::string>& geneData) {
    std::ifstream input(filename);
    std::string line{};
    if (!input) {
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

        labels.push_back(std::stof(label));
        geneData.push_back(sequence);
    }
}

std::vector<std::vector<int>> processSequences(std::vector<std::string>& geneData) {
    std::unordered_map<char, int> charMap;
    std::vector<std::vector<int>> encodedGenes;

    double i = 1;
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

void runClassifier(const std::string& filename) {
    std::vector<int> oldLabels;
    std::vector<std::string> geneData;

    readCSV(filename, oldLabels, geneData);
    std::vector<std::vector<int>> processedData = processSequences(geneData);

    const size_t rows = processedData.size();
    const size_t cols = processedData[0].size();

    arma::mat dataset(cols, rows);
    for (size_t i = 0; i < processedData.size(); ++i) {
        for (size_t j = 0; j < processedData[0].size(); ++j) {
            dataset(j, i) = static_cast<double>(processedData[i][j]);
        }
    }

    arma::Row<size_t> labels = arma::conv_to<arma::Row<size_t>>::from(oldLabels);

    arma::mat trainX, testX;
    arma::Row<size_t> trainY, testY;
    data::Split(dataset, labels, trainX, testX, trainY, testY, 0.2);

    const size_t numClasses = 2;
    const size_t minimumLeafSize = 5;
    const size_t numTrees = 10;

    const size_t k = 10;

    KFoldCV<RandomForest<GiniGain, RandomDimensionSelect>, Accuracy> cv(k, trainX, trainY, numClasses);

    double cvAcc = cv.Evaluate(numTrees, minimumLeafSize);
    std::cout << "\nKFoldCV Accuracy: " << cvAcc;

}
