/*
 * 0.d 추가 문제
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 0.d ) stack

// 대기번호
int waiting = 1;

// 리스트 노드 구조체
struct _node{
    int key;
    struct _node* next;
};

typedef struct _node node_t;

node_t *head = NULL;

// 노드 추가
void insert_node(){
    // 노드 동적 할당
    node_t* new_node = (node_t *) malloc(sizeof(node_t));

    // 구조체 포인터로 선언된 노드의 key 와 다음 노드 (next) 를 지정
    // 추가된 노드는 첫 번째 노드이므로 다음 노드 주소는 head
    new_node -> key = waiting;
    new_node -> next = head;

    if(head == NULL){

        // head 노드가 없을 경우 새로 만들어진 노드를 head 노드에 대응
        // head 노드 뿐이므로 tail 노드와 head 노드는 동일

        head = new_node;
    }else{

        // head 노드가 있으면 새로 추가된 노드의 next 에 기존 head 의 주소를 저장
        // 추가된 노드는 head 노드가 됨

        new_node -> next = head;
        head = new_node;
    }

    printf("대기순번은 %d 번입니다.", waiting);
    waiting += 1;
}

int delete_node(){
    node_t *node;
    int r;

    // head 가 없을 경우 error 값 -1을 반환
    if(head == NULL) return -1;

    node = head; // 제거 대상 노드 지정
    head = head -> next; // head 노드를 다음 노드로 변경

    r = node -> key; // 제거 대상에 있던 key 값을 가져옴
    free(node); // 메모리 반환

    return r;
}


int main() {
    int number;
    bool isEnd = false;

    do {
        printf("00은행 순번대기 시스템입니다. \n"
               "(0 : 대기자 추가, 1 : 다음 대기자 호출, -1 : 종료) : ");
        scanf("%d", &number);

        if (number == 0) {
            insert_node();
        } else if (number == 1) {
            int delete_node_result = delete_node();

            if (delete_node_result != -1) printf("%d번 손님 창구로 와 주세요.",delete_node_result);
            else printf("대기열이 비어 있습니다.");

        } else if (number == -1) isEnd = true;
        else printf("잘못 입력하였습니다. 다시 입력하세요.");

        printf("\n\n");
    } while (!isEnd);

    return 0;
}