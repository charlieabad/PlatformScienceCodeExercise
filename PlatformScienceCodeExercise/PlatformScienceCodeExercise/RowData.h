// File:    RowData.h 
// Created: November 27, 2022
// Author:  Charlie Abad
// Purpose: Define class to manage to store report data.

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class RowData
{
public:
    std::string street, name;
    double ss = 0.0;
    int duplicate = false;
};

