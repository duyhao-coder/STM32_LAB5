/*
 * sofware_timer.h
 *
 *  Created on: Sep 25, 2024
 *      Author: Duy
 */

#ifndef INC_SOFWARE_TIMER_H_
#define INC_SOFWARE_TIMER_H_
#define timer_cycle 10

extern int timer_counter_7seg2;
extern int timer_flag_7seg2;
extern int timer_counter;
extern int timer_flag;
extern int timer_counter1;
extern int timer_flag1;
extern int timer_counter3;
extern int timer_flag3;
extern int timer_counter4;
extern int timer_flag4;
extern int timer_counter5;
extern int timer_flag5;
extern int timer_counter6;
extern int timer_flag6;
extern int timer_counter_system;
extern int timer_flag_system;
void setTimer_system(int duration);
void setTimer1(int duration);
void setTimer(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);
void setTimer6(int duration);
void timeRun();

#endif /* INC_SOFWARE_TIMER_H_ */
