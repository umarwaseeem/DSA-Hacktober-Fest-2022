#include <iostream>
#include <vector>

void shellSort(std::vector<int> &array) {
    for (int interval = array.size() / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < array.size(); i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

int main() {
    std::vector<int> array;
    printf("Please enter the total number of elements: ");
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        printf("Index %d: ", i);
        std::cin >> temp;
        array.push_back(temp);
    }
    shellSort(array);

    for (auto number : array) {
        printf("%d ", number);
    }
    printf("\n");
}