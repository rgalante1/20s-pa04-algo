#ifndef TEST_H
#define TEST_H
#include "search.h"
#include <chrono>
#include <iostream>
#include <fstream>
using namespace std;
using namespace std::chrono;

class Test{
private:
    int test1size = 100;
    int test1arr[100];
    int test2size = 1000000;
    int test2arr[1000000];
    Search<int>* ptr;
    ofstream out;
public:
    Test();
    void test1();
    void test2();
};

#endif // TEST_H
