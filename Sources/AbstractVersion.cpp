#include "AbstractVersion.hpp"

void AbstractStrategy::set_n(int n){
    this->n = n;
}

void AbstractStrategy::set_m(int m){
    this->m = m;
}

void AbstractStrategy::set_matrix(std::vector<std::vector<int>> matrix){
    this->matrix = matrix;
}