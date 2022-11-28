// File:    FileNameData.h 
// Created: November 27, 2022
// Author:  Charlie Abad
// Purpose: Define class to manage the name file.

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileNameData
{
private:

    std::string row = "empty";
    int size_row = -1;
    int even_count = false;
    int valid_case = false;
    double suitability_score = 0.0;

    int vowel_count = 0;
    int consonant_count = 0;

public:

    // Class constructor
    FileNameData(std::string str);

    // Show people's names properly
    // Capitalize the first character of each driver's name
    std::string format_name(std::string name);

    // Set class variables
    void setup(void);

    // Reset class variables
    void reset(void);

    // Count vowels in the user's name
    void parse(void);
    std::string parse_data(std::string s);
    
    // Get/Set class variables
    int get_vowel_count(void);
    int get_consonant_count(void);
    std::string get_row(void);
    int is_even(void);
    double get_suitability_score(void);
    void set_suitability_score(double d);
};