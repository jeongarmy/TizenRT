/****************************************************************************
 *
 * Copyright 2019 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/
#include <tinyara/config.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sched.h>
#include <pthread.h>
#include <fcntl.h>
#include <mqueue.h>
#include <semaphore.h>

#if !defined(CONFIG_MPU_TEST_KERNEL_CODE_ADDR) || !defined(CONFIG_MPU_TEST_APP_ADDR)
#error "Address not defined for MPU test"
#endif


/////////////////////tasks

static int normal_task(int argc, char *argv[])
{
	while (1) {
		sleep(10);
	}
}

static int sem_wait_task(int argc, char *argv[])
{
	sem_t test_sem;

	sem_init(&test_sem, 0, 0);
	sem_wait(&test_sem);
}

static int mq_wait_task(int argc, char *argv[])
{
	int nbytes;
	mqd_t mqfd;
	char mq_name[32];
	char data[32];

	struct mq_attr attr;
	attr.mq_maxmsg = 32;
	attr.mq_msgsize = 16;
	attr.mq_flags = 0;

	memset(mq_name, 0, 32);

	sprintf(mq_name, "mymqueue%d", getpid());
	
	mqfd = mq_open(mq_name, O_RDWR | O_CREAT, 0666, &attr);
	if (mqfd < 0) {
		printf("Failed to open message queue\n");
		return 0;
	}

	nbytes = mq_receive(mqfd, (char *)data, 32, NULL);
	if (nbytes <= 0) {
		printf("Receive ERROR %d, errno %d, retry!\n", nbytes, errno);
	}
 
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/
void recovery_test(void)
{
	int pid;
	int i;

	/*for (i = 0; i < 5; i++) {
		pid = task_create("sem_wait", 220, 1024, sem_wait_task, (FAR char *const *)NULL);
		if (pid < 0) {
			printf("task create FAIL\n");
			return 0;
		}
	}*/

	for (i = 0; i < 30; i++) {
		pid = task_create("sem_wait", 100, 512, sem_wait_task, (FAR char *const *)NULL);
		if (pid < 0) {
			printf("task create FAIL\n");
			return 0;
		}
	}
}
