// File:    FileStreetData.cpp
// Created: November 27, 2022
// Author:  Charlie Abad
// Purpose: Define class functions to manage the street file.

#include "FileStreetData.h"

// Class constructor
FileStreetData::FileStreetData(std::string str)
{
    this->row = str;
    this->setup();
}

// Set class variables
void FileStreetData::parse(void)
{
    this->setup();
}

// Get class variables
std::string FileStreetData::get_row(void)
{
    return this->row;
}

int FileStreetData::is_even(void)
{
    return this->even_count;
}

