#define PANIC_GENERAL 0xFFFF
#define PANIC_FROM_EMERGENCY 0xFFFE

#define PANIC_WATCHDOG_EXPIRED 0xFFFD
#define PANIC_WATCHDOG_KEY_INVALID 0xFFFC
#define PANIC_BROWNOUT 0xFFFB
#define PANIC_ILLEGAL_INSTRUCTION 0xFFFA
#define PANIC_ILLEGAL_FETCH 0xFFF9
#define PANIC_FLASH_KEY_INVALID 0xFFF8
#define PANIC_ILLEGAL_FLASH_ACCESS 0xFFF7

#define PANIC_STACK_CORRUPT 0xFFF6
#define PANIC_STACK_TAINTED 0xFFF5

#define PANIC_CPU_CHECK_FAILED 0xFFF4
#define PANIC_BAD_RAM_FOUND 0xFFF3
#define PANIC_BAD_FLASH_FOUND 0xFFF2

#define PANIC_SILCON_BUG 0xFFF1

#define EMERGENCY_GENERAL 0xFFEF
#define EMERGENCY_FLASH_CRC_MISMATCH 0xFFEE
#define EMERGENCY_STACK_OVERFLOW 0xFEED
#define EMERGENCY_CLOCK_FAILURE 0xFEEC

#define ERR_GENERAL 100

#define ERR_ARG_OUT_OF_RANGE 101
#define ERR_ARG_INVAILD 102
#define ERR_ARG_EMPTY
#define ERR_NO_ARGUMENTS 103
#define ERR_TO_MANY_ARGUMENTS 104
#define ERR_NOT_ENOUGH_ARGUMENTS 105

#define DOES_NOT_EXIST
#define IS_LOCKED
#define IS_UNLOCKED
#define HAS_CHANGED
#define HAS_NOT_CHANGED
#define IN_USE

#define NOT_ENOUGH_RAM
#define NOT_ENOUGH_FLASH
#define TOO_BIG
#define TOO_SMALL
#define NO_SLOTS_FREE
#define NO_ENTRIES_FREE
#define NO_GAP_FREE
#define NONE_FREE

#define NO_MORE_FREE
#define NO_MORE_ENTRIES
#define NO_MORE_GAPS
#define NO_MORE_SLOTS

#define NO_MATCH
#define NO_MATCHES

#define FOUND_MATCH
#define MATCH_FOUND

#define FOUND_MATCHES
#define MATCHES_FOUND

#define START_OF_TABLE
#define START_OF_STRING
#define END_OF_TABLE
#define END_OF_STRING

#define IS_PAGED
#define IN_MEMORY
#define PAGED_OUT
#define HAS_MOVED
