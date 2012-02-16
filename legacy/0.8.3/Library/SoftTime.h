//EasyMSP Copyright 2011 Matthew Burmeister

//delayus
//--------------------------------------------------------
//Delay execution by "x" microseconds.

static inline void delayus(register unsigned int time);
/// \fn static inline void delayus(register unsigned int time)
/// \brief Delays code execution by said microseconds(uS)
/// 
/// \details delayus() delays code execution by said microseconds. 
///
/// \param time Time to pause execution in microseconds(uS)
///
/// \note Please note that execution times may vary due to factors such as:
/// \li CPU Speed
/// \li DCO Calibration
/// \li Interrupts
///
/// Without interrupts, Timing should be within 1%.

static inline void _us(void);
/// \fn static inline void _us(void)
/// \brief Delay exactly 1 microsecond(uS)
/// \attention This is a internal use function and not listed as part of the EasyMSP library.
/// \details _us() delays code execution by exactly one microsecond(uS).
/// \note Please note that pause time may vary due to many factors such as:
/// \li CPU Speed
/// \li DCO Calibration
/// \li Interrupts
///
/// Without interrupts and a calibrated DCO, Timing should be within 1%.

static inline void delayms(register unsigned int time);
/// \fn static inline void delayms(register unsigned int time)
/// \brief Delay execution by said milliseconds(mS)
/// \details delayms() delays code execution by said milliseconds(mS)
///
/// \note Please not that pause time may vary due to many factors such as:
/// \li CPU Speed
/// \li DCO Calibration
/// \li Interrupts
///
/// Without interrupts and a calibrated DCO, timing should be within 1%.
static inline void delaysec(register unsigned int time);
/// \fn static inline void delaysec(register unsigned int time)
/// \brief Delay execution by said seconds
/// \details delayms() delays code execution by said seconds
///
/// \note Please not that pause time may vary due to many factors such as:
/// \li CPU Speed
/// \li DCO Calibration
/// \li Interrupts
///
/// Without interrupts and a calibrated DCO, timing should be within 1%.

static inline void delay(register unsigned int time);
/// \fn static inline void delay(register unsigned int time)
/// \brief Delay execution by said milliseconds(mS)
///
/// \details delayms() delays code execution by said milliseconds(mS)
///
/// \note Please not that pause time may vary due to many factors such as:
/// \li CPU Speed
/// \li DCO Calibration
/// \li Interrupts
///
/// Without interrupts and a calibrated DCO, timing should be within 1%.
///
/// \remark this is a Arduino AFI Function.
