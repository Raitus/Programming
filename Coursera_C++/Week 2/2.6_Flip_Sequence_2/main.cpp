#include <vector>

std::vector<int> Reversed(const std::vector<int>& v){
    std::vector<int> v2;
    v2.begin();
    for (int i = 0; i < v.size(); ++i) {
        v2.push_back(v[v.size()-1-i]);
    }
    return v2;
}