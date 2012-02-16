/*
 * thread.c
 * Source for the MSP430 Multitasking Library.
 *
 *
 *
 *
 *
 *
 */
 
 struct thread
 {
	unsigned int Max=THREADMAX;
	unsigned int Current=0;
	unsigned int Mask=0;
	unsigned int Locked=0;
	unsigned int Suspended=0;
	unsigned int Stack[Max];
	unsigned int PC[Max];
	unsigned int Status[Max];
 };
 
 void ContextSwitch(void)
 {
 
 }
 
 unsigned int threadStart()
 {
 
 }
 
 unsigned int threadKill()
 {
 
 
 }
 
 unsigned int threadSuspend()
 {
 
 
 }
 
 unsigned int threadResume()
 {
 
 
 }