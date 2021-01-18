/*
 * 0.3 배열 회전
 *
 * right_rotate : 배열의 특정 위치를 오른쪽으로 1회전
 * left_rotate : 배열의 특정 위치를 왼쪽으로 1회전
 * multiple_right_rotate : 배열의 특정 위치를 오른쪽으로 지정한 만큼 회전
 */

#include <stdio.h>

void right_rotate(int arr[], int start, int end) {
    int last = arr[end];
    int i;

    for (i = end; i > start; i--) {
        arr[i] = arr[i - 1];
    }

    arr[start] = last;
}

void left_rotate(int arr[], int start, int end) {
    int first = arr[start];
    int i;

    for (i = start; i < end; i++) {
        arr[i] = arr[i + 1];
    }

    arr[end] = first;
}

void multiple_right_rotate(int arr[], int start, int end, int try) {
    const int size = end - start + 1; // 임시로 사용할 배열의 크기 (소배열의 크기)

    int new_order[size], previous_order[size]; // 새 위치, 기존 위치의 원소 값
    int actual_try = try % size; // 실제 소배열 내에서 이동하는 횟수

    int i;
    int temp = start + actual_try; // 소배열에 저장될 원소 값을 임시 저장

    // 기존 위치에 있던 원소 저장
    for (i = start; i <= end; i++) {
        previous_order[i - start] = arr[i];
    }

    // 원소의 새로운 위치
    for (i = 0; i < size; i++) {
        if (temp > end) {
            temp = start;
        }
        new_order[i] = temp;
        temp += 1;
    }

    // 새로운 위치를 참조하여 배열 요소 재배치
    for (i = 0; i < size; i++)
        arr[new_order[i]] = previous_order[i];
}


int main() {
    int arr0[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int arr1[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int arr2[] = {1, 3, 5, 7, 9, 11, 13, 15};

    int try = 15;

    right_rotate(arr0, 2, 6);
    left_rotate(arr1, 2, 6);
    multiple_right_rotate(arr2, 2, 6, try);

    int i;
    printf("배열 내 특정 위치 우회전 결과 : ");
    for (i = 0; i < 8; i++) {
        if (i < 7) {
            printf("%d, ", arr0[i]);
        } else printf("%d", arr0[i]);
    }
    printf("\n");

    printf("배열 내 특정 위치 좌회전 결과 : ");
    for (i = 0; i < 8; i++) {
        if (i < 7) {
            printf("%d, ", arr1[i]);
        } else printf("%d", arr1[i]);
    }
    printf("\n");

    printf("배열 내 특정 위치 %d번 우회전 결과 : ", try);
    for (i = 0; i < 8; i++) {
        if (i < 7) {
            printf("%d, ", arr2[i]);
        } else printf("%d", arr2[i]);
    }

    return 0;
}