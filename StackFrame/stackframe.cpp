//stackframe.cpp
#include<stdio.h>

char pp(char a, char b) {
	a = b;
	return 'a';
}
int main(int argc, char* argv[]) {
	char a[20] = "Hello Hello Hello";
	char b = 'P';
	char c = 'A';
	c = pp(b, 'a');
	printf("%s\n", a);
	return 0;
}
