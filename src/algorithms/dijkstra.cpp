//          Copyright Marcello Tavano Lanas August 2014
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <limits>
#include <cstdint>

#include "../containers/matrix.hpp"

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
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


#endif