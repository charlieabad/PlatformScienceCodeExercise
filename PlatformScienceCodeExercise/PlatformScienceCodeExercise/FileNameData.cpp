// File:    FileNameData.h 
// Created: November 27, 2022
// Author:  Charlie Abad
// Purpose: Define class to manage the name file functions.

// Class declaration
#include "FileNameData.h"
#include "defs.h"

// Class constructor
FileNameData::FileNameData(std::string str)
{
    this->row = format_name(str);
    this->setup();
}

// Set class variables
void FileNameData::setup(void)
{
    this->row = format_name(this->row);
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

// Reset class variables
void FileNameData::reset(void)
{
    this->size_row = -1;
    this->even_count = false;
    this->valid_case = false;
    this->suitability_score = 0.0;
}

// Show people's names properly
// Capitalize the first character of each driver's name
std::string FileNameData::format_name(std::string name)
{
    int i = (int)name.size();
    int k = false;

    for (int j = 0; j < i; j++)
    {
        int c = name.at(j);

        if (isspace(c))
        {
            k = false;
        }
        else
        {
            if (isalpha(c))
            {
                if (k == false)
                {
                    c = toupper(c);
                    k = true;
                }
                else
                {
                    c = tolower(c);
                }
            }
        }

        name[j] = c;
    }

    return name;
}

// Count vowels in the user's name
std::string FileNameData::parse_data(std::string s)
{
    this->vowel_count = 0;
    this->consonant_count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        // Make sure we have a letter
        if (isalpha(s[i]))
        {
            // The following letters are defined as vowels in American English!
            if ((s[i] == 'A') || (s[i] == 'a')
                || (s[i] == 'E') || (s[i] == 'e')
                || (s[i] == 'I') || (s[i] == 'i')
                || (s[i] == 'O') || (s[i] == 'o')
                || (s[i] == 'U') || (s[i] == 'u')
                || (s[i] == 'Y') || (s[i] == 'y'))
            {
                this->vowel_count++;
            }
            else
            {
                // These are not vowels - tally
                this->consonant_count++;
            }
        }
    }

    return s;
}

// Parse interface
void FileNameData::parse(void)
{
    this->setup();
}

// Get / Set class variables

double FileNameData::get_suitability_score(void)
{
    return this->suitability_score;
}

void FileNameData::set_suitability_score(double d)
{
    this->suitability_score = d;
}

int FileNameData::get_vowel_count(void)
{
    return this->vowel_count;
}

int FileNameData::get_consonant_count(void)
{
    return this->consonant_count;
}

std::string FileNameData::get_row(void)
{
    return this->row;
}

int FileNameData::is_even(void)
{
    return this->even_count;
}


