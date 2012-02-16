//EasyMSP Copyright 2011 Matthew Burmeister

static unsigned int compare(unsigned int pospin, unsigned int negpin);
/// \fn static unsigned int compare(unsigned int pospin, unsigned int negpin)
/// \brief Compare two voltages
/// \details compare() uses the on board voltage comparator to compare two external voltage sources.
/// \todo map numbers to pins groups.
/// \todo Test compare
/// \return Return state is dependant on configured settings.

static void compareConfig(unsigned int ref, unsigned int _short, unsigned int filter, unsigned int exchange, unsigned int refsel);
/// \fn static void compareConfig(unsigned int ref, unsigned int _short, unsigned int filter, unsigned int exchange, unsigned int refsel)
/// \brief Configure the on board voltage comparator.
/// \details compareConfig() configures the on board voltage comparator for use.
///
/// \param ref comparator reference
/// \li EXTERNAL - External reference
/// \li VDDHALF - Reference voltage is VDD / 2
/// \li VDDQUARTER - Reference voltage is VDD / 4
/// \li DIODE - Reference is DIODE
///
/// \param _short Short inputs?
/// \li YES - Short inputs
/// \li NO - Do not short inputs
///
/// \param filter Filter the output?
/// \li YES - Filter the output
/// \li NO - Do not filter the output
///
/// \param exchange Swap input pins?
/// \li YES - Swap pins
/// \li NO - Do not swap pins
///
/// \param refsel selects which terminal the reference voltage is applied to.
/// \li POSITIVE - Reference voltage is applied to the positive terminal
/// \li NEGATIVE - Reference voltage is applied to the negative terminal
///
/// \return Nothing
///
/// \sa compare()
