/*
 * =====================================================================================
 *    Description:
 *        Version:  1.0
 *        Created:  08/03/2018 11:49:05 AM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <shadow.h>
#include <pwd.h>
#include <common.h>

int main(int argc, const char *argv[])
{
    struct spwd *result;
    result = getspnam("root");
    chk_null(result);
    printf("%s %s\n", result->sp_namp, result->sp_pwdp);

    struct passwd *wrong_result;
    wrong_result = getpwnam("root");
    chk_null(result);
    printf("%s %s\n", wrong_result->pw_name, wrong_result->pw_passwd);
    return 0;
}
