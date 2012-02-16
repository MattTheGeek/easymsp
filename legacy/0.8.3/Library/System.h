//EasyMSP Copyright 2011 Matthew Burmeister

#ifndef ARDUINO

static inline void setup(void);
/// \fn static inline void setup()
/// \brief Sets up the controller for use with EasyMSP
/// \attention You must call setup or EasyMSP will not run correctly.
/// \details setup() sets up the controller for use with the EasyMSP system. setup() accepts no commands and does not return anything. 

#else

extern void setup();
extern void loop();

#endif

static int _lowpower = 0;

static inline void stopwd(void);
/// \fn static inline void stopwd(void)
/// \brief Stops the system watchdog
/// \details stopwd() stops the system watchdog.

static inline void reset(void);
/// \fn static inline void reset(void)
/// \brief Resets the system
/// \details reset() resets the system by causing a PUC. Code execution will restart at the beginning of the program.
///
/// \return Nothing

static inline void shutdown(void);
/// \fn static inline void shutdown(void)
/// \brief Enters the MCU into shutdown mode (LPM4)
/// \details shutdown() enters the MCU into LPM4. In LPM4, the CPU and all clocks are disabled, Thus any peripheral requiring a clock is disabled. The only way to return from LPM4 is through a interrupt such as a NMI/RESET or a PORT interrupt.
/// 
/// \return Nothing

static void sleep(unsigned int time, unsigned int mode);
/// \fn static void sleep(unsigned int time, unsigned int mode)
/// \todo Write ISR and entry code.

static inline void lowPowerModeOn(void);
/// \fn static inline void lowPowerModeOn(void)
/// \todo Write code that uses lowPowerMode

static inline void lowPowerModeOff(void);
/// \fn static inline void lowPowerModeOff(void)
/// \todo Write code that uses lowPowerMode

static inline void disableInterrupts(void);
/// \fn static inline void disableInterrupts(void)
/// \brief disable global interrupts.
/// \warning Some peripherals rely on interrupts. Disabling interrupts can adversely affect the operation of the peripherals and/or program.
/// \details disableInterrupts() clears the GIE bit in the status register, thus disabling all maskable interrupts. Non-maskable interrupts will not be affected. Disabling interrupts can be useful when you have time critical code or when your delaying execution.
///
/// \return Nothing

static inline void enableInterrupts(void);
/// \fn static inline void enableInterrupts(void)
/// \brief enable global interrupts.
/// \details enableInterrupts() sets the GIE bit in the status register, thus enabling all maskable interrupts.
///
/// \return Nothing

static inline void enterAM(void);
/// \fn static inline void enterAM(void)
/// \brief Enter Active Mode.
/// \details enterAM() enters the MCU into Active mode. When entering Active Mode, the CPU is enabled and all clocks are active.
///
/// \return Nothing

static inline void enterLPM0(void);
/// \fn static inline void enterLPM0(void)
/// \brief Enter Low Power Mode 0
/// \details enterLPM0() enters the MCU into Low Power Mode 0. When entering LPM0, The CPU is off and MCLK is stopped. All other clocks remain active.
///
/// \return Nothing

static inline void enterLPM1(void);
/// \fn static inline void enterLPM1()
/// \brief Enter Low Power Mode 1
/// \details enterLPM1() enters the MCU into Low Power Mode 1. When entering LPM1, the CPU is off, MCLK is stopped, and the DCO is off.
///
/// \return Nothing

static inline void enterLPM2(void);
/// \fn static inline void enterLPM2()
/// \brief Enter Low Power Mode 2
/// \details enterLPM2() enters the MCU into Low Power Mode 2. When entering LPM2, The CPU is off, MCLK is stopped, the DCO is off and SMCLK is stopped. However the DC generator remains active.
///
/// \return Nothing

static inline void enterLPM3(void);
/// \fn static inline void enterLPM3()
/// \brief Enter Low Power Mode 3
/// \details enterLPM3() enters the MCU into Low Power Mode 3. When entering LPM3, the CPU is off, MCLK is stopped, the DCO is off, SMCLK is stopped and the DC generator is off. The only clock that remains enabled in LPM3 is ACLK.
///
/// \return Nothing

static inline void __bis_IE1(unsigned int pos);
/// \attention for Internal use 

