/*
 * 0.1 최대와 최소
 *
 * 두 개의 정수를 인자로 받아 둘 중 큰 값이나 작은 값을 반환하는 두 개의 함수를 구현
 */

#include <stdio.h>

int min(int x, int y);

int max(int x, int y);

int max_arr(int arr[], int length);

int min_arr(int arr[], int length);

int main() {
    int num1 = 10;
    int num2 = 12;
    int arr[6] = {1, 2, 3, 4, 5, 6};

    int maxNum = max(num1, num2);
    int minNum = min(num1, num2);
    int maxArrResult = max_arr(arr, 6);
    int minArrResult = min_arr(arr, 6);

    printf("최댓값 : %d, 최솟값 : %d\n", maxNum, minNum);
    printf("배열 내 최댓값 : %d, 배열 내 최솟값 : %d", maxArrResult, minArrResult);

    return 0;
}

int max(int x, int y) {
    if (x >= y) return x;
    else return y;
}

int min(int x, int y) {
    if (x <= y) return x;
    else return y;
}

int max_arr(int arr[], int length) {
    int maxArr = arr[0];
    int i;

    for (i = 1; i < length; i++) {
        if (arr[i] > maxArr) {
            maxArr = arr[i];
        }
    }

    return maxArr;
}

int min_arr(int arr[], int length) {
    int minArr = arr[0];
    int i;

    for (i = 1; i < length; i++) {
        if (arr[i] < minArr) {
            minArr = arr[i];
        }
    }

    return minArr;
}