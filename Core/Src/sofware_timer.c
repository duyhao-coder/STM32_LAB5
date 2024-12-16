/*
 * sofware_timer.c
 *
 *  Created on: Sep 25, 2024
 *      Author: Duy
 */

#include "sofware_timer.h"

#define timer_cycle 10

int timer_counter=0;
int timer_flag=0;
int timer_counter1=0;
int timer_flag1=0;
int timer_counter_7seg2=0;
int timer_flag_7seg2=0;
int timer_counter3=0;
int timer_flag3=0;
int timer_counter4=0;
int timer_flag4=0;
int timer_counter5=0;
int timer_flag5=0;
int timer_counter6=0;
int timer_flag6=0;
int timer_counter_system=0;
int timer_flag_system=0;
void setTimer_system(int duration)
{
	timer_counter_system = duration/timer_cycle;
	timer_flag_system = 0;
}
void setTimer6(int duration){
	timer_counter6 = duration/timer_cycle;
	timer_flag6 = 0;
}
void setTimer5(int duration){
	timer_counter5 = duration/timer_cycle;
	timer_flag5 = 0;
}
void setTimer4(int duration){
	timer_counter4 = duration/timer_cycle;
	timer_flag4 = 0;
}
void setTimer3(int duration){
	timer_counter3 = duration/timer_cycle;
	timer_flag3 = 0;
}
void setTimer2(int duration)
{
	timer_counter_7seg2 = duration/timer_cycle;
	timer_flag_7seg2 = 0;
}
void setTimer1(int duration){
	timer_counter1 = duration/timer_cycle;
	timer_flag1 = 0;
}
void setTimer(int duration){
	timer_counter = duration/timer_cycle;
	timer_flag = 0;
}
void timeRun()
{
	if(timer_counter > 0) {timer_counter--;
	if(timer_counter == 0){
		timer_flag = 1;
	}}
	if(timer_counter1 > 0) {timer_counter1--;
	if(timer_counter1 == 0){
		timer_flag1 = 1;
	}}
	if(timer_counter_7seg2 > 0) {timer_counter_7seg2--;
		if(timer_counter_7seg2 == 0){
			timer_flag_7seg2 = 1;
		}}
	if(timer_counter3 > 0) {timer_counter3--;
		if(timer_counter3 == 0){
			timer_flag3 = 1;
		}}
	if(timer_counter4 > 0) {timer_counter4--;
		if(timer_counter4 == 0){
			timer_flag4 = 1;
		}}
	if(timer_counter5 > 0) {timer_counter5--;
		if(timer_counter5 == 0){
			timer_flag5 = 1;
		}}
	if(timer_counter6 > 0) {timer_counter6--;
		if(timer_counter6 == 0){
			timer_flag6 = 1;
		}}
	if(timer_counter_system > 0) {timer_counter_system--;
		if(timer_counter_system == 0){
			timer_flag_system = 1;
		}}




}
