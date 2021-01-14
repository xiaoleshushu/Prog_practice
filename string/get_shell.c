/******************
 *
 *
 * 执行 shell cmd 并返回执行结果
 *
 *
 *****************/
#include "public.h"

/*debug func*/
static int print_line(char *str)
{
	printf("%s\n", str);
	return 0;
}

/*
 * 提取包含"path"的字符串
 */
static char *process_str(char *str)
{
	char *head = NULL;
	char *tail = NULL;
	char *ptr = NULL;

	if (str == NULL)
		return NULL;
	head = strstr(str, "path");
	tail = head;
	while (*tail != ';' && *tail != '\0')
		tail++;
	if (*tail == ';') {
		*(tail-1) = '\0';
		ptr = strdup(head);
	} else {
		printf("can't find ExecStart path !!!\n");
		ptr = NULL;
	}
	return ptr;
}

/*
 * 找到指定行
 */
static char *find_line(char *buf)
{
	char *ptr = NULL;
	char *tag = NULL;
	char *str = NULL;
	
	if (buf == NULL)
		return NULL;
	
	tag = buf;
	str = buf;
	while (*tag != '\0') {
		if (*tag == '\n') {
			*tag = '\0';
			//print_line(str); /*debug*/
			if (strstr(str, KEY_STRING_INDEX)) {
				ptr = process_str(str);
				return ptr;
			}
			str = tag+1;
		}
		tag++; 
	}
	printf("Count find the line include key string: %s\n", KEY_STRING_INDEX);	
	return NULL;
}
/***************************************
 * 执行shell cmd，并提取预设字符串
 *
 * 输入：shell完整命令
 * 输出：提取结果 or NULL
 *
 * note：函数返回的指针，需要调用者free
 *
 * *********************************** */
char *get_shell(char *cmd)
{
	FILE *fp = NULL;
	char *ptr = NULL;
	char buf[READMAX] = {0};

 	if (cmd == NULL)
		return NULL; 

	memset(buf,0,sizeof(buf));
	if (NULL != (fp = popen((const char *)cmd,"r"))) {    
		if (0 < fread(buf, sizeof(char), sizeof(buf)-1, fp)) {    
			ptr = find_line(buf);
		} else {
			printf("cmd:%s, err\n",cmd);
		}    
		pclose(fp);
		return ptr; 
	} else {
		return NULL;
	}
}
