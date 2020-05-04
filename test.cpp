#include "test.h"

Test::Test(){
    //populate arrays
    for(int i = 0; i < test1size; i++){
        //arr values will range from 1 to 100
        test1arr[i] = i+1;
    }
    for(int i = 0; i < test2size; i++){
        //arr values will range from 2 to 2000000
        test2arr[i] = (i+1)*2;
    }
}

void Test::test1(){
    //choosing a key that does not exist in array will force worse case performance
    int key = 200;

    out.open("output.txt");

    out << "Test 1: " << endl;

    //Linear Search timed performance test
    ptr = new LinearSearch<int>();
    auto start = high_resolution_clock::now();
    int result = ptr->search(test1arr, test1size, key);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    out << "Linear Search Performance: " << duration.count() << " nanoseconds" << endl;
    (result == -1)? out << "Key not found in array" << endl : out << "Key Found! Index: " << result << endl;
    delete ptr;

    //Ternary Search timed performance test
    ptr = new TernarySearch<int>();
    start = high_resolution_clock::now();
    result = ptr->search(test1arr, test1size, key);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end-start);
    out << "Ternary Search Performance: " << duration.count() << " nanoseconds" << endl;
    (result == -1)? out << "Key not found in array" << endl : out << "Key Found! Index: " << result << endl;
    delete ptr;

    //Binary Search timed performance test
    ptr = new BinarySearch<int>();
    start = high_resolution_clock::now();
    result = ptr->search(test1arr, test1size, key);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end-start);
    out << "Binary Search Performance: " << duration.count() << " nanoseconds" << endl;
    (result == -1)? out << "Key not found in array" << endl : out << "Key Found! Index: " << result << endl;
    delete ptr;

    out << "End of Test 1" << endl << endl;
}

void Test::test2(){
    int key = 1800000;

    out << "Test 2: " << endl;

    //Linear Search timed performance test
    ptr = new LinearSearch<int>();
    auto start = high_resolution_clock::now();
    int result = ptr->search(test2arr, test2size, key);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    out << "Linear Search Performance: " << duration.count() << " nanoseconds" << endl;
    (result == -1)? out << "Key not found in array" << endl : out << "Key Found! Index: " << result << endl;
    delete ptr;

    //Ternary Search timed performance test
    ptr = new TernarySearch<int>();
    start = high_resolution_clock::now();
    result = ptr->search(test2arr, test2size, key);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end-start);
    out << "Ternary Search Performance: " << duration.count() << " nanoseconds" << endl;
    (result == -1)? out << "Key not found in array" << endl : out << "Key Found! Index: " << result << endl;
    delete ptr;

    //Binary Search timed performance test
    ptr = new BinarySearch<int>();
    start = high_resolution_clock::now();
    result = ptr->search(test2arr, test2size, key);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end-start);
    out << "Binary Search Performance: " << duration.count() << " nanoseconds" << endl;
    (result == -1)? out << "Key not found in array" << endl : out << "Key Found! Index: " << result << endl;
    delete ptr;

    out << "End of Test 2" << endl;
}
