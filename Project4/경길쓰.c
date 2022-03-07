/*
    Alphabet_sort.c
    create : 2022. 3. 3
    Author : 임경길
*/

#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void insertionSort(char arr[], int n);
void insertdata(char arr[], int n);
void printData(char arr[], int n);
int isAlpha(char c);

int main(void)
{
    char input_ary[10] = { NULL, };   //인풋 배열 초기화
    char lower_ary[10] = { NULL, };   //소문자 배열 초기화
    char upper_ary[10] = { NULL, };   //대문자 배열 초기화
    
    int len_i = sizeof(input_ary) / sizeof(char);
    int len_l = sizeof(lower_ary) / sizeof(char);
    int len_u = sizeof(upper_ary) / sizeof(char);

    int l_count = 0;
    int u_count = 0;

    insertdata(input_ary, sizeof(input_ary) / sizeof(char));
    printData(input_ary, sizeof(input_ary) / sizeof(char));
  
    for (int i = 0; i < len_i; i++) { // 인풋 배열 돌리는 놈
        if (input_ary[i] >= 97 && input_ary[i] <= 122) {
            lower_ary[l_count] = input_ary[i];
            l_count++;
        }
        else if(input_ary[i] >= 65 && input_ary[i] <= 90){
            upper_ary[u_count] = input_ary[i];
            u_count++;
        }
    }

    printf("==정렬 전==\n");
    printf("lower : ");
    printData(lower_ary, sizeof(input_ary) / sizeof(char));

    printf("upper : ");
    printData(upper_ary, sizeof(input_ary) / sizeof(char));

    insertionSort(lower_ary, sizeof(input_ary) / sizeof(char));
    insertionSort(upper_ary, sizeof(input_ary) / sizeof(char));

    printf("==정렬 후==\n");
    printf("lower : ");
    printData(lower_ary, sizeof(input_ary) / sizeof(char));

    printf("upper : ");
    printData(upper_ary, sizeof(input_ary) / sizeof(char));

    return 0;
}

int isAlpha(char c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) return 1; //알파벳일 때
    else if (c == '0') return 9999; //0일 때
    else return -1; // 그 외 문자
}

void insertdata(char arr[], int n)
{   
    char ch[] = "data";
    int isAl = 0;

    for (int i = 0; i < n; i++)
    {
        printf("알파벳을 입력하세요. 0을 누르면 입력 종료\n");
        scanf("%s", ch);
        getchar();

        if (isAlpha(ch[0]) == -1 || strlen(ch) > 1) {
            printf("알파벳이 아닙니다.\n");
            i--;
        }

        else if (isAlpha(ch[0]) == 9999) {
            break;
        }
        
        else {
            arr[i] = ch[0];
        }
    }
    printf("입력 종료\n");
}

void insertionSort(char arr[], int n)
{
    int i, j;
    int target;
    int cnt = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] == '\0') break;
        cnt++;
    }

    for (i = 1; i < cnt; i++)
    {
        target = arr[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > target)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = target;
    }
}

void printData(char arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}