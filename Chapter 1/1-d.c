/*
 * 1-d. 순열에서 역전된 순서쌍 찾기
 *
 * 더 빠른 해결법 필요
 */

#include <stdio.h>

void reversed_pair(int arr[], int size, int idx){
    static int count = 0;
    int pos=idx+1;

    // 종료조건
    if(idx == size-1){
        printf("count : %d\n",count);
        return;
    }

    while(pos<size){
        if(arr[idx]>arr[pos]){
            count++;
        }
        pos++;
    }

    reversed_pair(arr, size, idx+1);
}

// 2중 for 문 사용 ( 시간복잡도 O(n^2) )
void reversed_pair_2(int arr[], int size){
    static int count = 0;

    for(int i=0;i<size-1;i++){
        for(int j=i+1; j<size; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }

    printf("%d\n", count);
}

int main(){
    int arr[] = {4,3,1,5,2, 24,24,5,52,52,52,52,25,25,25,25,25,25,25,25,1,1,1,1,1,1,1,1,1,1
    ,4,3,1,5,2, 24,24,5,52,52,52,52,25,25,25,25,25,25,25,25,1,1,1,1,1,1,1,1,1,1};
    int size = 60;

    reversed_pair(arr, size, 0);
    reversed_pair_2(arr, size);
    return 0;
}