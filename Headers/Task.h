/*
 * Task.h
 *
 * Created: 2/23/2019 2:41:20 PM
 *  Author: AVE-LAP-040
 */ 


#ifndef TASK_H_
#define TASK_H_


#define ZERO 0
#define ONE 1

#define TRUE 1
#define FALSE 0

#define Task4_ID 3

/*Enum for Task IDS*/
enum ID
{
	ID_0,
	ID_1,
	ID_2,
	ID_3,
	ID_4,
	ID_5,
	};
	
/*Enum For Priority*/

enum priority
{
	priority_1,
	priority_2,
	priority_3,
	priority_4,
	priority_5,
	priority_6,
};

/*Function Definitions */
void Task1();
void Task2();
void Task3();
void Task4();
void Task5();


#endif
/* TASK_H_ */
