#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int majorityElement(std::vector<int>& nums) {
    std::map<int, unsigned int> frequencyCount;
    for (auto a : nums) {
        frequencyCount[a]++;
    }

    auto pr = std::max_element(
        std::begin(frequencyCount), std::end(frequencyCount),
        [](const std::map<int, unsigned int>::value_type& p1, const std::map<int, unsigned int>::value_type& p2) {
            return p1.second < p2.second;
        });
    return pr->first;
}

int main() {
    std::vector<int> vec = {2, 2, 1, 1, 1, 2, 2};
    std::cout << majorityElement(vec) << std::endl;
    return 0;
}