#ifndef _THREADS_LIST_H
#define _THREADS_LIST_H
#include "global_includes.h"
#include "project_defs.h"

#define INIT_THREAD_LIST                                                                                                      \
    (task_init_descriptor_t[])                                                                                                \
    {                                                                                                                         \
    {lp_workqueue_thread, lp_workqueue_init, "Low priority Work thread", 2048, NULL, 0, NULL, DEFAULT_THREAD_HANDLE},         \
    }
#endif