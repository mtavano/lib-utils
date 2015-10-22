//          Copyright Marcello Tavano Lanas August 2014
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <queue>

#include "../containers/matrix.hpp"

#ifndef BFS_HPP
#define BFS_HPP

template <class T>
vector<size_t> bfSearch(const Matrix<T>& matAdj, const int& root) {
    // should be equal to matAdj.columns()
    size_t numNodes = matAdj.rows();
    std::queue<size_t> qSol;
    vector<bool> explored(numNodes, false);
    vector<size_t> visited;
    qSol.push(root);
    explored[root]=true;
    while(!qSol.empty()) {
        size_t current = qSol.front();
        qSol.pop();
        visited.push_back(current);
        for(size_t i = 0; i != numNodes;  ++i) {
            if(!explored[i] and matAdj[current][i]) {
                qSol.push(i);
                explored[i]=true;
            }
        }
    }
  return visited;
}

#endif