#pragma once

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>


// ------------- Helpers -------------
// todo: make index file export for the helpers classes
#include "class/helpers/benchmark-helpers.h"


// ------------- Classes -------------

#include "./class/stack/index.h"
#include "./class/lists/h-list.h"
#include "./class/math-expression.h"
#include "./class/dic.h"
// todo: make index export file for tree classes
#include "class/tree/tree.h"
#include "class/tree/binary_tree_search.h"
#include "class/tree/red_black_tree.h"

#include "class/data-structur.utils.h"


#define MAX_RAND_ELE 100'000

#define MAX_ELE 10'000'000
// 100 million
// #define STACK_INSERT_ELE_COUNT 100'000'000
#define STACK_INSERT_ELE_COUNT 10
