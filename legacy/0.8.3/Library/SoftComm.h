//EasyMSP Copyright 2011 Matthew Burmeister

void shiftOut(unsigned int DOUT, unsigned int SCLK, unsigned int bitorder, unsigned char data);
/// \fn  void shiftOut(unsigned int DOUT, unsigned int SCLK, unsigned int bitorder, unsigned char data)
/// \brief Transmit SPI Serial data
/// 
/// \details shiftOut() transmits a byte of data via three wire SPI. The speed of the SPI clock is dependant on the devices current MCLK speed.
///
/// \param DOUT Serial data out pin
/// \param SCLK Serial clock pin
/// \param bitorder Order to shift the bits
/// \li MSFIRST - Shift the left most (MSB) bit first
/// \li LSBFIRST - Shift the right most (LSB) bit first
/// \param data - Data to shift out
///
/// \sa shiftIn()

unsigned char shiftIn(unsigned int DIN, unsigned int SCLK, unsigned int bitorder);
/// \fn  unsigned char shiftIn(unsigned int DIN, unsigned int SCLK, unsigned int bitorder)
/// \brief Receive SPI Serial data
///
/// \details shiftIn() receives a byte of SPI Serial data. The speed of the SPI clock is dependant on the MCLK speed. shiftIn() also provides a timeout function, to prevent the program from freezing from unreceived or malformed data.
///
/// \param DIN Serial Data in pin
/// \param SCLK Serial clock pin 
/// \param bitorder - Order to receive bits
/// \li MSBFIRST - Receive the left most (MSB) bit first
/// \li LSBFIRST - Receive the right most (LSB) bit first
///
/// \return Data received
///
/// \sa shiftOut()
