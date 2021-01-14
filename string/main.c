#include "public.h"

int main(int argc, char* argv[])
{
	char *str = NULL;
 
 	str = get_shell(CMD_GET_OUTPUT);

	if (str) {
		printf("%s\n",str);
		free(str);
	}

	return 0;
}
