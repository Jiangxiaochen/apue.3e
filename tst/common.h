/*
 * =====================================================================================
 *
 *    Description:  some common macros for my apue
 *        Created:  08/03/2018 09:14:46 AM
 *         Author:  xiaochen.jiang (kl), jiangxch.hn@gmail.com
 *
 * =====================================================================================
 */

#ifndef COMMON_JXC_APUE_H
#define COMMON_JXC_APUE_H

#include <apue.h>

#define chk_nega(call) if ((call) < 0) {\
    err_sys("Error in `" #call "` syscall (%s:%d)", __FILE__, __LINE__);\
}

#define chk_null(ptr) if ((ptr) == NULL) {\
    err_sys("Error in `" #ptr "` syscall (%s:%d)", __FILE__, __LINE__);\
}


#define chk_eof(call) if ((call) == EOF) {\
    err_sys("Error in `" #call "` syscall (%s:%d)", __FILE__, __LINE__);\
}





#endif
