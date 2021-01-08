#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum3(int k, int n) {
            vector<vector<int>> res = {};
            vector<int> sequence = {};
            int x = n - (k * (k-1))/2;
            cout << "x: " << x << "\n";
            for (int i=1; i < k; i++) {
                sequence.push_back(i);
            }
            sequence.push_back(x);

            for (int i=0; sequence[k - 1] > sequence[k - 2]; i++) {
                cout << this->printSequence(sequence) << "\n";
                if (sequence[k-1] > 9 || sequence[k-2] > 9)
                    continue;
                res.push_back(sequence);
                
                sequence[k - 1] = sequence[k - 1] - 1;
                int updateIndex = k - 2 - (i % (k-1));
                sequence[updateIndex] = sequence[updateIndex] + 1;
            }
            return res;
            
        };
        string printSequence(vector<int>& s) {
            if (!s.size())
                return "";
            string ret = "[";
            ret += to_string(s[0]);
            for (int i=1; i < s.size(); i++) {
                ret += "," + to_string(s[i]);
            };
            return ret + "]";
        };
};

int main(int argc, char** argv) {
    const int nargs = 2;
    if (argc != nargs + 1) {
        cout << "Invalid number of args: Expected " << to_string(nargs) << " but got " << to_string(argc - 1) << "\n";
        return 1;
    };
    for (int i = 1; i < nargs + 1; i++) {
        cout << "Arg " << to_string(i) << ": " << string(argv[i]) << "\n";
    };
    Solution sol = Solution();
    vector<vector<int>> ans = sol.combinationSum3(atoi(argv[1]), atoi(argv[2]));
    return 0;
}
/* SOLUTION

 - Minimum sum for k elements is k(k+1)/2
 - => Minimum sum for k-1 elements is k(k-1)/2

 - Let x = n - k(k-1)/2
 - x is the final element of the combination => all other elements must sum to k(k-1)/2
 - If x is less than or equal to k-1 then there are no valid combinations, since there can be no repeated numbers
 
 - Increase left sequence by 1 and decrease final number by 1 
 - Increase elements of left sequence from right-to-left with each increment

 */