#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("timbre.in");
ofstream g("timbre.out");

long long costMin;

int main() {
   
    int numPages, numIntervals, maxSubseqLength;
    f >> numPages >> numIntervals >> maxSubseqLength;

    // Vector de perechi pentru a stoca marginea superioara a intervalului si costul fiecaruia
    vector<pair<int, int>> intervals(numIntervals);

   
    for (int i = 0; i < numIntervals; i++) 
        f >> intervals[i].first >> intervals[i].second;
    
    while (numPages > 0) {
        int bestIntervalIndex = -1;
        int minCost = 10001;
       
        for (int i = 0; i < numIntervals; i++) 
            if (intervals[i].first >= numPages && intervals[i].second < minCost && intervals[i].first != -1) 
            {
                bestIntervalIndex = i;
                minCost = intervals[i].second;
            }
        
        costMin += minCost;
        intervals[bestIntervalIndex].first = -1;
        numPages -= maxSubseqLength;
    }

    
    g << costMin;
    f,g.close();
    return 0;
}
