//EasyMSP Copyright 2011 Matthew Burmeister

static void high(unsigned int pin);
/// \fn static void high(unsigned int pin)
/// \brief Makes a pin high
///
///	high() makes a GPIO pin HIGH or outputing 3.3V (or VCC Voltage).
///
/// \param pin Pin to make high
///
/// pins 0 thru 7 are located on P1 (PORT1)
///	\li P1.0 = 0
/// \li P1.1 = 1
/// \li P1.2 = 2
/// \li P1.3 = 3
/// \li P1.4 = 4
/// \li P1.5 = 5
/// \li P1.6 = 6
/// \li P1.7 = 7
///
/// pins 8 thru 15 are located on P2 (PORT2)
/// \li P2.0 = 8
/// \li P2.1 = 9
/// \li P2.2 = 10
/// \li P2.3 = 11
/// \li P2.4 = 12
/// \li P2.5 = 13
/// \li P2.6 = 14
/// \li P2.7 = 15
///
/// Larger pin count devices will feature a third GPIO Port, P3 (PORT3) and covers pins 16 to 23.
/// \li P3.0 = 16
/// \li P3.1 = 17
/// \li P3.2 = 18
/// \li P3.3 = 19
/// \li P3.4 = 20
/// \li P3.5 = 21
/// \li P3.6 = 22
/// \li P3.7 = 23
///
/// For example, if you wanted to make P1.3 high, you would use pin 3. But if you wanted to make P2.3 high, you would use pin 11.
///	
///
/// \return Nothing, Function is void.
/// 
/// \remark if a pin you enter does not exist on the chip, the function ignores the input.
///
/// \sa low() digitalWrite()
	
static void low(unsigned int pin);
/// \fn static void low(unsigned int pin)
/// \brief Makes a pin low
///
/// low() makes a GPIO pin low, or outputing 0V.
///
/// \param pin Pin to make low
/// pins 0 thru 7 are located on P1 (PORT1)
///	\li P1.0 = 0
/// \li P1.1 = 1
/// \li P1.2 = 2
/// \li P1.3 = 3
/// \li P1.4 = 4
/// \li P1.5 = 5
/// \li P1.6 = 6
/// \li P1.7 = 7
///
/// pins 8 thru 15 are located on P2 (PORT2)
/// \li P2.0 = 8
/// \li P2.1 = 9
/// \li P2.2 = 10
/// \li P2.3 = 11
/// \li P2.4 = 12
/// \li P2.5 = 13
/// \li P2.6 = 14
/// \li P2.7 = 15
///
/// Larger pin count devices will feature a third GPIO Port, P3 (PORT3) and covers pins 16 to 23.
/// \li P3.0 = 16
/// \li P3.1 = 17
/// \li P3.2 = 18
/// \li P3.3 = 19
/// \li P3.4 = 20
/// \li P3.5 = 21
/// \li P3.6 = 22
/// \li P3.7 = 23
///
/// For example, if you wanted to make P1.3 low, you would use pin 3. But if you wanted to make P2.3 low, you would use pin 11.
///
/// \return Nothing, Function is void.
/// 
/// \remark if a pin you enter does not exist on the chip, the function ignores the input.
///
/// \sa high() digitalWrite()

static void input(unsigned int pin);
/// \fn static void input(unsigned int pin)
/// \brief Makes a pin a input
/// 
/// input() makes a GPIO pin into a input. 
/// 
/// \param pin Pin to make into a input
/// pins 0 thru 7 are located on P1 (PORT1)
///	\li P1.0 = 0
/// \li P1.1 = 1
/// \li P1.2 = 2
/// \li P1.3 = 3
/// \li P1.4 = 4
/// \li P1.5 = 5
/// \li P1.6 = 6
/// \li P1.7 = 7
///
/// pins 8 thru 15 are located on P2 (PORT2)
/// \li P2.0 = 8
/// \li P2.1 = 9
/// \li P2.2 = 10
/// \li P2.3 = 11
/// \li P2.4 = 12
/// \li P2.5 = 13
/// \li P2.6 = 14
/// \li P2.7 = 15
///
/// Larger pin count devices will feature a third GPIO Port, P3 (PORT3) and covers pins 16 to 23.
/// \li P3.0 = 16
/// \li P3.1 = 17
/// \li P3.2 = 18
/// \li P3.3 = 19
/// \li P3.4 = 20
/// \li P3.5 = 21
/// \li P3.6 = 22
/// \li P3.7 = 23
///
/// For example, if you wanted to make P1.3 a input, you would use 3. But if you wanted to make P2.3 a input, you would use 11.
///	
///
/// \return Nothing, Function is void.
/// 
/// \remark if a pin you enter does not exist on the chip, the function ignores the input.
///
/// \sa output() pinMode()

