/*
 * app.h
 *
 *  Created on: 06/11/2017
 *      Author: Salvador Zendejas
 */

#ifndef APP_APP_H_
#define APP_APP_H_

/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>

#include "FreeRTOS.h"
#include "task.h"

/*-- Macros ------------------------------------------------------------------*/
#define    PRINT(x)    { printf(x); fflush(stdout); }         /*print on stdout*/

/*-----------------------------------------------------------
* TASK DLECLARATION
*----------------------------------------------------------*/
void vApp_init(void);
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

/**
 *  BaseType_t xTaskCreate(
							  TaskFunction_t pvTaskCode,
							  const char * const pcName,
							  uint16_t usStackDepth,
							  void *pvParameters,
							  UBaseType_t uxPriority,
							  TaskHandle_t *pvCreatedTask
						  );
 */

#endif /* APP_APP_H_ */
