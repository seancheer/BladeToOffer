#pragma once
#include "common.h"
#define BOOL_TO_STRING(__value) {	\
	if (__value){ puts("true");} else{puts("false");}}

void swap(int* left, int* right);

void swap(char* left, char* right);

bool equals_double(double left, double right);
