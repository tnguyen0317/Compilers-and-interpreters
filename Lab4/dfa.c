#include <stdio.h>
#include <stdlib.h>


int main()
{
	int state = 1;
	char c;
	char temp = 'a';
	printf("START\n");
	
	while(1)
	{

		temp=getchar();
		if(temp != '\n' && temp != ' ')
		{

			c=temp;
		} 
		else 
		{
			continue;
		}
		printf("%d\n",state);
		printf("skriv in tecken:\n");
					
		switch(state)
			{
			case 1:
					if (c=='a')
						state=2;
					else
						state=4;
				break;
				case 2:
					if(c=='a')
						state=3;
					else if (c=='b')
						state=1;
					else
						state=4;
				break;
				case 3:
					printf("FINISH\n");
					exit(1);
				break;
				case 4:
					printf("ERROR STATE\n");
					exit(1);
				break;
				
			}
		}

	





	return 0;
}

