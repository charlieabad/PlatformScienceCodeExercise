// File:    defs.h 
// Created: November 27, 2022
// Author:  Charlie Abad
// Purpose: List all macro definitions used by this program

#pragma once

// Program definitions
#define ERR_CODE_SUCCESS 0

#define FILE_ONE_ARG 1
#define FILE_TWO_ARG 2

#define MAX_ROW_SIZE 512

#define REQUIRED_PARAM_COUNT 3

// Note: Termination codes no longer apply to modern operating systems (set all exit values to zero)
#define TERMINATE_INVALID_PARAM 0
#define TERMINATE_PARAM_ONE 0
#define TERMINATE_PARAM_TWO 0
#define TERMINATE_OK 0