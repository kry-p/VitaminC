/*
 * 0-h. 특정 위치를 포함하는 배열의 부분합 중 최댓값 계산
 *
 * TODO : 3중 for 문을 사용하지 않고 이 문제를 해결할 수 있을지 알아보기
 */

#include <stdio.h>

int partMax(const int arr[], int size, int pos) {
    int max = 0;
    int temp = 0;

    // 초기값 지정
    for (int i = 0; i < size; i++) {
        max += arr[i];
    }

    for (int i = 0; i < pos; i++) {
        for (int j = pos - 1; j < size; j++) {
            for (int k = i; k < j; k++) {
                temp += arr[k];
            }
            if (temp > max) max = temp;
            temp = 0;
        }
    }

    return max;
}

int main() {
    int arr[] = {-1,2,-3,4,-5,6,-7,8,-9};

    printf("%d", partMax(arr, 9, 5));

    return 0;
}