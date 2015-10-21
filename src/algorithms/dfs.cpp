//          Copyright Marcello Tavano Lanas August 2014
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <stack>

#include "../containers/matrix.hpp"

#ifndef DFS_HPP
#define DFS_HPP

 
template <class T>
vector<size_t> dfSearch(const Matrix<T>& matAdj, const int& root) {
    // should be equal to matAdj.columns()
    size_t numNodes = matAdj.rows();
    std::stack<size_t> stSol;
    vector<bool> explored(numNodes, false);
    vector<size_t> visited;
    stSol.push(root);
    explored[root]=true;
    while(!stSol.empty()) {
        size_t current = stSol.top();
        stSol.pop();
        visited.push_back(current);
        for(size_t i = 0; i != numNodes;  ++i) {
            if(!explored[i] and matAdj[current][i]) {
                stSol.push(i);
                explored[i]=true;
            }
        }
    }
  return visited;
}
#endif