//EasyMSP Copyright 2011 Matthew Burmeister

static int hspiConfig(unsigned int bitorder, unsigned int clockspeed, unsigned int pol, unsigned int phase);
/// \fn static int hspiConfig(unsigned int bitorder, unsigned int clockspeed, unsigned int pol, unsigned int phase)
/// \brief Configures the USI to SPI Mode
/// \details hspiConfig configures to 3 wire SPI Master mode. Allow you then to transmit and receive SPI Serial data.
///
/// \param bitorder Order to shift the data
/// \li MSBFIRST - Shift the MSB First.
/// \li LSBFIRST - Shift the LSB First.
///
/// \param clockspeed SPI Clock speed.
/// \li FAST - SPI Clock speed is SMCLK frequency.
/// \li SLOW - SPI Clock speed is SMCLK frequency divided by 16.
/// \remark You can fine tune the SPI Clock speed by changing SMCLK settings with setSMCLK(). 
///
/// \param pol SPI clock polarity
/// \li HIGH - Idle High
/// \li LOW - Idle Low
///
/// \param phase Clock phase select
/// \li FALLING - Data is changed on the first SCLK edge and captured on the following edge.
/// \li RISING - Data is captured on the first SCLK edge and changed on the following edge.
///
/// Once the function is completed, you then can start receiving or sending SPI data.
///
/// \return 1 - Success
/// \return -1 - Incorrect bitorder
/// \return -2 - Incorrect clock phase
/// \return -3 - Incorrect clock speed
/// \return -4 - Incorrect clock polarity
///
/// \sa hspiOut() hspiIn()


static int hspiOut(unsigned char data);
/// \fn static int hspiOut(unsigned char data)
/// \brief Transmit SPI data via USI
/// \attention You must configure the USI using hspiConfig() before you use this function.
/// \details hspiOut() transmits a byte via 3 wire SPI thru the USI. 
/// 
/// \param data Data to transmit
///
/// \return 1 - Success
/// \return -1 - USI not configured.
/// 
/// \sa hspiIn() hspiConfig()

static unsigned char hspiIn(void);
/// \fn static unsigned char hspiIn(void)
/// \brief Receive SPI data via the USI
/// \attention You must configure the USI using hspiConfig() before you use this function.
/// \details hspiIn() receives a byte via 3 wire SPI thru the USI.
///
/// \return Data
///
/// \sa hspiOut() hspiConfig()

static void usiOff(void);
/// \fn static void usiOff(void)
/// \brief Turns off the USI
/// \details usiOff() turns off the USI. This is useful when you want to save power or release the serial pins from the USI.
///
/// \return Nothing
///
/// \sa hspiConfig

static unsigned char usi_mode=0;
/// \fn static unsigned char usi_mode
/// \brief holds the current USI mode
