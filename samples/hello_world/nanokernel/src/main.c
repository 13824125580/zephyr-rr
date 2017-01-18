/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <zephyr.h>

#if defined(CONFIG_STDOUT_CONSOLE)
#include <stdio.h>
#define PRINT           printf
#else
#include <misc/printk.h>
#define PRINT           printk
#endif


/*
 * @file
 * @brief Hello World demo
 * Nanokernel version of hello world demo
 */

char __stack bufstack0[1024];
char __stack bufstack1[1024];
char __stack bufstack2[1024];
extern void fiber_sleep(int32_t timeout_in_ticks);

void task1(int arg1, int arg2);
void task2(int arg1, int arg2);
void task0(int arg1, int arg2)
{
       task_fiber_start(bufstack1, 1024, task1, (int)NULL, (int)NULL, 3, (unsigned)NULL);
       task_fiber_start(bufstack2, 1024, task2, (int)NULL, (int)NULL, 3, (unsigned)NULL);
       while(1)
       {
               /*fiber_sleep(100);*/
               PRINT("%s, compiler by: %s.\n", __func__, "allwinner");
               fiber_yield();
       }

       return;
}

void task1(int arg1, int arg2) 
{
       while(1)
       {
               /*fiber_sleep(100);*/
               PRINT("%s, compiler by: %s.\n", __func__, "allwinner");
               fiber_yield();
       }

       return;
}

void task2(int arg1, int arg2) 
{
       while(1)
       {
               /*fiber_sleep(100);*/
               PRINT("%s, compiler by: %s.\n", __func__, "allwinner");
               fiber_yield();
       }

       return;
}

void main(void)
{
       PRINT("Hello World! %s, compiler by: %s.\n", CONFIG_ARCH, "allwinner");
       
       task_fiber_start(bufstack0, 1024, task0, (int)NULL, (int)NULL, 3, (unsigned)NULL);

       while(1)
       {
               task_sleep(100);
               PRINT("Hello World! %s, compiler by: %s.\n", CONFIG_ARCH, "allwinner");
       }

       return;
}

