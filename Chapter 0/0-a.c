/*
 * 0-a. 추가 문제
 */

#include <stdio.h>

// 0.a ) int 형 배열의 원소를 모두 출력
void print_arr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {1, 5, 2, 3, 7, 6};

    print_arr(arr, 6);

    return 0;
}