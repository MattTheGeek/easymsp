//EasyMSP Copyright 2011 Matthew Burmeister

static unsigned int _currentfreq = 1; //This varible holds the system current clock.
/// \var static unsigned int _currentfreq
/// \brief Holds the current CPU frequency.

static void setCPUFreq(unsigned int freq);
/// \fn static void setCPUFreq(unsigned int freq)
/// \brief Sets the CPU Operating frequency
/// \details setCPUFreq() sets the CPU operating frequency. Higher frequencies yield more performance, however increases power requirments both in voltage and current.
/// 
/// Changing the clock frequency changes delay speeds. changing the frequency to 4MHZ would result in a 4x increase of delay speed, While in K250, Would result in a 4x decrease in delay speed.
///
/// \param freq Frequency for the CPU to be set to. 
/// \li M1 - 1Mhz
/// \li K500 - 500Khz
/// \li K250 - 250Khz
/// \li K125 - 125Khz
/// \li K32 - 32Khz
/// \li K22 - 22Khz
/// \li DAMNSLOW - 2Khz
///
/// \attention K32 requires a external 32Khz crystal to be placed on XTAL Pins.
/// \remarks I just had to add DAMNSLOW, It just seem fitting.

static void setDCOFreq(unsigned int dco, unsigned int mod, unsigned int rsel);
/// \fn static void setDCOFreq(unsigned int dco, unsigned int mod, unsigned int rsel)
/// \brief Sets the frequency of the DCO
/// \details setDCOFreq() sets the frequency of the DCO.
///
/// \param dco DCO frequency select
/// Vaild range is 0 to 8.
///
/// \param mod Modulator selection
/// Valid range is 0 to 32
///
/// \param rsel Range Select
/// Valid range is 0 to 16.
/// 
/// \return Nothing

static inline void enableDCO(void);
/// \fn static inline void enableDCO(void)
/// \brief Enables the DCO
/// \details enableDCO() enables the DCO.
///
/// \return Nothing

static inline void disableDCO(void);
/// \fn static inline void disableDCO(void)
/// \brief Disables the DCO
/// \details disableDCO() Disables the DCO. 
///
/// \return Nothing

static void setMCLK(unsigned int source, unsigned int div);
/// \fn static void setMCLK(unsigned int source, unsigned int div)
/// \brief Set MCLK source and divsion settings
/// \details setMCLK() Configures the MCLK (CPU Clock). Changing the CPU clock speed can affect timing, Please see setCPUFreq()
/// 
/// \param source MCLK Clock source
/// Valid clock sources are:
/// \li DCOCLK - DCO Clock
/// \li VLOCLK - VLO Clock
/// \li CRYSTAL - 32Khz crystal
///
/// \param div Clock divisor
/// Valid clock divisors are:
/// \li 1
/// \li 2
/// \li 4
/// \li 8
///
/// \return Nothing

static void setSMCLK(unsigned int source, unsigned int div);
/// \fn static void setSMCLK(unsigned int source, unsigned int div)
/// \brief Set SMCLK source and divsion settings
/// \details setMCLK() Configures the SMCLK. Changing the SubMaster clock can affect the operating speed or behavior of some peripherals. peripherals affected are ADCs, USCI, USI, WDT+, and Timers. 
/// 
/// \param source SMCLK Clock source
/// Valid clock sources are:
/// \li DCOCLK - DCO Clock
/// \li VLOCLK - VLO Clock
/// \li CRYSTAL - 32Khz crystal
///
/// \param div Clock divisor
/// Valid clock divisors are:
/// \li 1
/// \li 2
/// \li 4
/// \li 8
///
/// \return Nothing

static void setACLK(unsigned int source, unsigned int div);
/// \fn static void setACLK(unsigned int source, unsigned int div)
/// \brief Set ACLK source and divsion settings
/// \details setACLK() Configures the ACLK. Chaning the Aux Clock can affect the operating speed or behavior of some peripherals such as the WDT+ and Timers.
/// 
/// \param source ACLK Clock source
/// Valid clock sources are:
/// \li VLOCLK - VLO Clock
/// \li CRYSTAL - 32Khz crystal
///
/// \param div Clock divisor
/// Valid clock divisors are:
/// \li 1
/// \li 2
/// \li 4
/// \li 8
///
/// \return Nothing

