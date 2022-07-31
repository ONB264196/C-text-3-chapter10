#include<stdio.h>

#define _1005


#ifdef _1001
#include<stdlib.h>

typedef struct {
	int max;
	int ptr;
	int* stk;
} Stack;

int StackAlloc(Stack* s, int max) {
	s->ptr = 0;
	if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}
void StackFree(Stack* s) {
	if (s->stk != NULL) {
		free(s->stk);
		s->max = s->ptr = 0;
	}
}
int StackSize(const Stack* s) {
	return s->max;
}
int StackNo(const Stack* s) {
	return s->ptr;
}
int StackIsEmpty(const Stack* s) {
	return s->ptr <= 0;
}
int StackIsFull(const Stack* s) {
	return s->ptr >= s->max;
}
int StackPush(Stack* s, int x) {
	if (s->ptr >= s->max) return -1;
	s->stk[s->ptr++] = x;
	return 0;
}
int StackPop(Stack* s, int* x) {
	if (StackIsEmpty(s)) return -1;
	*x = s->stk[--s->ptr];
	return 0;
}
int StackPeek(const Stack* s, int* x) {
	if (StackIsEmpty(s)) return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}
void StackClear(Stack* s) {
	s->ptr = 0;
}

int main(void) {
	Stack stk;

	if (StackAlloc(&stk, 100) == -1) {
		puts("スタックの確保に失敗しました。");
		return 1;
	}
	while (true) {
		int m = 0, x = 0;

		printf("現在のデータ数 : %d/%d\n", StackNo(&stk), StackSize(&stk));
		printf("(1) プッシュ  (2) ポップ  (3) 終了 : ");
		scanf_s("%d", &m);
		if (m == 0) break;

		switch (m) {
		case 1: 
			printf("データ : "); scanf_s("%d", &x);
			if (StackPush(&stk, x) == -1) puts("プッシュできません");
			break;
		case 2:
			if (StackPop(&stk, &x) == -1) puts("ポップできません。");
			else printf("ポップしたデータは%dです。\n", x);
			break;
		}
	}
	StackFree(&stk);

	return 0;
}
#endif

#ifdef _1002
void fa() {
	puts("□□□関数fa開始");
	puts("□□□関数fa終了");
}
void fb() {
	puts("□□□関数fb開始");
	puts("□□□関数fb終了");
}
void fc() {
	puts("□□関数fc開始");
	fa();
	fb();
	puts("□□関数fc終了");
}

int main(void) {
	puts("□main関数開始");
	fc();
	puts("□main関数終了");

	return 0;
}
#endif

#ifdef _1003
void func(double x, int n) {
	int i = 0, j = 0;
	int a[3]{};
}

int main(void) {
	double y = 5.0;
	func(y, 2);

	return 0;
}
#endif

#ifdef _1004a
int z[8000]{};

void func() {
	int x[8000]{};
}

int main(void) {
	int a[8000]{};
	func();

	return 0;
}
#endif

#ifdef _1004b
int z[8000]{};

void func() {
	static int x[8000]{};
}

int main(void) {
	static int a[8000]{};
	func();

	return 0;
}
#endif

#ifdef _1005
void func() {
	char x[5]{};
	puts("関数funcの実行中です。");
	for (int i = -2; i < 8; i++) x[i] = 0;
}

int main(void) {
	puts("関数uncを呼び出します。");
	func();
	puts("関数funcから戻ってきました。");

	return 0;
}
#endif