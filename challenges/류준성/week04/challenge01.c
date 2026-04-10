#include <stdio.h>
#include <string.h>


void print_banner()
{
	printf("카이사르 암호기/해독기! 빰빠밤~\n");
}

void encode(char* str, int shift)
{
	for (int i = 0; str[i] != '\0';i++)
	{
		char c = str[i];
		if (c >= 'A' && c <= 'Z')
		{
			str[i] = (c - 'A' + shift) % 26 + 'A';
		}
		else if (c >= 'a' && c <= 'z')
		{
			str[i] = (c - 'a' + shift) % 26 + 'z';
		}
	}
}

int get_shift()
{
	int shift = 0;
	printf("쉬프트값을 입력해주세요!\n");
	scanf("%d", &shift);
	while (getchar() != '\n');
	return shift;
}

int main()
{
	char text[101];
	int shift;
	print_banner();
	printf("메세지를 입력하십시오: ");
	fgets(text, sizeof(text), stdin);
	text[strcspn(text, "\n")] = 0;
	shift = get_shift();
	encode(text, shift);
	printf("Encoded Result: %s\n", text);
	return 0;
}