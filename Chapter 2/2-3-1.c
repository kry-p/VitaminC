/*
 * 2-3-1. 경로를 순서대로 출력하기
 * 이중 연결 리스트를 이용하여 해결
 *
 * sample
5 5
1 2 3 2 1
1 2 3 2 1
1 2 3 2 1
1 2 3 2 1
1 2 3 2 1

 */

#include <stdio.h>
#include <stdlib.h>

enum {
    LEFT, UP
};

// 리스트 노드 구조체
struct _node {
    int yPos;
    int xPos;
    struct _node *next;
    struct _node *prev;
};

typedef struct _node node_t;

node_t *head = NULL;
node_t *tail = NULL;

// 노드 추가
void insert_node(int m, int n) {
    // 노드 동적 할당
    node_t *new_node = (node_t *) malloc(sizeof(node_t));

    // 구조체 포인터로 선언된 노드의 key 와 다음 노드 (next) 를 지정
    // 추가된 노드는 마지막 노드이므로 다음 노드 주소는 NULL
    new_node->yPos = m;
    new_node->xPos = n;
    new_node->next = NULL;

    // 이중 연결 리스트의 tail 노드는 노드가 추가될 때마다 바뀜, 이를 반영
    if (tail != NULL)
        new_node->prev = tail;
    else
        new_node->prev = NULL;

    if (head == NULL) {

        // head 노드가 없을 경우 새로 만들어진 노드를 head 노드에 대응
        // head 노드 뿐이므로 tail 노드와 head 노드는 동일

        head = new_node;
        tail = new_node;
    } else {

        // head 노드가 있으면 tail 노드의 next 에 새로운 노드의 주소를 저장
        // 마지막 노드인 new_node 는 tail 노드가 됨

        tail->next = new_node;
        tail = new_node;
    }
}

void delete_node() {
    node_t *node;

    // head 가 없을 경우 error 값 -1을 반환
    if (head == NULL)
        printf("list error : head is null\n");
    else {
        node = head; // 제거 대상 노드 지정
        head = head->next; // head 노드를 다음 노드로 변경

        // head 가 없을 경우 참조 오류가 발생할 수 있는 tail 노드 참조도 제거
        if (head == NULL) tail = NULL;

        free(node); // 메모리 반환
    }
}

// 연결 리스트를 역순으로 출력 (이중 연결리스트)
void print_list_reverse(node_t *from) {
    node_t *node;

    node = from;

    while (node != NULL) {
        printf("(%d, %d) ", node->yPos, node->xPos);
        node = node->prev;
    }
}

// 동적 2차원 배열 생성기
long long **array_generator(int m, int n) {
    long long **array = (long long **) calloc(n, sizeof(long long *));

    for (int i = 0; i < n; i++) {
        array[i] = (long long *) calloc(m, sizeof(long long));
    }

    return array;
}

// 최댓값
long long max(long long m, long long n) {
    if (m > n) return m;
    else return n;
}

void print_path(long long **from, int m, int n) {
    if (m == 0 && n == 0) return;

    if (from[m][n] == LEFT) {
        insert_node(m - 1, n);
        print_path(from, m - 1, n);
    } else {
        insert_node(m, n - 1);
        print_path(from, m, n - 1);
    }
}

long long beautiful_path_counter(long long **map, int m, int n) {
    // 동적 2차원 배열 생성
    long long **path = array_generator(m, n);
    long long **from = array_generator(m, n);

    path[0][0] = map[0][0];

    for (int i = 1; i < m; i++) {
        path[i][0] = path[i - 1][0] + map[i][0];
        from[i][0] = LEFT; // 어디에서 왔는지 기록
    }

    for (int i = 1; i < n; i++) {
        path[0][i] = path[0][i - 1] + map[0][i];
        from[0][i] = UP;
    }

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++) {
            if (path[i - 1][j] > path[i][j - 1]) from[i][j] = LEFT;
            else from[i][j] = UP;

            path[i][j] = max(path[i - 1][j], path[i][j - 1]) + map[i][j];
        }

    print_path(from, m - 1, n - 1);
    printf("\n");

    print_list_reverse(tail); // 리스트를 역순으로 출력

    delete_node(); // 메모리 정리

    long long result = path[m - 1][n - 1];

    // 동적 할당된 메모리 해제
    for (int i = 0; i < n; i++) {
        free(path[i]);
        free(from[i]);
    }

    free(path);
    free(from);

    return result;
}


int main() {
    int m, n;

    scanf("%d %d", &m, &n);

    // 동적 2차원 배열 생성
    long long **map = array_generator(m, n);

    // 지도 정보 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%lld", &map[i][j]);

    printf("\n%lld\n", beautiful_path_counter(map, m, n));

    // 동적 할당된 메모리 해제
    for (int i = 0; i < n; i++)
        free(map[i]);

    free(map);

    return 0;

}