/*
 * 0.2 두 변수의 값 바꾸기
 *
 * swap : 두 변수 공간은 유지한 채로 둘이 갖고 있는 값만 바꿈
 * swap_array : 입력한 두 위치의 원소를 서로 바꿈
 */

#include <stdio.h>

void swap(int *num1, int *num2);

void swap_array(int arr[], int pos0, int pos1);

int main() {
    int a = 20;
    int b = 35;

    swap(&a, &b); // 전달된 인자는 주소

    printf("두 변수 바꾸기 결과 : %d, %d\n", a, b);

    int arr[] = {1, 3, 5, 7, 9};

    swap_array(arr, 2, 4);

    int i;
    printf("배열 내 두 변수 바꾸기 결과 : ");
    for (i = 0; i < 5; i++) {
        if(i < 4){
            printf("%d, ", arr[i]);
        }else printf("%d", arr[i]);
    }

    return 0;
}

// 포인터로 받아 처리
void swap(int *num1, int *num2) {
    int temp = *num1;

    // 주소에 담긴 값을 서로 바꿈
    *num1 = *num2;
    *num2 = temp;
}

// 배열의 두 값을 서로 바꿈
void swap_array(int arr[], int pos0, int pos1) {
    int temp;

    temp = arr[pos0];
    arr[pos0] = arr[pos1];
    arr[pos1] = temp;
}