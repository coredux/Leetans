#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// submit the codes below

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;
        this->generateFreqMap( nums , freqMap );

        priority_queue<NumNode,vector<NumNode>,Comparator> heap;
        for ( auto i = freqMap.begin() ; i != freqMap.end(); ++i ) {
            heap.push( NumNode( (*i).first , (*i).second ) );
        }

        vector<int> ret;
        for ( int i = 0 ; i < k ; ++i ) {
            if ( !heap.empty() ) {
                ret.push_back( heap.top().value );
                heap.pop();
            }
        }
        return ret;
    }

private:

    struct NumNode {
        int value;
        int freq;
        NumNode( int val , int fre ) : value( val ) , freq( fre ) {}
    };

    struct Comparator {
        bool operator ()( const NumNode& a , const NumNode& b ) {
            return a.freq < b.freq;
        }
    };

    void generateFreqMap( vector<int>& nums , unordered_map<int,int>& freqMap ) {
        for ( auto i = nums.begin() ; i != nums.end() ; ++i ) {
            int nowNum = *i;
            if ( freqMap.find( nowNum ) != freqMap.end() ) {
                ++freqMap[ nowNum ];
            } else {
                pair<int,int> toInsert( nowNum , 1 );
                freqMap.insert( toInsert );
            }
        }
    }
};

// submit the codes above

int main() {
    Solution s;
    vector<int> inp = { 1,1,1,2,2,3};
    s.topKFrequent( inp , 2 );
    return 0;
}