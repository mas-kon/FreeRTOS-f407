#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H


/* 
Использовать вытесняющую многозадачность? 
Если этот параметр поставить в 0, то получим кооперативку, с требованием 
вызывать taskYIELD() для отдачи управления диспетчеру. 
*/
#define configUSE_PREEMPTION			1 

/* Использовать ли платформенно зависимые способы переключения задач? */
#define configUSE_PORT_OPTIMISED_TASK_SELECTION	0 

/* 
Использовать ли IDLE без тиков. В этом режиме 
таймер в IDLE глушится и не генерирует тики зря, полезно малопотребляющих решений.  
*/
#define configUSE_TICKLESS_IDLE			0


/* Частота контроллера */
#define configCPU_CLOCK_HZ			( ( unsigned long ) 168000000 )

/* Частота системных тиков ОС.  */
#define configTICK_RATE_HZ			( ( TickType_t ) 1000 )

/* Количество приоритетов задач */
#define configMAX_PRIORITIES			5

/*
Минимальный размер стека. Вообще он не влияет ни на что 
кроме тех мест где мы создаем задачи. Это просто макроопределение.
*/
#define configMINIMAL_STACK_SIZE		32

/*
Размер суммарной кучи. Области памяти задачи, где лежит и стек и локальные переменные какие то. 
Т.е. тут мы укзываем сколько вообще у нас места. Зависит от доступной оперативки. 
но долженбыть некий запас под глобальные переменные какие. Потому что-то оставляем себе, а остальное отдаем ОС. 

*/
#define configTOTAL_HEAP_SIZE			( ( size_t ) ( 50 * 1024 ) )


#define configMAX_TASK_NAME_LEN			16
/*
Для отладочных целей можно задавать каждой задаче символическое имя. Это мах длина имени задачи.
*/

#define configUSE_16_BIT_TICKS			0
/*
Разрядность таймера ОС. 1—16 бит, 0—32 бита. У STM32 SysTick 24 разрядный, поэтому оставляем тут 0. 
*/

#define configIDLE_SHOULD_YIELD			1
/*
Этот параметр определяет поведение задач с приоритетом IDLE болтающихся одновременно с IDLE ядра. 
Если стоит 1, то ядро будет отдавать управление сразу же как только задача станет готовой к запуску. 
А если оставить 0, то время будет равномерно делиться между задачами с приоритетом IDLE и IDLE ядра. 
*/

#define configUSE_MUTEXES						1
#define configUSE_RECURSIVE_MUTEXES		1
#define configUSE_COUNTING_SEMAPHORES		1
/*
Это конфигурация на использование мутексов и семафоров. Т.е. можно поотрубать ненужное, чтобы память не ело зря. 
*/


#define configQUEUE_REGISTRY_SIZE		10
#define configUSE_QUEUE_SETS			0
#define configUSE_TIME_SLICING			0
#define configUSE_NEWLIB_REENTRANT		0
#define configENABLE_BACKWARD_COMPATIBILITY	0




/* Hook function related definitions. */
#define configUSE_IDLE_HOOK			0
/* 	
Есть ли функция перехватывающая IDLE?
В FreeRTOS мы можем поставить перехват IDLE, 
т.е. при попадании в Idle будет выполнена некая функция. 
Например загон проца в спячку или еще какая нужна вещь. 
Если Hook на IDLE не используется, то 0.  
*/

#define configUSE_TICK_HOOK			0
/* 
Аналогичная функция, но про перехват диспетчера. Т.е. можно поставить 
зацепку за диспетчер и выполнять какую-нибудь фигню каждый тик. 
*/ 

#define configCHECK_FOR_STACK_OVERFLOW		0
#define configUSE_MALLOC_FAILED_HOOK		0
 
/* Run time and task stats gathering related definitions. */
#define configGENERATE_RUN_TIME_STATS		0
#define configUSE_TRACE_FACILITY		0
#define configUSE_STATS_FORMATTING_FUNCTIONS	0
 
/* Co-routine related definitions. */
/* Используются ли сопрограммы и приоритеты для них. */
#define configUSE_CO_ROUTINES			0
#define configMAX_CO_ROUTINE_PRIORITIES	2
 
/* Software timer related definitions. */
#define configUSE_TIMERS			1
#define configTIMER_TASK_PRIORITY		3
#define configTIMER_QUEUE_LENGTH		10
#define configTIMER_TASK_STACK_DEPTH		configMINIMAL_STACK_SIZE
 
/* Interrupt nesting behaviour configuration. */
#define configKERNEL_INTERRUPT_PRIORITY		255
#define configMAX_SYSCALL_INTERRUPT_PRIORITY	191
 
 
 
 
/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
 
#define INCLUDE_vTaskPrioritySet		1
#define INCLUDE_uxTaskPriorityGet		1
#define INCLUDE_vTaskDelete			0
#define INCLUDE_vTaskCleanUpResources		1
#define INCLUDE_vTaskSuspend			1
#define INCLUDE_vTaskDelayUntil			1
#define INCLUDE_vTaskDelay			1
#define INCLUDE_xResumeFromISR			1
#define INCLUDE_xTaskGetSchedulerState		1
#define INCLUDE_xTaskGetCurrentTaskHandle	0
#define INCLUDE_uxTaskGetStackHighWaterMark	0
#define INCLUDE_xTaskGetIdleTaskHandle		0
#define INCLUDE_xTimerGetTimerDaemonTaskHandle	0
#define INCLUDE_pcTaskGetTaskName		0
#define INCLUDE_eTaskGetState			0
#define INCLUDE_xEventGroupSetBitFromISR	1
#define INCLUDE_xTimerPendFunctionCall		1
 
 
 
 
#define xPortSysTickHandler SysTick_Handler
#define xPortPendSVHandler PendSV_Handler
#define vPortSVCHandler SVC_Handler
 
 
#endif /* FREERTOS_CONFIG_H */
