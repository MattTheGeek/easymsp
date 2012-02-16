//EasyMSP Copyright 2011 Matthew Burmeister

static unsigned int analogRead(unsigned int pin);
/// \fn static unsigned int analogRead(unsigned int pin)
/// \brief Reads the analog value on said pin
/// \details analogRead() reads the analog value of said pin using the on board ADC10.
///
/// \param pin Pin to read
///
/// \return Analog value of pin. 0 ... 1024
///
/// \sa analongReference() analogConfig()
///
/// \remark analogRead() is a EasyMSP function and a Arduino function.

static void analogReference(unsigned int ref);
/// \fn static void analogReference(unsigned int ref)
/// \brief Sets the ADC10 Reference mode
/// \details analogReference() sets the ADC10s reference mode. 
///
/// \param ref ADC10 Referece mode 
/// \li DEFAULT - Default reference mode.
/// \li INTERNAL - Internal reference mode.
/// \li INTERNAL2V56 - Internal 2.56V reference mode.
/// \li INTERNAL1V5 -Internal 1.5V reference mode.
/// \li EXTERNAL - External reference mode.
///
/// \sa analogRead() analogConfig()
///
/// \return Nothing
///
/// \remark analogReference() is a EasyMSP function and a Arduino Function.


static int analogConfig(unsigned int holdtime, unsigned int format, unsigned int invert);
/// \fn static int analogConfig(unsigned int holdtime, unsigned int format, unsigned int invert)
/// \brief Configures advanced settings for the ADC10.
/// 
/// \details analogConfig() allows you to configure advanced settings for the ADC10.
/// Settings such as Holding time, Data format and data inversion.
///
/// \param holdtime 
///	Valid hold times are:
/// \li 4 - 4 Clock cycles
/// \li 8 - 8 Clock cycles
/// \li 16 - 16 Clock cycles
/// \li 64 - 64 Clock cycles
///
/// \param format
/// \li BINARY - Analog value is in pure binary form
/// \li TWOCOMP - Analog value is Two's complement form
///
/// \param invert
/// \li INVERTED - The result is inverted
/// \li NOTINVERTED - The result is not inverted
///
/// \return 
/// \li 1 : Success
/// \li -1 : Wrong hold time config
/// \li -2 : Wrong format config
/// \li -3 : Wrong invert config

static int _holdconfig = 0;
/// \var static int _holdconfig
/// \brief Holds if hold setting was configured
/// \attention For internal use only
