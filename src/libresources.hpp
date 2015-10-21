//
// 
// libresources.hpp
// 
// LIB_RESOURCES_HPP
// 
// libresources.h
//
// Created by Marcello Tavano on 7/7/14.
// Copyright (c) 2014 xxx. All rights reserved.

#ifndef LIB_RESOURCES_HPP
#define LIB_RESOURCES_HPP

#include <vector>
#include <cstddef>

using std::vector;
using std::size_t;

// begin containers section

template <class T> class Matrix {
    public: 
        Matrix(const size_t& r, const size_t& c,const T& fill = T()) :
                                mRows_(r), mColumns_(c), mData_(r*c, fill) {}
    size_t rows() const {
        return mRows_; 
    }
    size_t columns() const {
        return mColumns_;
    }
    size_t elements() const {
        return mData_.size();
    }
    T* operator[] (size_t r) {
        return &mData_[r*columns()];
    }
    const T* operator[] (size_t r) const {
        return &mData_[r*columns()];
    }
    private:
        size_t mRows_;
        size_t mColumns_;
        vector<T> mData_;
};

// end containers section

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// begin algorithms section
// 
// 
// Breadth-first search
#include <queue>
using std::queue;
// 
template <class T>
vector<size_t> bfSearch(const Matrix<T>& matAdj, const int& root) {
    // should be equal to matAdj.columns()
    size_t numNodes = matAdj.rows();
    queue<size_t> qSol;
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
// 
// Deep-fisrt search
// 
#include <stack>
using std::stack;
// 
template <class T>
vector<size_t> dfSearch(const Matrix<T>& matAdj, const int& root) {
    // should be equal to matAdj.columns()
    size_t numNodes = matAdj.rows();
    stack<size_t> stSol;
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
// 
// 
// 
// 
// Dijstra & minDistance
// 
#include <limits>
#include <cstdint>
// 
typedef std::numeric_limits<int> nLimits;
typedef const bool kBool;
typedef const int kInt;

int minDistance(const vector<int> &dist, kBool sptSet[], kInt V){
   int min = nLimits::max(), min_index;
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false and dist[v] <= min)
         min = dist[v], min_index = v;
   return min_index;
}

template <typename T>
void dijkstra(const Matrix<T>& matAdj, vector<int>  &dist ,kInt &src, kInt &V){
     bool sptSet[V];
     for (int i = 0; i < V; i++)
        dist[i] = nLimits::max(), sptSet[i] = false;
     dist[src] = 0;
     for (int count = 0; count < V-1; count++) {
       int u = minDistance(dist, sptSet,V);
       sptSet[u] = true;
       for (int v = 0; v < V; v++)
         if (!sptSet[v] and matAdj[u][v] and dist[u] != nLimits::max() 
                                       and dist[u]+matAdj[u][v] < dist[v])
            dist[v] = dist[u] + matAdj[u][v];
     } 
}




// end algorithms section

#endif //LIB_RESOURCES_HPP
