//EasyMSP Copyright 2011 Matthew Burmeister

static int enableTimer(unsigned int clocksource, unsigned int divs);
/// \fn static int enableTimer(unsigned int clocksource, unsigned int divs)
/// \brief Enables a periodic interrupt.
/// \details enableTimer() is a function to provide a perodic interrupt for the user. The period of which the timer interrupts at is defined by the chosen clock source speed and the divider.
/// 
/// interrupttime = (CLK / DIV)
/// 
/// The user must also provide a function named WDT_int(). EasyMSP will Call WDT_int() each time a interrupt fires.
/// \attention You must define WDTINT or code will not compile correctly.
///
/// \param clocksource Select a clock source to source from.
/// \li MCLK
/// \li ACLK
/// 
/// \attention Please note that selecting a fast interrupt period can result in a stack overflow, Crashing the system. 
/// \param divs Clock divider
/// \li 64
/// \li 512
/// \li 8192
/// \li 32768
///
/// \return 
/// \li 1 - Success
/// \li -1 - Incorrect divisor
///
/// \sa disableTimer()

static void disableTimer(void);
/// \fn static void disableTimer(void)
/// \brief Disables the periodic interrupt.
/// \details disableTimer() stops the periodic interrupt from firing.
///
/// \return Nothing
///
/// \sa enableTimer()

static void clearWD(void);
/// \fn static void clearWD(void)
/// \brief Clears the watchdog's counter regsister
/// \details clearWD() clears the watchdog's counter regsister, preventing the watchdog from expiring.
///
/// \return Nothing
///
/// \sa stopWD() disableWD() enableWD()

static void disableWD(void);
/// \fn static void disableWD(void)
/// \brief Disables the system watchdog
/// \details disableWD() disables the systems watchdog.
///
/// \return Nothing
///
/// \sa stopWD() clearWD() enableWD()

static int enableWD(unsigned int clocksource, unsigned int divs);
/// \fn static int enableWD(unsigned int clocksource, unsigned int divs)
/// \attention The user must clear the watchdog before it expires, or a PUC (RESET) will occur.
/// \brief Enables the system watchdog
/// \details enableWD() enables the system watchdog, preventing the system from hanging due to malfunctioning code. However, the user must clear the watchdog before it expires or a reset will occur. The user can also set how long it takes for the watchdog to expire.
/// 
/// \param clocksource Select a clock source to source from.
/// \li MCLK
/// \li ACLK
/// 
/// \param divs Clock divider
/// \li 64
/// \li 512
/// \li 8192
/// \li 32768
///
/// \return 
/// \li 1 - Success
/// \li -1 - Incorrect divisor
///
/// \sa disableWD() clearWD()
