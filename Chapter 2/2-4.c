/*
 * 2-4. 부분집합의 합
 */

#include <stdio.h>

int c[100][200] = {0,};

int max(int num1, int num2) {
    if (num1 > num2) return num1;
    else return num2;
}

int subset_sum(int array[], int size, int dest) {
    // 참조할 부분집합이 더 이상 없을 때 남은 수가 존재하면 불가
    if (size == 0) {
        if (dest == 0) return 1;
        else return 0;
    }

    // 집합의 마지막 값을 포함했을 때와 포함하지 않았을 때에 대해 계산
    return max(subset_sum(array, size - 1, dest - array[size - 1]),
               subset_sum(array, size - 1, dest));
}

void calculate_subset_num(int array[], int size, int dest) {
    // 참조할 부분집합이 없음 + 남은 수 없음 (가능)
    for (int i = 0; i <= size; i++){
        c[i][0] = 1;
    }

    // 참조할 부분집합이 없음 + 남은 수 있음 (불가)
    for (int i = 1; i <= dest; i++){
        c[0][i] = 0;

    }

    // 그 이외
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= dest; j++) {
            c[i][j] = 0; // 초기화


            // 구하고자 하는 부분집합의 합이 부분 배열의 마지막 값 이상이고
            if (j >= array[i - 1]) {
                // 집합의 마지막 값을 포함하지 않았을 때 더 작은 배열로 완성할 수 있으면
                // 배열이 더 크더라도 완성할 수 있음
                if (c[i - 1][j - array[i - 1]] == 1){
                    c[i][j] = 1;
                }
            }

            // 특정 배열 크기일 때 부분집합을 완성할 수 있으면
            // 배열이 더 크더라도 완성할 수 있음
            if (c[i - 1][j] == 1) {
                c[i][j] = 1;
            }
        }
    }
}

int main() {
    int arr[] = {6, 9, 13, 14, 20, 21, 22};
    calculate_subset_num(arr, 7, 41);

//    if (subset_sum(arr, 10, 110)) printf("possible\n");
//    else printf("impossible\n");

    if (c[7][41]==1) printf("possible\n");
    else printf("impossible\n");

    return 0;
}