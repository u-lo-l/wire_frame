#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	int iFst;
	int iSnd;
	char *fstStr;
	char *sndStr;
	int printed[128];

	if (argc == 3)
	{	
		fstStr = argv[1];
		sndStr = argv[2];

		iFst = 0;
		while (iFst < 128)
			printed[iFst++] = 0;
	
		iFst = 0;
		while (fstStr[iFst])
		{
			iSnd = 0;
			if (printed[(int)(fstStr[iFst])] == 0)
			{
				while (sndStr[iSnd])
				{
					if (sndStr[iSnd++] == fstStr[iFst])
					{
						write(1, fstStr + iFst, 1);
						printed[(int)(fstStr[iFst])] = 1;
						break;
					}
				}
			}
			iFst++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
