/*
 * 0-b. 추가 문제
 */

#include <stdio.h>

// 0.b ) int 형 배열의 모든 원소의 값이 일치하는지 확인
int all_is(int arr[], int size, int k) {
    int isSame = 1;

    for (int i = 0; i < size; i++) {
        if (arr[i] != k) isSame = 0;
    }

    return isSame;
}

int main() {
    int arr[] = {1, 5, 2, 3, 7, 6};

    printf("%d", all_is(arr, 6, 1));

    return 0;
}