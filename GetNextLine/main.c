#include <stdio.h>
#include <fcntl.h>

#include "get_next_line.h"
#include "get_next_line_bonus.h"

char	*get_next_line(int fd);
char	*get_next_line_bonus(int fd);

int main()
{
	char *line;
	int file1 = open("./files/garbage_file", O_RDONLY);
	int file2 = open("./files/10_no_nl", O_RDONLY);
	int file3 = open("./files/normal_file", O_RDONLY);
	int file4 = open("./files/10nls", O_RDONLY);
	int file5 = open("./files/empty", O_RDONLY);

	while ((line = get_next_line(0)))
	{
		printf("%s", line);
		free(line);
	}
	close(file1);
	close(file2);
	close(file3);
	close(file4);
	close(file5);
}