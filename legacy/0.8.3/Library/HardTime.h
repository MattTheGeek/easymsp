//EasyMSP Copyright 2011 Matthew Burmeister

//HardTime

static inline void delay(register unsigned int time);
/// \fn static inline void delay(register unsigned int time)
/// \warning Using this function will stop any timer background task on devices with less than two hardware timers. Please consult your device datasheet.
/// \brief Delays execution by said milliseconds(mS) using hardware timers
/// \details delay() will delay program execution by said milliseconds using a hardware timer and a crystal.
/// \param time Time to delay execution
/// \attention You must define "USEHARDWARETIMING" before you can use hardware timing.
/// \remark Hardware timing has better power saving and precision, but requires a use of a hardware timer and a 32Khz crystal.
static inline void delayus(register unsigned int time);
/// \fn static inline void delayus(register unsigned int time)
/// \warning Using this function will stop any timer background task on devices with less than two hardware timers. Please consult your device datasheet.
/// \brief Delays execution by said microseconds(uS) using hardware timers
/// \details delayus() will delay program execution by said microseconds using a hardware timer and a crystal.
/// \param time Time to delay execution
/// \attention You must define "USEHARDWARETIMING" before you can use hardware timing.
/// \remark Hardware timing has better power saving and precision, but requires a use of a hardware timer and a 32Khz crystal.
static inline void delayms(register unsigned int time);
/// \fn static inline void delayms(register unsigned int time)
/// \warning Using this function will stop any timer background task on devices with less than two hardware timers. Please consult your device datasheet.
/// \brief Delays execution by said milliseconds(mS) using hardware timers
/// \details delayms() will delay program execution by said milliseconds using a hardware timer and a crystal.
/// \param time Time to delay execution
/// \attention You must define "USEHARDWARETIMING" before you can use hardware timing.
/// \remark Hardware timing has better power saving and precision, but requires a use of a hardware timer and a 32Khz crystal.
static inline void delaysec(register unsigned int time);
/// \fn static inline void delaysec(register unsigned int time)
/// \warning Using this function will stop any timer background task on devices with less than two hardware timers. Please consult your device datasheet.
/// \brief Delays execution by said seconds using hardware timers
/// \details delaysec() will delay program execution by said seconds using a hardware timer and a crystal.
/// \param time Time to delay execution
/// \attention You must define "USEHARDWARETIMING" before you can use hardware timing.
/// \remark Hardware timing has better power saving and precision, but requires a use of a hardware timer and a 32Khz crystal.