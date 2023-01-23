#include <stdint.h>
#include <iostream>
#include <map>
#include <vector>
#include <utility>

const uint32_t num_partitions = 100000;
const size_t num_elements = 500000;

void multimap_stat(const std::vector<std::pair<uint32_t, uint64_t>> *values){
    std::multimap<uint32_t, uint64_t> mumap;
    clock_t start = clock();
    for (auto iter = values->begin(); iter != values->end(); ++iter){
        mumap.insert(*iter);
    }
 
    clock_t stop = clock();
    std::cout << "Filling std::multimap: " << stop - start << " ticks" << std::endl;

    std::vector<uint64_t> sums;
    start = clock();
    for (uint32_t i = 0; i <= num_partitions; ++i){
        uint64_t sum = 0;
        auto range = mumap.equal_range(i);
        for (auto iter = range.first; iter != range.second; ++iter){
            sum += iter->second;
        }
        sums.push_back(sum);
    }
    stop = clock();
    std::cout << "Reading std::multimap: " << stop - start << " ticks" << std::endl;
}


void map_stat(const std::vector<std::pair<uint32_t, uint64_t>> *values){
    std::map<uint32_t, std::vector<uint64_t>> mumap;
    clock_t start = clock();
    for (auto iter = values->begin(); iter != values->end(); ++iter)
    {
        mumap[iter->first].push_back(iter->second);
    }
    clock_t stop = clock();
    std::cout << "Filling map: " << stop - start << " ticks" << std::endl;
    
    std::vector<uint64_t> sums;
    start = clock();
    for (uint32_t i = 0; i <= num_partitions; ++i)
    {
        uint64_t sum = 0;
        auto range = std::make_pair(mumap[i].begin(), mumap[i].end());
        for (auto iter = range.first; iter != range.second; ++iter)
        {
            sum += *iter;
        }
        sums.push_back(sum);
    }
    stop = clock();
    std::cout << "Reading map: " << stop - start << " ticks" << std::endl;
}

int main()
{
    srand(1337);
    std::vector<std::pair<uint32_t, uint64_t>> values;
    for (size_t i = 0; i <= num_elements; ++i)
    {
        uint32_t key = rand() % num_partitions;
        uint64_t value = rand();
        values.push_back(std::make_pair(key, value));
    }
    multimap_stat(&values);

    map_stat(&values);

    return 0;
}