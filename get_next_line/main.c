#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define LINEFEED printf("\n")

int main()
{
	int fd = open("test.txt", O_RDONLY);
	int	fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	char *str1 = get_next_line(fd);
	char *str2 = get_next_line(fd);
	char *str3 = get_next_line(fd);
	char *str4 = get_next_line(fd);
	char *str5 = get_next_line(fd);
	char *str6 = get_next_line(fd);
	char *str7 = get_next_line(fd);
	char *str8 = get_next_line(fd);
	char *str9 = get_next_line(fd);
	char *str10 = get_next_line(fd);

	char *str1_2 = get_next_line(fd2);
	char *str2_2 = get_next_line(fd2);
	char *str3_2 = get_next_line(fd2);
	char *str4_2 = get_next_line(fd2);
	char *str5_2 = get_next_line(fd2);
	char *str6_2 = get_next_line(fd2);
	char *str7_2 = get_next_line(fd2);
	char *str8_2 = get_next_line(fd2);
	char *str9_2 = get_next_line(fd2);
	char *str10_2 = get_next_line(fd2);
	
	char *str1_3 = get_next_line(fd3);
	char *str2_3 = get_next_line(fd3);
	char *str3_3 = get_next_line(fd3);
	char *str4_3 = get_next_line(fd3);
	char *str5_3 = get_next_line(fd3);
	char *str6_3 = get_next_line(fd3);
	char *str7_3 = get_next_line(fd3);
	char *str8_3 = get_next_line(fd3);
	char *str9_3 = get_next_line(fd3);
	char *str10_3 = get_next_line(fd3);

	printf("str1: %s", str1);
	printf("str2: %s", str2);
	printf("str3: %s", str3);
	printf("str4: %s", str4);
	printf("str5: %s", str5);
	printf("str6: %s", str6);
	printf("str7: %s", str7);
	printf("str8: %s", str8);
	printf("str9: %s", str9);
	printf("str10: %s", str10);
	LINEFEED;
	printf("str1: %s", str1_2);
	printf("str2: %s", str2_2);
	printf("str3: %s", str3_2);
	printf("str4: %s", str4_2);
	printf("str5: %s", str5_2);
	printf("str6: %s", str6_2);
	printf("str7: %s", str7_2);
	printf("str8: %s", str8_2);
	printf("str9: %s", str9_2);
	printf("str10: %s", str10_2);
	LINEFEED;
	printf("str1: %s", str1_3);
	printf("str2: %s", str2_3);
	printf("str3: %s", str3_3);
	printf("str4: %s", str4_3);
	printf("str5: %s", str5_3);
	printf("str6: %s", str6_3);
	printf("str7: %s", str7_3);
	printf("str8: %s", str8_3);
	printf("str9: %s", str9_3);
	printf("str10: %s", str10_3);


	close(fd);
	close(fd2);
	close(fd3);
}
