
#ifndef FINAL_FOR_CS3520_GENEML_H
#define FINAL_FOR_CS3520_GENEML_H
#include "mlpack/core.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

void readCSV(const std::string& filename, std::vector<int>& labels, std::vector<std::string>& geneData);
std::vector<std::vector<int>> processSequences(std::vector<std::string>& geneData);

#endif //FINAL_FOR_CS3520_GENEML_H
