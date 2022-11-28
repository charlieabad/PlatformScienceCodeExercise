// File:    FileStreetData.h 
// Created: November 27, 2022
// Author:  Charlie Abad
// Purpose: Define class to manage the street file.

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "FileData.h"

class FileStreetData : FileData
{
public:

    FileStreetData(std::string str);
    std::string get_row(void);
    int is_even(void);
    void parse(void);
};