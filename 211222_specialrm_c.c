#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LEN 100
int strcmpprinciple(char* str1, char* str2);
char strcmpprinciple_modify(char* ch, char* op);
int main()
{
	unsigned int i;
	char op[15] = { 0, };
	for (i = 0; i < 15; i++) {
		op[i] = 32 + i;
		printf("%c ", *(op + i));
	}
	printf("\n");
	char msg[] = "This  ! method # calls   ( into  ))*&      the underlying     c   runtime.";
	char* p = (char*)malloc(MAX_LEN);
	p = msg;
	char p_arr[MAX_LEN];
	strncpy_s(p_arr, MAX_LEN, p, 1);
	int len = strlen(msg) + 1;//�ι��ڱ��� �����Ϸ���
	unsigned int j = 0;
	char* p_tmp = msg;
	for (unsigned int i = 0; i < len; i++) {
		p = p_tmp++;
		strncpy_s(p_arr, MAX_LEN, p, 1);
		printf("%s:p_arr\n", p_arr);
		//printf("%c:%d: p++�Ұ�\n", *p++, *p);
		//printf("%c:%d: p++�Ұ�\n", *p_arr, *p_arr);
		char special = strcmpprinciple_modify(p_arr, op);
		printf("%d: special\n", special);
		//�������ڿ����� �� �ε����� ã�Ƽ� �� �ε��� +1�� �ֵ���� ���ܿ�
		//���Ǹ����� ���� do nothing�̰� ���Ǹ����ȵǸ� break;��
		int result;
		char* p2;
		p2 = &special;
		while ((result = strcmp(p_arr, p2)) != 0) {
			//printf("%d:strcmp���\n", result);
			//printf("%c:*p,%c:special\n", *p, special);
			strncpy_s(p_arr, MAX_LEN, p++, 1);
			printf("%s:p_arr,%s:p2\n", p_arr, p2);
			j++;
			printf("%c:%d: j\n", *p_arr, j);
		}
		printf("���� ���ڸ� ã�ҽ��ϴ�\n");
		for (unsigned int k = j; k < len; k++) {
			msg[k] = msg[k + 1];
			printf("%c: msg[%d]\n", msg[k], k);
		}

		printf("%s: msg\n", msg);
		j = 0;

	}
	printf("%s: msg\n", msg);
}
int strcmpprinciple(char* str1, char* str2)
{
	int len;
	len = (strlen(str1) < strlen(str2)) ? strlen(str1) + 1 : strlen(str2) + 1;
	for (unsigned int i = 0; i < len; i++) {
		int ascii_diff = str1[i] - str2[i];
		if (ascii_diff < 0)	return -1;
		else if (ascii_diff > 0)	return 1;
		else {
			continue;
		}
	}
	return 0;
}
char strcmpprinciple_modify(char* ch_addr, char* op)
{
	int result;
	printf("%c:op�Ű������� ��\n", *op);
	char op_arr[15];
	strncpy_s(op_arr, 15, op, 1);
	printf("%d: op����\n", strlen(op));
	for (unsigned int j = 0; j < strlen(op) + 1; j++) {
		strncpy_s(op_arr, 15, op, 1);
		printf("%d��° ��\n", j+1);
		printf("%c: op_arr at str...modify\n", *op_arr);
		if ((result = strcmp(ch_addr, op_arr)) != 0) {
			printf("%d:%c: op_arr������\n", *op_arr, *op_arr);
			printf("%d:%c: ch_addr������\n", *ch_addr, *ch_addr);
			op++;
			printf("----------------------------------\n");
		}
		else
		{
			printf("Ư�����ڰ� �ƴ� �����Դϴ� 0����ȯ�մϴ�\n");
			return *ch_addr;
		}
	}
	return 0;
}