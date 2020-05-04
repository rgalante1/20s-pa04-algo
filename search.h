//Riley Galante, Seqeunce Search Problem Solutions, CS 3353
#ifndef SEARCH_H
#define SEARCH_H

template<typename T>
class Search{
public:
    virtual int search(T[], int size, T) = 0;
};

template<typename T>
class LinearSearch: public Search<T>{
public:
    int search(T arr[], int size, T key){
        //trivial solution:
        //iterate through entire array until key is found
        //return -1 if key is not found
        //Time Complexity: O(n)
        for(int i = 0; i < size; i++){
            if(arr[i] == key)
                return i;
        }
        return -1;
    }
};

template<typename T>
class TernarySearch: public Search<T>{
public:
    int search(T arr[], int size, T key){
        //advanced solution (assuming sorted array):
        //searches by thirds
        //return -1 if key is not found
        //Time Compexity: O(log3(n))

        //left-most index
        int l = 0;
        //right-most index
        int r = size-1;

        while (r >= l){
            //divides array or subarray (depending on what l and r are)
            //into thirds
            //mid1 represents the boundary between third 1 and 2
            //mid2 represents the boundary between third 2 and 3
            int mid1 = l + (r-l)/3;
            int mid2 = r - (r-l)/3;

            if(arr[mid1] == key)
                return mid1;
            if(arr[mid2] == key)
                return mid2;

            //if key is in third 1, next search will be conducted in third 1 only
            if(key < arr[mid1])
                r = mid1-1;

            //if key is in third 3, next search will be conducted in third 3 only
            else if(key > arr[mid2])
                l = mid2+1;

            //else, key exists in third 2, so next search will be conducted in third 2 only
            else{
                l = mid1+1;
                r = mid2-1;
            }
        }
        return -1;
    }
};

template<typename T>
class BinarySearch: public Search<T>{
public:
    int search(T arr[], int size, T key){
        //more advanced solution (assuming sorted array):
        //divides array in 2 to narrow searches
        //returns -1 if key not found
        //Time Complexity: O(log2(n))

        //left-most index
        int l = 0;
        //right-most index
        int r = size-1;

        while (l <= r){
            //divide array or subarray(depending on l and r) into 2
            int mid = l + (r-l)/2;

            if(arr[mid] == key)
                return mid;

            //if key is in first half, next search will be done on first half only
            if(key < arr[mid])
                r = mid-1;

            //else, key is in second half, so next search will be done on second half only
            else{
                l = mid+1;
            }
        }
        return -1;
    }
};

#endif // SEARCH_H
