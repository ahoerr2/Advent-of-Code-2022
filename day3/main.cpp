#include <__concepts/arithmetic.h>
#include <__concepts/same_as.h>
#include <_types/_uint32_t.h>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <ostream>
#include <set>
#include <string>
#include <vector>
#include "Util.h"


int main(int, char**){
    std::cout << "Hello, from day3_aoc2020!\n";
    std::cout << "Project for Advent of Code 2022, Day 3!\n";
    std::cout << "\n";

    std::string text_line;
    std::fstream input_text("day3_input.txt");
    std::vector<char> matched_chars;
    auto insertMatchedChars = [&](const auto& str1, const auto& str2, auto& matched_chars){
        for(size_t i = 0; i < str1.size(); i++){
            for(size_t j = 0; j < str2.size(); j++){
                if (str1[i] == str2[j]){
                    matched_chars.push_back(str2[j]);
                    return;
                }
            }
        }
    };

    auto insertMatchedChars2 = [&](const auto& str1, const auto& str2, auto& matched_chars){
        for(size_t i = 0; i < str1.size(); i++){
            for(size_t j = 0; j < str2.size(); j++){
                if (str1[i] == str2[j]){
                    matched_chars.push_back(str2[j]);
                }
            }
        }
    };

    while(std::getline(input_text,text_line)){
        std::string str1 = text_line.substr(0,text_line.size() / 2);
        std::string str2 = text_line.substr(text_line.size() / 2, text_line.size());
        insertMatchedChars(str1, str2, matched_chars);
    }

    int UppercaseConversionNum = 'A' - 27;
    int LowercaseConversionNum = 'a' - 1;
    int final_score = 0;

    auto findMatchedItemScore = [&](int item){
        if(item >= 'a' && item <= 'z'){
            return item - LowercaseConversionNum;
        }

        if(item >= 'A' && item <= 'Z'){
            return item - UppercaseConversionNum;
        }

        return 0;
    };

    for (auto & item : matched_chars){
        final_score += findMatchedItemScore(item);
    }

    std::cout << "Final Score: " << final_score << std::endl;
    input_text.close();

    std::cout << "Part 2: " << std::endl;

    uint32_t line_amt = 0;
    std::vector<std::string> rucksack = {};
    std::vector<char> group_vals = {};

    auto populateRuckSack = [](uint32_t& line_amt, std::string text_line, std::vector<std::string>& rucksack){
        rucksack.push_back(text_line);
        line_amt+= 1;
        return;
    };

    auto findGroupVal = [&](const uint32_t& line_amt, auto& rucksack){
        std::vector<char> matches = {};
        if(line_amt > 2){
            insertMatchedChars2(rucksack[0], rucksack[1], matches);
            insertMatchedChars2(matches, rucksack[2], group_vals);
            Util::printVector(group_vals, "Matches");
        }
    };

    auto findBestScore = [&](const std::vector<char>& vec){
        uint32_t bestScore = 0;
        for (auto item : vec){
            bestScore = (findMatchedItemScore(item) > bestScore) ? findMatchedItemScore(item) : bestScore;
        }
        return bestScore;
    };

    input_text.open("day3_input.txt");

    std::vector<uint32_t> best_vals = {};

    while(std::getline(input_text,text_line)){
        populateRuckSack(line_amt, text_line, rucksack);
        findGroupVal(line_amt, rucksack);

        if (line_amt > 2){
            std::cout << "Best Score: " << findBestScore(group_vals) << " : " << (char) findBestScore(group_vals) << std::endl;
            best_vals.push_back(findBestScore(group_vals));
            rucksack.clear();
            group_vals.clear();
            line_amt = 0;
        }
        
    }

    uint32_t score = 0;
    for (auto item : best_vals){
        score += item;
    }

    std::cout << "Final Score: " << score << std::endl;

    return 0;
}
