#include <iostream>
#include <string>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Sort(int* arr, int n, int* idx) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swap(idx[j], idx[j + 1]);
            }
        }
    }
}

void cariRanking(int* skor, int n) {
    int* idx = new int[n];
    for (int i = 0; i < n; i++) {
        idx[i] = i;
    }

    Sort(skor, n, idx);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            std::cout << "Gold Medal";
        }
        else if (i == 1) {
            std::cout << "Silver Medal";
        }
        else if (i == 2) {
            std::cout << "Bronze Medal";
        }
        else {
            std::cout << i + 1;
        }
        std::cout << " ";
    }

    delete[] idx;
}

int main() {
    int skor[] = { 10, 3, 8, 9, 4 };
    int n = sizeof(skor) / sizeof(skor[0]);

    cariRanking(skor, n);

    std::cout << std::endl;

    return 0;
}



//// RelativeSortArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//#include <algorithm>
//
//void relativeSort(int arr1[], int arr2[], int m, int n) {
//    int count[1001] = { 0 };
//
//    // Count the frequency of each element in arr1
//    for (int i = 0; i < m; i++) {
//        count[arr1[i]]++;
//    }
//
//    int index = 0;
//
//    // Sort the elements in arr1 based on the relative order in arr2
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < count[arr2[i]]; j++) {
//            arr1[index++] = arr2[i];
//        }
//        count[arr2[i]] = 0;
//    }
//
//    // Sort the elements that are not in arr2
//    for (int i = 0; i < 1001; i++) {
//        for (int j = 0; j < count[i]; j++) {
//            arr1[index++] = i;
//        }
//    }
//}
//
//int main() {
//    int arr1[] = { 2,3,1,3,2,4,6,7,9,2,19 };
//    int arr2[] = { 2,1,4,3,9,6 };
//    int m = sizeof(arr1) / sizeof(arr1[0]);
//    int n = sizeof(arr2) / sizeof(arr2[0]);
//
//    relativeSort(arr1, arr2, m, n);
//
//    for (int i = 0; i < m; i++) {
//        std::cout << arr1[i] << " ";
//    }
//
//    return 0;
//}


// 
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
//    int index_map[1001] = { 0 };
//    int max_element = 0;
//    for (int i = 0; i < arr2.size(); i++) {
//        index_map[arr2[i]] = i + 1;
//        max_element = std::max(max_element, arr2[i]);
//    }
//
//    std::sort(arr1.begin(), arr1.end(), [&](int a, int b) {
//        if (index_map[a] && index_map[b]) {
//            return index_map[a] < index_map[b];
//        }
//        else if (index_map[a]) {
//            return true;
//        }
//        else if (index_map[b]) {
//            return false;
//        }
//        else {
//            return a < b;
//        }
//        });
//
//    int end = arr1.size();
//    for (int i = 0; i < end; i++) {
//        if (!index_map[arr1[i]]) {
//            int j = i + 1;
//            while (j < end && !index_map[arr1[j]]) {
//                j++;
//            }
//            std::sort(arr1.begin() + i, arr1.begin() + j);
//            i = j - 1;
//        }
//    }
//
//    return arr1;
//}
//
//int main() {
//    std::vector<int> arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
//    std::vector<int> arr2 = { 2,1,4,3,9,6 };
//    auto result = relativeSortArray(arr1, arr2);
//    for (int num : result) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//    return 0;
//}
//
//
//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug program: F5 or Debug > Start Debugging menu
//
//// Tips for Getting Started: 
////   1. Use the Solution Explorer window to add/manage files
////   2. Use the Team Explorer window to connect to source control
////   3. Use the Output window to see build output and other messages
////   4. Use the Error List window to view errors
////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
