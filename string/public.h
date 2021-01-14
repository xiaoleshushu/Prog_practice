#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define READMAX 1024
#define KEY_STRING_INDEX "ExecStart"
#define CMD_GET_OUTPUT	"systemctl  show sshd.service\n"

/* *************************************
 * 执行shell cmd，并提取预设字符串
 *
 * 输入：shell完整命令
 * 输出：提取结果 or NULL
 *
 * note：函数返回的指针，需要调用者free
 * 
 * ********************************** */
char *get_shell(char *cmd);
