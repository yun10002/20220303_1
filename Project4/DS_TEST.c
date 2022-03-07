/*
	Alphabet_sort.c
	create : 2022. 3. 3
	Author : 최윤진
*/

#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> // isalpha함수-> 대문자 1, 소문자 2, 알파벳 아니면 0 반환

typedef struct _node {
	char data;
	struct _node* next;
}Node;

void createNode(Node* h, char alpha) { //후위 삽입으로 노드 생성
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) exit(1);

	newNode->data = alpha;
	newNode->next = NULL;

	Node* cur = h->next;

	if (cur == NULL) {				//기존 노드가 하나도 없을 때
		h->next = newNode;
	}
	else {
		while (cur->next != NULL) { //기존 노드가 하나 이상일 때
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void printNode(Node* h, char c) {
	Node* cur = h->next;

	while (cur != NULL) {
		if (c == 'l') {	 //소문자일 때
			if (isalpha(cur->data) == 2) {
				printf("%c ", cur->data);
			}
		}
		else if (c == 'u') { //대문자일 때
			if (isalpha(cur->data) == 1) {
				printf("%c ", cur->data);
			}
		}
		else printf("%c ", cur->data); //전체출력

		cur = cur->next;
	}
	printf("\n");

	if (h->next == NULL) {
		printf("#입력된 알파벳이 없습니다.\n");
	}
}

Node* InserSort(Node* h) {
	Node* cur = h->next;
	Node* temp;

	while (cur->next != NULL) {
		if (cur->data > cur->next->data) { //앞 높이 뒷 놈보다 클 때
			temp = cur->next; //temp에 앞으로 옮겨야 할 놈 저장
			cur->next = cur->next->next; //temp에 저장한 놈 빼고 나머지 연결
			temp->next = h->next; //temp는 가장 첫 번째 노드 가리킴
			h->next = temp;
			cur = h->next;  //head랑 cur이 temp(첫 번째 노드) 가리키게 초기화
			continue;
		}
		cur = cur->next;
	}
	return h;
}

void freeNode(Node* h) { // 동적으로 할당받은 메모리(노드) 반환
	Node* cur = h->next;

	/*while(h->next == NULL){
		cur = h->next;
		h->next = h->next->next;
		free(cur);
		cur = NULL;
	}*/

	while (cur != NULL) {
		h->next = h->next->next; //head가 두 번째 노드 가리키도록 함
		free(cur); //cur이 가리키는 놈(살아 있는 노드 중에 첫 번째 노드) free해주기
		cur = h->next; // 그 다음 노드로 이동
	}
	
	free(h);
}

int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) exit(1);
	head->next = NULL;

	char str[] = "alpha";
	printf("[0을 누르면 입력을 종료합니다.]\n\n");

	while (1) {
		printf("알파벳 입력 >> ");
		scanf("%s", str);
		getchar();

		if (str[0] == '0') { //0입력->종료
			printf("===입력 종료===\n\n");
			break;
		}
		else if (strlen(str) > 1 || (isalpha(str[0]) == 0)) { //문자열이거나 알파벳이 아닐 때
			printf("#알파벳이 아닙니다.\n");
		}
		else { //알파벳일 때
			createNode(head, str[0]);
		}
	}

	printf("입력 받은 알파벳 : ");
	printNode(head, 'b'); //before

	InserSort(head);
	//printf("일단 정렬 : ");
	//printNode(head, 'b');

	printf("소문자 정렬 : ");
	printNode(head, 'l'); //lower

	printf("대문자 정렬 : ");
	printNode(head, 'u'); //upper

	freeNode(head);

	return 0;
}