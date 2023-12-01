
#ifndef FINAL_FOR_CS3520_GENEML_H
#define FINAL_FOR_CS3520_GENEML_H

#include <core/data/load.hpp>
#include <methods/random_forest/random_forest.hpp>
#include <core/cv/k_fold_cv.hpp>
#include <armadillo>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

void readCSV(const std::string& filename, std::vector<int>& labels, std::vector<std::string>& geneData);
std::vector<std::vector<int>> processSequences(std::vector<std::string>& geneData);

void runClassifier(const std::string& filename);
#endif //FINAL_FOR_CS3520_GENEML_H
