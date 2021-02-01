/*
 * 0.5.2 Deque
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int waiting = 1; // 대기번호

// 리스트 노드 구조체
struct _node{
    int key;
    struct _node* prev;
    struct _node* next;
};

typedef struct _node node_t;

node_t* head = NULL;
node_t* tail = NULL;

// 대기순번 추가 (새치기)
void insert_node_pos(int k){
    // 노드 동적 할당
    node_t* new_node = (node_t *) malloc(sizeof(node_t));
    node_t *prev, *next;

    // 구조체 포인터로 선언된 노드의 key 를 지정
    new_node -> key = waiting;

    int i;
    prev = head; // 끼워넣을 노드의 이전 노드

    for(i = 0; i < k - 1; i++){
        prev = prev -> next;
    }

    next = prev -> next; // 끼워넣을 노드의 다음 노드

    if(head == NULL){
        // head 가 없으면 이 명령을 무시
        printf("잘못된 대기번호 입력입니다.\n");
        return;

    }else{
        // 노드를 중간에 삽입하면 링크를 바꿈
        new_node -> prev = prev;
        new_node -> next = next;

        prev -> next = new_node;
        next -> prev = new_node;

        printf("대기순번은 %d 번입니다.", waiting);
        waiting += 1;
    }
}

// 첫 번째에 대기순번 추가
void insert_node_head(){
    // 노드 동적 할당
    node_t* new_node = (node_t *) malloc(sizeof(node_t));

    // 구조체 포인터로 선언된 노드의 key 와 다음 노드 (next) 를 지정
    // 추가된 노드는 첫 번째 노드이므로 이전 노드 주소는 NULL
    new_node -> key = waiting;
    new_node -> prev = NULL;

    if(head == NULL){

        // head 노드가 없을 경우 새로 만들어진 노드를 head 노드에 대응
        // head 노드 뿐이므로 tail 노드와 head 노드는 동일

        head = new_node;
        tail = new_node;
    }else{
        // 노드를 맨 앞에 삽입하면 head 를 바꿈
        head -> prev = new_node;
        new_node -> next = head;

        head = new_node;
    }

    printf("대기순번은 %d 번입니다.", waiting);
    waiting += 1;
}

// 마지막에 대기순번 추가
void insert_node_tail(){
    // 노드 동적 할당
    node_t* new_node = (node_t *) malloc(sizeof(node_t));

    // 구조체 포인터로 선언된 노드의 key 와 다음 노드 (next) 를 지정
    // 추가된 노드는 마지막 노드이므로 다음 노드 주소는 NULL
    new_node -> key = waiting;
    new_node -> next = NULL;

    if(tail == NULL){

        // tail 노드가 없을 경우 새로 만들어진 노드를 head 노드에 대응
        // tail 노드 뿐이므로 tail 노드와 head 노드는 동일

        head = new_node;
        tail = new_node;
    }else{
        // 노드를 맨 뒤에 삽입하면 tail 을 바꿈
        tail -> next = new_node;

        new_node -> prev = tail;
        new_node -> next = NULL;

        tail = new_node;
    }

    printf("대기순번은 %d 번입니다.", waiting);
    waiting += 1;
}

// 첫 번째 대기순번 배출
int delete_node_head(){
    node_t* node;
    int r;

    // head 가 없을 경우 error 값 -1을 반환
    if(head == NULL) return -1;

    node = head; // 제거 대상 노드 지정
    head = head -> next; // head 노드를 다음 노드로 변경

    // head 가 없을 경우 참조 오류가 발생할 수 있는 tail 노드 참조도 제거
    if(head == NULL) tail = NULL;

    r = node -> key; // 제거 대상에 있던 key 값을 가져옴
    free(node); // 메모리 반환

    return r;
}

// 마지막 대기순번 배출
int delete_node_tail(){
    node_t* node;
    int r;

    // tail 이 없을 경우 error 값 -1을 반환
    if(tail == NULL) return -1;

    node = tail; // 제거 대상 노드 지정
    tail = tail -> prev; // tail 노드를 이전 노드로 변경

    // tail 이 없을 경우 참조 오류가 발생할 수 있는 head 노드 참조도 제거
    if(tail == NULL) head = NULL;

    r = node -> key; // 제거 대상에 있던 key 값을 가져옴
    free(node); // 메모리 반환

    return r;
}

int main() {

    int number;
    bool isEnd = false;

    do {
        printf("안녕하세요, 바나나은행 순번대기 시스템입니다. \n"
               "(0 : 대기자 추가, 1 : 다음 대기자 호출, 2 : VIP 대기, 3 : 새치기, -1 : 종료) : ");
        scanf("%d", &number);

        if (number == 0) {
            insert_node_tail();
        } else if (number == 1) {
            int delete_node_result = delete_node_head();

            if (delete_node_result != -1) printf("%d번 손님 창구로 와 주세요.",delete_node_result);
            else printf("대기열이 비어 있습니다.");

        } else if (number == -1) isEnd = true;
        else if (number == 2){
            insert_node_head();
        }
        else if (number == 3){
            int pos;
            printf("끼워넣을 위치를 입력하세요 : ");
            scanf("%d", &pos);

            insert_node_pos(pos);
        }
        else printf("잘못 입력하였습니다. 다시 입력하세요.");

        printf("\n\n");
    } while (!isEnd);

    return 0;
}