// File:    PlatformScienceCodeExercise.cpp 
// Created: November 27, 2022
// Author:  Charlie Abad
// Purpose: Job evaluation. Start application.

// Compile control features
// #define ENABLE_DEBUG_CODE

// What public interfaces do we need?
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// What project interfaces do we need?
#include "defs.h"
#include "FileData.h"
#include "FileStreetData.h"
#include "FileNameData.h"
#include "RowData.h"

// Allow access to common C++ functionality
using namespace std;

// Application global variables (avoid using the local heap)
vector<FileStreetData> list_addresses;
vector<FileNameData> list_names;
vector<RowData> list_report;
vector<string> list_avoid_dups;

// Functions

// Borrowed function from StackOverflow!
// https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
std::string trim(const std::string& str, const std::string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
    {
        return ""; // no content
    }


    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

// Application starts here
int main(int argc, char* argv[])
{
    // Introduce the software to the user
    std::cout << endl;
    std::cout << "Platform Science Code Exercise" << endl;
    std::cout << "By Charlie Abad" << endl;
    std::cout << "Version 2.0.0" << endl; // Never label a program as a one point zero (people are superstitous)
    std::cout << endl;

    // The program requires two command line arguments
    // Note: the first command line argument will be the execution path of this program (per C/C++ standard)
    if (argc != REQUIRED_PARAM_COUNT)
    {
        std::cout << "Invalid command line arguments!" << endl << endl;
        std::cout << "PlatformScienceCodeExercise.exe addressFile.txt namesFile.txt" << endl;
        std::cout << endl;
        return TERMINATE_INVALID_PARAM;
    }

    // Do the specified files exist?
    // Note: the only way to verify a file exists using C/C++ is to open it.

    // Verify the first file exists
    errno_t error_code = ERR_CODE_SUCCESS;
    FILE* file_check;

    // Open the file in read only mode
    error_code = fopen_s(&file_check, argv[FILE_ONE_ARG], "r");

    if ((error_code != ERR_CODE_SUCCESS) || (file_check == NULL))
    {
        std::cout << "File does not exits or permission error: " << argv[FILE_ONE_ARG] << endl;
        std::cout << endl;
        return TERMINATE_PARAM_ONE;
    }

    // Close and reset the first file
    fclose(file_check);
    file_check = NULL;

    // Verify the second file exists
    error_code = fopen_s(&file_check, argv[FILE_TWO_ARG], "r");

    if ((error_code != ERR_CODE_SUCCESS) || (file_check == NULL))
    {
        std::cout << "File does not exits or permission error: " << argv[FILE_TWO_ARG] << endl;
        std::cout << endl;
        return TERMINATE_PARAM_TWO;
    }

    // Close and reset the first file
    fclose(file_check);
    file_check = NULL;

    // Process the data in the first file
    ifstream fileObj_one(argv[FILE_ONE_ARG]);

    if (fileObj_one.is_open())
    {
        std::string line;
        while (getline(fileObj_one, line))
        {
            if (line.size() > 0)
            {
                FileStreetData fileOneObj(trim(line));
                list_addresses.push_back(fileOneObj);

#ifdef ENABLE_DEBUG_CODE
                std::cout << line << endl;
#endif 
            }
        }

        fileObj_one.close();
    }
    else
    {
        std::cout << "Failed to process file one: " << argv[FILE_ONE_ARG] << endl;
        std::cout << endl;
        return TERMINATE_PARAM_ONE;
    }

    // Process the data in the second file
    ifstream fileObj_two(argv[FILE_TWO_ARG]);

    if (fileObj_two.is_open())
    {
        std::string line;
        while (getline(fileObj_two, line))
        {
            if (line.size() > 0)
            {
                FileNameData fileTwoObj(trim(line));
                list_names.push_back(fileTwoObj);

#ifdef ENABLE_DEBUG_CODE
                std::cout << line << endl;
#endif
            }
        }

        fileObj_two.close();
    }
    else
    {
        std::cout << "Failed to process file two: " << argv[FILE_TWO_ARG] << endl;
        std::cout << endl;
        return TERMINATE_PARAM_ONE;
    }

#ifdef ENABLE_DEBUG_CODE

    // Build the header
    printf("%20s    %10s    %20s     C,    V     %s\n",
        "Street",
        "O/E",
        "Name",
        "SS");

#endif 

    // Build the report for the user
    int file_one_count = (int)list_addresses.size();
    int file_two_count = (int)list_names.size();

    const string even_txt = "Even";
    const string odd_txt = "Odd";
    string odd_or_event;

    for (int i = 0; i < file_one_count; i++)
    {
        FileStreetData temp1 = list_addresses[i];

        temp1.parse();

        if (temp1.is_even())
        {
            odd_or_event = even_txt;
        }
        else
        {
            odd_or_event = odd_txt;
        }

        for (int j = 0; j < file_two_count; j++)
        {
            FileNameData temp2 = list_names[j];
            double d = 0.0;

            temp2.parse();

            if (temp1.is_even())
            {
                // Requirement 1
                d = temp2.get_vowel_count() * 1.5;
            }
            else
            {
                // Requirement 2
                d = temp2.get_consonant_count() * 1.0;
            }

            // Requirement 3 (increase by 50% if the length of the street and driver as the same)
            if (temp1.get_row().size() == temp2.get_row().size())
            {
                d = d * 1.5;
            }

#ifdef ENABLE_DEBUG_CODE

            // Display the data and the values calculated
            printf("%20s -- %10s -- %20s (%4d, %4d) -> %.2f\n",
                temp1.get_row().c_str(),
                odd_or_event.c_str(),
                temp2.get_row().c_str(),
                temp2.get_consonant_count(),
                temp2.get_vowel_count(),
                d);
#endif 

            // Update the report queue
            RowData row;
            row.street = temp1.get_row();
            row.name = temp2.get_row();
            row.ss = d;

            list_report.push_back(row);
        }
    }

    // Sort the report data by SS
    int i = (int)list_report.size();

    if (i > 0)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < i; k++)
            {
                if (j != k)
                {
                    RowData row1 = list_report.at(j);
                    RowData row2 = list_report.at(k);

                    if (row1.ss > row2.ss)
                    {
                        list_report[j] = row2;
                        list_report[k] = row1;
                    }
                }
            }
        }

        for (int j = 0; j < i; j++)
        {
            // Look for duplicates
            int k = (int)list_avoid_dups.size();
            int dup = false;

            if (k > 0)
            {
                for (int m = 0; m < k; m++)
                {
                    std::string nam = list_avoid_dups[m];

                    if (nam == list_report[j].name)
                    {
                        dup = true;
                        break;
                    }
                }
            }

            // Display the data and the values calculated
            if (dup == false)
            {
                printf("%20s -- %20s -> %.2f\n",
                    list_report[j].street.c_str(),
                    list_report[j].name.c_str(),
                    list_report[j].ss);
            }

            // Avoid duplicate names
            list_avoid_dups.push_back(list_report[j].name.c_str());
        }
    }
    else
    {
        std::cout << "No Report Data" << endl;
    }

    // Report footer
    std::cout << endl;
    std::cout << "End Program";

    // End program
    return TERMINATE_OK;
}
