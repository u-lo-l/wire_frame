#include <unistd.h>
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
{
	int iFst;
	int iSnd;
	char *fstStr;
	char *sndStr;
	char printable[128];

	if (argc == 3)
	{
		iFst = 0;
		iSnd = 0;
		fstStr = argv[1];
		sndStr = argv[2];
		while (iFst < 128)
			printable[iFst++] = TRUE;
		
		iFst = 0;
		while (fstStr[iFst])
		{
			if (printable[(int)(fstStr[iFst])] == TRUE)
			{
				write(1, fstStr + iFst, 1);
				printable[(int)(fstStr[iFst])] = FALSE;
			}
			iFst++;
		}
		while (sndStr[iSnd])
		{

			if (printable[(int)(sndStr[iSnd])] == TRUE)
			{
				write(1, sndStr + iSnd, 1);
				printable[(int)(sndStr[iSnd])] = FALSE;
			}
			iSnd++;
		}
	}
	write(1, "\n", 1);
}
