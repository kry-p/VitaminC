/*
 * 1-e. 조세푸스 수열
 *
 * https://johngrib.github.io/wiki/c-m-01-Recurrent-Problems-03/ 를 참고하였습니다.
 */

#include <stdio.h>
#include <stdlib.h>

// 규칙만 보고 트리거를 두어 풀이
// 시간이 매우 오래 걸림
int josephus(int players) {
    int currentPos = 0; // 현재 플레이어
    int survived = 1; // 첫번째는 살림 ( 살아있는 상태 : 1, 죽은 상태 : -1)
    int survivorCount = players; // 생존자 수
    int *status = (int *) malloc(sizeof(int) * players); // 플레이어 상태를 저장
    int temp; // 임시 변수

    // 플레이어 상태 변수 초기화
    for (int i = 0; i < players; i++)
        *(status + i) = 1;

    while (survivorCount > 1) {
        printf("현재 총의 조준방향 : %d\n", currentPos);
        // 죽었으면 그냥 넘김
        if (*(status + currentPos) != -1) {
            *(status + currentPos) = survived;
            survived *= -1; // 부호 반전 ( 다음 사람은 죽음 )

            // 죽었으면 생존자 수 감소
            if (*(status + currentPos) == -1) survivorCount -= 1;
        }

        for (int i = 0; i < players; i++) {
            temp = *(status + i);
            if (temp == 1) printf("생존 ");
            else if (temp == -1) printf("사망 ");
        }

        if (currentPos >= players - 1) currentPos = 0;
        else currentPos += 1;

        printf("\n\n");
    }

    // 최종 생존자 확인
    for (int i = 0; i < players; i++) {
        if (*(status + i) == 1) {
            temp = i;
            break;
        }
    }

    // 종료 시 메모리 해제
    free(status);
    return temp;
}

// 플레이어 수가 짝수일 때와 홀수일 때의 점화식을 구해 계산 (재귀적 형태)
int josephus_2(int players) {
    // 플레이어 수가 1이면 한 명만 살아남는 규칙에 의해 1이 됨
    if (players == 1)
        return 1;

    // 플레이어 수가 짝수일 때
    if (players % 2 == 0)
        return 2 * josephus_2(players / 2) - 1;
        // 홀수일 때
    else
        return 2 * josephus_2((players - 1) / 2) + 1;
}

int main() {
    int players = 20;

    printf("최종 생존자는 %d번 입니다. (1번부터 시작)\n", josephus(players) + 1);
    printf("최종 생존자는 %d번 입니다. (1번부터 시작)\n", josephus_2(players));

    return 0;
}