static void output(unsigned int pin);
/// \fn static void output(unsigned int pin)
/// \brief Makes a pin a output
///
/// output() makes a GPIO pin into a output.
///
/// \param pin Pin to make into a output
/// pins 0 thru 7 are located on P1 (PORT1)
///	\li P1.0 = 0
/// \li P1.1 = 1
/// \li P1.2 = 2
/// \li P1.3 = 3
/// \li P1.4 = 4
/// \li P1.5 = 5
/// \li P1.6 = 6
/// \li P1.7 = 7
///
/// pins 8 thru 15 are located on P2 (PORT2)
/// \li P2.0 = 8
/// \li P2.1 = 9
/// \li P2.2 = 10
/// \li P2.3 = 11
/// \li P2.4 = 12
/// \li P2.5 = 13
/// \li P2.6 = 14
/// \li P2.7 = 15
///
/// Larger pin count devices will feature a third GPIO Port, P3 (PORT3) and covers pins 16 to 23.
/// \li P3.0 = 16
/// \li P3.1 = 17
/// \li P3.2 = 18
/// \li P3.3 = 19
/// \li P3.4 = 20
/// \li P3.5 = 21
/// \li P3.6 = 22
/// \li P3.7 = 23
///
/// For example, if you wanted to make P1.3 a output, you would use 3. But if you wanted to make P2.3 a output, you would use 11.
///	
///
/// \return Nothing, Function is void.
/// 
/// \remark if a pin you enter does not exist on the chip, the function ignores the input.
///
/// \sa input() pinMode()

static unsigned int read(unsigned int pin);
/// \fn static unsigned int read(unsigned int pin)
/// \brief Returns a pins current state
///
/// read() reads a GPIO and then returns a value depending on the state of the GPIO pin.
///
/// \param pin Pin to read.
/// pins 0 thru 7 are located on P1 (PORT1)
///	\li P1.0 = 0
/// \li P1.1 = 1
/// \li P1.2 = 2
/// \li P1.3 = 3
/// \li P1.4 = 4
/// \li P1.5 = 5
/// \li P1.6 = 6
/// \li P1.7 = 7
///
/// pins 8 thru 15 are located on P2 (PORT2)
/// \li P2.0 = 8
/// \li P2.1 = 9
/// \li P2.2 = 10
/// \li P2.3 = 11
/// \li P2.4 = 12
/// \li P2.5 = 13
/// \li P2.6 = 14
/// \li P2.7 = 15
///
/// Larger pin count devices will feature a third GPIO Port, P3 (PORT3) and covers pins 16 to 23.
/// \li P3.0 = 16
/// \li P3.1 = 17
/// \li P3.2 = 18
/// \li P3.3 = 19
/// \li P3.4 = 20
/// \li P3.5 = 21
/// \li P3.6 = 22
/// \li P3.7 = 23
///
/// For example, if you wanted to read P1.3, you would use 3. But if you wanted to read P2.3, you would use 11.
///	
/// \return 1 - Pin is high
/// \return 0 - Pin is low or does not exist.
/// 
/// \remark if a pin you enter does not exist on the chip, the function ignores the input and returns a zero.
///
/// \sa digitalRead()

