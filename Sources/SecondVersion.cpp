#include "SecondVersion.hpp"

SecondAlgorithm::SecondAlgorithm(int n, int m, std::vector<std::vector<int>> matrix) 
{
    this->n = n;
    this->m = m;
    this->matrix = matrix;
}

std::vector<int> SecondAlgorithm::solve()
{
    //iteration zero
    this->count_iterations = 0;
    std::vector<int> r;
    std::vector<int> c;
    for (int i = 0; i < this->n; i++) r.push_back(i);
    for (int i = 0; i < this->m; i++) c.push_back(i);
    std::vector<int> result;
    while(!c.empty() && !r.empty()){
        int mx = -1;
        int idDel = -1;
        for (int i = 0; i < r.size(); i++)
        {
            int cnt = 0;
            for (int posc : c)
            {
                //iteration to count
                this->count_iterations++;
                cnt += this->matrix[r[i]][posc];
            }
            if(cnt > mx)
            {
                mx = cnt;
                idDel = i;
            }
        }
        if(idDel == -1) break;
        std::vector<int> newC;
        for (int posc : c)
        {
            //iteration to count
            this->count_iterations++;
            if(this->matrix[r[idDel]][posc] == 0)
            {
                newC.push_back(posc);
            }
        }
        result.push_back(r[idDel]);
        r.erase(r.begin() + idDel);
        c = newC;
    }
    return result;
}

