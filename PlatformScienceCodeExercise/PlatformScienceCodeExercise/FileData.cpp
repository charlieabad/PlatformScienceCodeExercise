
// File:    FileData.cpp 
// Created: November 27, 2022
// Author:  Charlie Abad
// Purpose: Define class for file data functions.

// Class declaration
#include "FileData.h"
#include "defs.h"

// Some classes will need to override this basic function
std::string FileData::parse_data(std::string s)
{
    return s;
}

// Set class variables
void FileData::setup(void)
{
    this->row = parse_data(this->row);

    this->size_row = (int)row.size();

    if ((this->size_row % 2) == 0)
    {
        this->even_count = true;
    }
    else
    {
        this->even_count = false;
    }

    if (this->size_row > 0)
    {
        this->valid_case = true;
    }
    else
    {
        this->valid_case = false;
    }
}

// Get SS 
double FileData::get_suitability_score(void)
{
    return this->suitability_score;
}

// Reset class variables
void FileData::reset(void)
{
    this->size_row = -1;
    this->even_count = false;
    this->valid_case = false;
    this->suitability_score = 0.0;
}

// Get variable values
int FileData::is_even(void)
{
    return this->even_count;
}

int FileData::is_valid(void)
{
    return this->valid_case;
}

std::string FileData::get_row(void)
{
    return this->row;
}

// Override set operator
void FileData::operator=(std::string str)
{
    this->row = str;
    this->setup();
}

// Override the other set operator
void FileData::operator+=(std::string str)
{
    this->row = this->row + str;
    this->setup();
}