static void enableResistor(unsigned int pin);
/// \fn static void enableResistor(unsigned int pin)
/// \brief Enables the pull up or pull down resistor on said pin.
/// \attention Some ports may not have pullup or pulldown resistors. Please check your device datasheet.
///
/// enableResistor() enables the built in pullup or pulldown resistor on said pin.
///
/// \param pin Pin to enable the resistor on.
/// pins 0 thru 7 are located on P1 (PORT1)
///	\li P1.0 = 0
/// \li P1.1 = 1
/// \li P1.2 = 2
/// \li P1.3 = 3
/// \li P1.4 = 4
/// \li P1.5 = 5
/// \li P1.6 = 6
/// \li P1.7 = 7
///
/// pins 8 thru 15 are located on P2 (PORT2)
/// \li P2.0 = 8
/// \li P2.1 = 9
/// \li P2.2 = 10
/// \li P2.3 = 11
/// \li P2.4 = 12
/// \li P2.5 = 13
/// \li P2.6 = 14
/// \li P2.7 = 15
///
/// Larger pin count devices will feature a third GPIO Port, P3 (PORT3) and covers pins 16 to 23.
/// \li P3.0 = 16
/// \li P3.1 = 17
/// \li P3.2 = 18
/// \li P3.3 = 19
/// \li P3.4 = 20
/// \li P3.5 = 21
/// \li P3.6 = 22
/// \li P3.7 = 23
///
/// \return Nothing
///
/// \sa disableResistor() pinPullUp() pinPullDown()

static void disableResistor(unsigned int pin);
/// \fn static void disableResistor(unsigned int pin)
/// \brief Disables the pull up or pull down resistor on said pin.
/// \attention Some ports may not have pullup or pulldown resistors. Please check your device datasheet.
/// 
/// disableResistor() disables the built in pullup or pulldown resistor on said pin.
///
/// \param pin Pin to disable the resistor on
/// pins 0 thru 7 are located on P1 (PORT1)
///	\li P1.0 = 0
/// \li P1.1 = 1
/// \li P1.2 = 2
/// \li P1.3 = 3
/// \li P1.4 = 4
/// \li P1.5 = 5
/// \li P1.6 = 6
/// \li P1.7 = 7
///
/// pins 8 thru 15 are located on P2 (PORT2)
/// \li P2.0 = 8
/// \li P2.1 = 9
/// \li P2.2 = 10
/// \li P2.3 = 11
/// \li P2.4 = 12
/// \li P2.5 = 13
/// \li P2.6 = 14
/// \li P2.7 = 15
///
/// Larger pin count devices will feature a third GPIO Port, P3 (PORT3) and covers pins 16 to 23.
/// \li P3.0 = 16
/// \li P3.1 = 17
/// \li P3.2 = 18
/// \li P3.3 = 19
/// \li P3.4 = 20
/// \li P3.5 = 21
/// \li P3.6 = 22
/// \li P3.7 = 23
///
/// \return Nothing
///
/// \sa enableResistor() pinPullUp() pinPullDown()

static void pinPullUp(unsigned int pin);
/// \fn static void pinPullUp(unsigned int pin)
/// \brief Pulls up the said pin.
/// \attention You must enable the resistor on the pin with enableResistor() before you attempt to pull up the pin.
///
/// pinPullUp() pulls up the said pin using the built in resistor. 
///
/// \param pin Pin to pullup
/// pins 0 thru 7 are located on P1 (PORT1)
///	\li P1.0 = 0
/// \li P1.1 = 1
/// \li P1.2 = 2
/// \li P1.3 = 3
/// \li P1.4 = 4
/// \li P1.5 = 5
/// \li P1.6 = 6
/// \li P1.7 = 7
///
/// pins 8 thru 15 are located on P2 (PORT2)
/// \li P2.0 = 8
/// \li P2.1 = 9
/// \li P2.2 = 10
/// \li P2.3 = 11
/// \li P2.4 = 12
/// \li P2.5 = 13
/// \li P2.6 = 14
/// \li P2.7 = 15
///
/// Larger pin count devices will feature a third GPIO Port, P3 (PORT3) and covers pins 16 to 23.
/// \li P3.0 = 16
/// \li P3.1 = 17
/// \li P3.2 = 18
/// \li P3.3 = 19
/// \li P3.4 = 20
/// \li P3.5 = 21
/// \li P3.6 = 22
/// \li P3.7 = 23
///
/// \return Nothing
///
/// \sa enableResistor() disableResistor() pinPullDown()

