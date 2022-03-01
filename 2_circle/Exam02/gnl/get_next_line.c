#include "get_next_line.h"

int get_next_line(char **line)
{
	char *temp;
	char c = 0;

	if (temp == NULL)
			temp = ft_strjoin(temp, '\0');
	while (read(0, &c, 1) && c != '\n')
	{
		tmp = ft_strjoin(temp, c);
	}
	*line = tmp;
	return (c == '\n');
}
