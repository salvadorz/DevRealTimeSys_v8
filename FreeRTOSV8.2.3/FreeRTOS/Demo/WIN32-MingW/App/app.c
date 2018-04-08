/*
 * app.c
 *
 *  Created on: 06/11/2017
 *      Author: Salvador Zendejas
 */

#include "app.h"

void vTask1(void * pvParameters)
{
	const char *pcStrMsg = "This is task 1\r\n";

	/* As per most tasks, this task is implemented in an infinite loop. */
	for (;; )
	{
		/* Print out the msg of this task. */
		PRINT(pcStrMsg);
		//printf("This is task 1\r\n");
		//fflush(stdout);

		/* Delay, entering in a blocking state */
		vTaskDelay(100 / portTICK_RATE_MS);
	}

}

void vTask2(void * pvParameters)
{
	const char *pcStrMsg = "This is task 2\r\n";

	/* As per most tasks, this task is implemented in an infinite loop. */
	for (;; )
	{
		/* Print out the msg of this task. */
		PRINT(pcStrMsg);

		/* Delay, entering in a blocking state */
		vTaskDelay(500 / portTICK_RATE_MS);
	}

}

void vApp_init()
{

	BaseType_t created_task;

	created_task = xTaskCreate(
		vTask1,		/* Pointer to the function that implements the task. */
		"Task 1",	/* Text name for the task. */
		1000,		/* Stack depth - in words, not bytes. */
		NULL,		/* Parameter passed into the task - Not used in this case */
		3,			/* Priority at which the task is created */
		NULL);		/* We are not going to use the task handle. */

	if (created_task == pdPASS){
		PRINT("Task 1 Created succesfully \n")
	}

	else {
		PRINT("Task 1 was not created \n")
	}
		/* Create the other task in exactly the same way */
	if (xTaskCreate(vTask2, "Task 2", 100, NULL, 1, NULL)){
		PRINT("Task 2 Created succesfully \n")
	}
	else {
		PRINT("Task 2 was not created \n")
	}
}