static void pinPullDown(unsigned int pin);
/// \fn static void pinPullDown(unsigned int pin)
/// \brief Pulls down the said pin
/// \attention You must enable the resistor on the pin with enableResistor() before you attempt to pull down the pin.
///
/// pinPullDown() pulls the down the said pin using the built in resistor.
///
/// \param pin Pin to pulldown
/// pins 0 thru 7 are located on P1 (PORT1)
///	\li P1.0 = 0
/// \li P1.1 = 1
/// \li P1.2 = 2
/// \li P1.3 = 3
/// \li P1.4 = 4
/// \li P1.5 = 5
/// \li P1.6 = 6
/// \li P1.7 = 7
///
/// pins 8 thru 15 are located on P2 (PORT2)
/// \li P2.0 = 8
/// \li P2.1 = 9
/// \li P2.2 = 10
/// \li P2.3 = 11
/// \li P2.4 = 12
/// \li P2.5 = 13
/// \li P2.6 = 14
/// \li P2.7 = 15
///
/// Larger pin count devices will feature a third GPIO Port, P3 (PORT3) and covers pins 16 to 23.
/// \li P3.0 = 16
/// \li P3.1 = 17
/// \li P3.2 = 18
/// \li P3.3 = 19
/// \li P3.4 = 20
/// \li P3.5 = 21
/// \li P3.6 = 22
/// \li P3.7 = 23
///
/// \return Nothing
///
/// \sa enableResistor() disableResistor() pinPullUp()

static unsigned int decodeInterruptPin(unsigned int port);
/// \fn static unsigned int decodeInterruptPin(unsigned int port)
/// \brief decodeInterruptPin() decodes and returns what pin caused the interrupt.
/// 
/// decodes the the port interrupt status registers and returns the pin that caused the interrupt.
///
/// \param port The port to decode
/// \li PORT1 - Decode interrupt on PORT1
/// \li PORT2 - Decode interrupt on PORT2
///
/// PORT3 Does not have interrupt capability
/// 
/// \return Pin Number
///
/// \attention This function will return a 0 if a error occurrs.

static void pinInterruptEnable(unsigned int pin);
/// \todo Test function
/// \fn static void pinInterruptEnable(unsigned int pin)
/// \brief Enables interrupts for said pin.
///
/// pinInterruptEnable enables interrupts for the said pin.
///
/// \param pin Pin to enable interrupts for
/// pins 0 thru 7 are located on P1 (PORT1)
///	\li P1.0 = 0
/// \li P1.1 = 1
/// \li P1.2 = 2
/// \li P1.3 = 3
/// \li P1.4 = 4
/// \li P1.5 = 5
/// \li P1.6 = 6
/// \li P1.7 = 7
///
/// pins 8 thru 15 are located on P2 (PORT2)
/// \li P2.0 = 8
/// \li P2.1 = 9
/// \li P2.2 = 10
/// \li P2.3 = 11
/// \li P2.4 = 12
/// \li P2.5 = 13
/// \li P2.6 = 14
/// \li P2.7 = 15
///
/// PORT3 Does not have interrupt capability
///
/// \return Nothing
/// 
/// \sa pinInterruptDisable()

static void pinInterruptDisable(unsigned int pin);
/// \todo Test function
/// \fn static void pinInterruptDisable(unsigned int pin)
/// \brief Disables interrupts for said pin.
///
/// pinInterruptDisable disables interrupts for the said pin.
///
/// \param pin Pin to disable interrupts for
///	\li P1.0 = 0
/// \li P1.1 = 1
/// \li P1.2 = 2
/// \li P1.3 = 3
/// \li P1.4 = 4
/// \li P1.5 = 5
/// \li P1.6 = 6
/// \li P1.7 = 7
///
/// pins 8 thru 15 are located on P2 (PORT2)
/// \li P2.0 = 8
/// \li P2.1 = 9
/// \li P2.2 = 10
/// \li P2.3 = 11
/// \li P2.4 = 12
/// \li P2.5 = 13
/// \li P2.6 = 14
/// \li P2.7 = 15
///
/// PORT3 Does not have interrupt capability
///
/// \return Nothing
/// 
/// \sa pinInterruptEnable()

static void interruptEdgeSelect(unsigned int pin, unsigned int edge);
/// \fn static void interruptEdgeSelect(unsigned int pin, unsigned int edge)
/// \brief Selects what edge to interrupt on.
/// 
/// InterruptEdgeSelect() changes on how the pin reacts to logic level changes.
///
/// \param pin Pin to configure
/// 
/// \param edge Sets what edge to interrupt on
///
/// RISING : Interrupt when the pin logic level rises. 
/// FAILING: Interrupt when the pin logic level falls.
///
/// \return Nothing

/// \todo Add interrupt handlers for port interrupts.


