// File:    FileData.h 
// Created: November 27, 2022
// Author:  Charlie Abad
// Purpose: Define class to manage files.

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileData
{
protected:

    std::string row = "empty";
    int size_row = -1;
    int even_count = false;
    int valid_case = false;
    double suitability_score = 0.0;

public:

    // Some classes will need to override this basic function
    std::string parse_data(std::string s);

    // Set class variables
    void setup(void);

    // Reset class variables
    void reset(void);

    // Get class variables
    double get_suitability_score(void);
    int is_even(void);
    int is_valid(void);
    std::string get_row(void);

    // Override operators to simplify setting values
    void operator=(std::string str);
    void operator+=(std::string str);
};

