/*
	Alphabet_sort.c
	create : 2022. 3. 3
	Author : ������
*/

#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> // isalpha�Լ�-> �빮�� 1, �ҹ��� 2, ���ĺ� �ƴϸ� 0 ��ȯ

typedef struct _node {
	char data;
	struct _node* next;
}Node;

void createNode(Node* h, char alpha) { //���� �������� ��� ����
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) exit(1);

	newNode->data = alpha;
	newNode->next = NULL;

	Node* cur = h->next;

	if (cur == NULL) {				//���� ��尡 �ϳ��� ���� ��
		h->next = newNode;
	}
	else {
		while (cur->next != NULL) { //���� ��尡 �ϳ� �̻��� ��
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void printNode(Node* h, char c) {
	Node* cur = h->next;

	while (cur != NULL) {
		if (c == 'l') {	 //�ҹ����� ��
			if (isalpha(cur->data) == 2) {
				printf("%c ", cur->data);
			}
		}
		else if (c == 'u') { //�빮���� ��
			if (isalpha(cur->data) == 1) {
				printf("%c ", cur->data);
			}
		}
		else printf("%c ", cur->data); //��ü���

		cur = cur->next;
	}
	printf("\n");

	if (h->next == NULL) {
		printf("#�Էµ� ���ĺ��� �����ϴ�.\n");
	}
}

Node* InserSort(Node* h) {
	Node* cur = h->next;
	Node* temp;

	while (cur->next != NULL) {
		if (cur->data > cur->next->data) { //�� ���� �� �𺸴� Ŭ ��
			temp = cur->next; //temp�� ������ �Űܾ� �� �� ����
			cur->next = cur->next->next; //temp�� ������ �� ���� ������ ����
			temp->next = h->next; //temp�� ���� ù ��° ��� ����Ŵ
			h->next = temp;
			cur = h->next;  //head�� cur�� temp(ù ��° ���) ����Ű�� �ʱ�ȭ
			continue;
		}
		cur = cur->next;
	}
	return h;
}

void freeNode(Node* h) { // �������� �Ҵ���� �޸�(���) ��ȯ
	Node* cur = h->next;

	/*while(h->next == NULL){
		cur = h->next;
		h->next = h->next->next;
		free(cur);
		cur = NULL;
	}*/

	while (cur != NULL) {
		h->next = h->next->next; //head�� �� ��° ��� ����Ű���� ��
		free(cur); //cur�� ����Ű�� ��(��� �ִ� ��� �߿� ù ��° ���) free���ֱ�
		cur = h->next; // �� ���� ���� �̵�
	}
	
	free(h);
}

int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) exit(1);
	head->next = NULL;

	char str[] = "alpha";
	printf("[0�� ������ �Է��� �����մϴ�.]\n\n");

	while (1) {
		printf("���ĺ� �Է� >> ");
		scanf("%s", str);
		getchar();

		if (str[0] == '0') { //0�Է�->����
			printf("===�Է� ����===\n\n");
			break;
		}
		else if (strlen(str) > 1 || (isalpha(str[0]) == 0)) { //���ڿ��̰ų� ���ĺ��� �ƴ� ��
			printf("#���ĺ��� �ƴմϴ�.\n");
		}
		else { //���ĺ��� ��
			createNode(head, str[0]);
		}
	}

	printf("�Է� ���� ���ĺ� : ");
	printNode(head, 'b'); //before

	InserSort(head);
	//printf("�ϴ� ���� : ");
	//printNode(head, 'b');

	printf("�ҹ��� ���� : ");
	printNode(head, 'l'); //lower

	printf("�빮�� ���� : ");
	printNode(head, 'u'); //upper

	freeNode(head);

	return 0;
}