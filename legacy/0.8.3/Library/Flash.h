//EasyMSP Copyright 2011 Matthew Burmeister

static inline void flashLock(void);
/// \fn static inline void flashLock(void)
/// \brief Locks the flash from being modified
/// \details flashLock() locks the flash from being written or erased. 

static inline int flashUnlock(unsigned int key);
/// \fn static inline int flashUnlock(unsigned int key)
/// \brief Unlocks the flash for writing
/// \details flashUnlock() Unlocks the flash, Allowing write and erase operations. 
/// 
/// \param key Safety key.
/// the key is KEY or 0xBEEF
///
/// \return 1 - success
/// \return -1 - failure

static inline int flashReadWord(unsigned int *address);
/// \todo Test function
/// \fn static flashReadWord(unsigned int *address)
/// \brief Reads a word (2 bytes) from the flash.
/// \details flashReadWord() Reads a word from the flash.
/// 
/// \param *address Address
/// 
/// \returns Data 

static int flashWriteWord(unsigned int key, unsigned int address, unsigned int data);
/// \todo finish the rest of the function
/// \fn static int flashWriteWord(unsigned int key, unsigned int address, unsigned int data)
/// \brief Writes a word (2 bytes) to the flash.
/// \details flashWriteWord() writes a word to the flash.
///
/// \param key Safety key.
/// the key is KEY or 0xBEEF
///
/// \param address Address to write to
/// \param data Data to write
///
/// \return 1 - success
/// \return -1 - failure

static int flashEraseSegment(unsigned int key, unsigned int key2, unsigned int segment);
/// \todo Write function
/// \fn static int flashEraseSegment(unsigned int key, unsigned int key2, unsigned int segment)
/// \brief Erases a info segment.
/// \details flashEraseSegment() erases a info segment.
/// 
/// \param key Safety key.
/// the key is KEY or 0xBEEF
///
/// \param key2 Safety key.
/// the key is KEY2 or 0x0E0E
///
/// \param segment Segment to erase
/// \li SegmentA
/// \li SegmentB
/// \li SegmentC
/// \li SegmentD
///
/// \return 1  - Success
/// \return -1  - Failure

static int flashEraseMainMemory(unsigned int key, unsigned int key2);
/// \todo Write function
/// \fn static int flashEraseMainMemory(unsigned int key, unsigned int key2)
/// \brief Erases code memory
/// \details flashEraseMainMemory erases all code data. Segment data is untouched.
/// \attention Code that executes this command must run from ram.

/// \param key Safety key.
/// the key is KEY or 0xBEEF
///
/// \param key2 Safety key.
/// the key is KEY2 or 0x0E0E
///
/// \return 1 on success, -1 on failure

static int flashEraseAll(unsigned int key, unsigned int key2);
/// \todo Write function
/// \fn static int flashEraseAll(unsigned int key, unsigned int key2)
/// \brief Erases all memory and segments.
/// \warning This function WILL ERASE ALL MEMORY AND SEGMENTS!
/// 
/// \warning Segment A will be erased. This segment holds critical information. Unless this information is rewritten, your device will not work with the EasyMSP System.
/// \attention Code that executes this command must run from ram.
///
/// flashEraseAll() Erases all memory on the device, including segment data.
///
/// \param key First safety key
/// \param key2 Second saftey key.
///
/// \return 1 : Success
/// \return -1 : Key mismatch
/// \return -2 : Flash Contoller Error

