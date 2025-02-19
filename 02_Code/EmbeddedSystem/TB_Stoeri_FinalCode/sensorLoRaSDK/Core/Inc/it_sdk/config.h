/* ==========================================================
 * config.h - SDK Configuration file
 * Project : Disk91 SDK
 * ----------------------------------------------------------
 * Created on: 2 sept. 2018
 *     Author: Paul Pinault aka Disk91
 * ----------------------------------------------------------
 * Copyright (C) 2018  Disk91
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU LESSER General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * ----------------------------------------------------------
 * 
 *
 * ==========================================================
 */

#ifndef IT_SDK_CONFIG_H_
#define IT_SDK_CONFIG_H_

#include <it_sdk/config_defines.h>

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// | SDK SETTING                   | USER SELECTED VALUE                  | SETTING DESCRIPTION                   |
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ITSDK_VERSION				"1.6.0-master"							// SDK Version String (do not change it)
#define ITSDK_VERSION_BYTE			0x16									//  SDK 1 Byte version corresponding to previous on (do not change it)

#define ITSDK_USER_VERSION			"0.1"									// CHANGE ME - Version of your firwmare
#define ITSDK_USER_VERSION_BYTE		0x01									// CHANGE ME - Version of your firwmare 4bits MAJOR / 4bits MINOR

#define ITSDK_CUBEMX_VERSION	    __CUBEMX_VERSION500						// Version of cube MX
#define ITSDK_PLATFORM 				__PLATFORM_STM32L0						// Hardware platform selection
#define ITSDK_DEVICE				__DEVICE_STM32L072XX					// Specific device
#define ITSDK_WITH_DRIVERS			__ENABLE								// Includes configDrivers.h
#define ITSDK_RAM_SIZE				(20*1024)								// RAM Memory size
#define ITSDK_EPROM_SIZE			(6*1024)								// EEPROM size
#define ITSDK_WITH_UART				( __UART_USART2 )						// Use USART2 for debug and console
#define ITSDK_WITH_UART_RXIRQ		__UART_USART2							// Setup some of the UART with IRQ enabled for RX
#define ITSDK_WITH_UART_RXIRQ_BUFSZ 64										// Size of the UART IRQ RX circular buffer (power of 2)
#define ITSDK_WITH_RTC				__RTC_ENABLED							// The Rtc is usd in the firmware
#define ITSDK_WITH_CLK_ADJUST		__ENABLE								// The RTC (and wtachdog) is calibrated
#define ITSDK_RTC_CLKFREQ			32768									// RTC clock source frequency
#define ITSDK_CLK_BEST_SOURCE		__CLK_BEST_SRC_RTC						// The RTC is the most accurate clk source to ADJUST Others
#define ITSDK_CLK_CORRECTION		1000									// correct clock with 1200 o/oo (+20%) of the ticks (used when clk_adjust = 0 or for RTC when CLK_BEST_SRC_RTC)
#define ITSDK_WITH_ADC				__ADC_ENABLED							// Use of Adc (includes the structures)
#define ITSDK_ADC_OPTIMIZE_SIZE		__ENABLE								// When __ENABLE adc code is optimized for code size (when relevant)
#define ITSDK_ADC1_PIN				65										// Map the channel for ADC on PIN 14 (PA0)
#define ITSDK_ADC_OVERSAMPLING		16										// Number of ADC read time before averaging
#define ITSDK_VDD_MV				3300									// VDD value in mV
#define ITSDK_VBAT_MIN				2000									// MIN value for VBAT in mv
#define ITSDK_VBAT_MAX				3300									// MAX value for VBAT in mv
#define ITSDK_VBAT_ADC_PIN			-1										// ADC pin used to measure VBAT (if -1 assume VBAT = VCC)
#define ITSDK_WITH_SPI				__SPI_ENABLED							// Use SPI (inludes the strutures)
#define ITSDK_SPI_HANDLER_TYPE		SPI_HandleTypeDef						// The name of the Spi structure to be used for the targeted MCU
#define ITSDK_SPI_TIMEOUT			100										// SPI transaction timeout in ms
#define ITSDK_WITH_I2C				__I2C_ENABLED								// I2C is enabled (__I2C_NONE / __I2C_ENABLED )
#define ITSDK_I2C_HANDLER_TYPE		I2C_HandleTypeDef						//    The name of the I2C structure to be used for the targeted MCU
#define ITSDK_I2C_TIMEOUT			100										//    I2C transaction timeout in ms
#define ITSDK_WITH_HW_TIMER			__TIMER_ENABLED							// Use Hardware Timer
#define ITSDK_HW_TIMER1_HANDLE		htim21									// Timer handler to be used as primary timer
#define ITSDK_HW_TIMER1_ID			21										// Timer hadware 1 - id/name
#define ITSDK_HW_TIMER1_FREQ		32000000								// Primary timer base frequency
#define ITSDK_HW_TIMER1_MAX			2024									// Timer's counter max value ( 2^size )
#define ITSDK_TIMER_SLOTS			5										// Maximum number of SOFT TIMER available in parallel - 0 disable SOFT TIMER code
#define ITSDK_WITH_WDG				__WDG_NONE								// Allows to disable the watchdog
#define ITSDK_WDG_MS				0									// WatchDog time out in ms 1 --> 28000 / 0 to disable
#define ITSDK_WDG_CLKFREQ			37000									// Watchdog clock source frequency
#define ITSDK_CORE_CLKFREQ			32000000								// Core Frequency of the chip
#define ITSDK_WITH_EXPERIMENTAL 	__DISABLE								// activate or deactivate some experimental code by default set it to DISABLE
#define ITSDK_WITH_GPIO_HANDLER		__ENABLE								// Enable the internal GPIO Handler, when disable you need to map it manually

#define ITSDK_LOGGER_CONF			0x00F0									// error->info level on serial1 => USART2 (see logger.c)
#define ITSDK_LOGGER_WITH_SEG_RTT 	__DISABLE								// activate or deactive the segger RTT console (see segger.md file)
#define ITSDK_LOGGER_MODULE			( \
									  __LOG_MOD_NONE		  \
								/*	| __LOG_MOD_LOWPOWER   */ \
								/*	| __LOG_MOD_STATEMINF  */ \
								/*	| __LOG_MOD_STATEMDBG  */ \
								/*	| __LOG_MOD_LOWSIGFOX  */ \
								/*	| __LOG_MOD_STKSIGFOX  */ \
								/*	| __LOG_MOD_STKLORA    */ \
								/*	| __LOG_MOD_STIMER     */ \
								/*	| __LOG_MOD_LOWLORADBG */ \
								/*	| __LOG_MOD_LOWLORAINF */ \
								/*	| __LOG_MOD_GNSS       */ \
								/*	| __LOG_MOD_ACCEL	   */ \
									)										// list the module to be activated in log see config_defines.h

#define ITSDK_WITH_ERROR_RPT		__ENABLE								// Enable the Error reporting code. The allow to store error code in the EEPROM
#define ITSDK_WITH_ERROR_EXTENTION	__ENABLE								//  Add an application extension for error code in configError.h file
#define ITSDK_ERROR_USE_EPROM		__ENABLE								//  Error reports are stored in the EEPROM
#define ITSDK_ERROR_BLOCKS			64										//  Max number of error block / 1 block stores 1 error and needs 8 Byte for storage.
																			//  The first block is header

#define ITSDK_LOWPOWER_MOD			( __LOWPWR_MODE_STOP           \
									| __LOWPWR_MODE_WAKE_RTC       \
									| __LOWPWR_MODE_WAKE_GPIO      \
								/*	| __LOWPWR_MODE_WAKE_LPUART */ \
								/*	| __LOWPWR_MODE_WAKE_UART1  */ \
									| __LOWPWR_MODE_WAKE_UART2  \
									)										// Mode Stop + wakeup RTC + GPIO
		                                                                    // UARTS WAKE Requires clk HSE/LSE and WakeInt Activated
#define ITSDK_LOWPOWER_MINDUR_MS	5										// Under 5 ms sleep request, no need to sleep
#define ITSDK_LOWPOWER_RTC_MS		500										// RTC wake up after 500ms
#define ITSDK_LOWPOWER_MISC_HALT    (  __LP_HALT_NONE					\
								/*	 | __LP_HALT_I2C1	*/				\
								/*	 | __LP_HALT_I2C2	*/				\
									 | __LP_HALT_SPI1					\
								/*	 | __LP_HALT_SPI2	*/				\
									 | __LP_HALT_TIM21 					\
									 | __LP_HALT_ADC1 					\
									)										// extra module to stop during low power phase

#define ITSDK_LOWPOWER_GPIO_A_KEEP	(  __LP_GPIO_NONE  \
								    /*   | __LP_GPIO_0 */  /* Not Used */ \
								    /*   | __LP_GPIO_1 */  /* LoRa RF Sw */ \
										 | __LP_GPIO_2 	   /* Uart2 */ 	\
										 | __LP_GPIO_3     /* Uart2 */ 	\
									/*	 | __LP_GPIO_4 */  /* not used */	\
									/*	 | __LP_GPIO_5 */  /* Led2 / DIO4 */	\
									/*	 | __LP_GPIO_6 */  /* spi1 */		\
									/*	 | __LP_GPIO_7 */  /* spi1 */		\
									/*	 | __LP_GPIO_8 */  /* not used */	\
									/*	 | __LP_GPIO_9 */  /* not used */	\
									/*	 | __LP_GPIO_10 */ /* Uart1 Rx */	\
									/*	 | __LP_GPIO_11 */ /* not used */	\
									/*	 | __LP_GPIO_12 */ /* LoRa Tcxo */	\
									/*	 | __LP_GPIO_13 */ /* lpuart NA */	\
									/*	 | __LP_GPIO_14	*/ /* lpuart NA */	\
									/*	 | __LP_GPIO_15	*/ /* LoRa Nss */	\
		                            )										// Keep activ
#define ITSDK_LOWPOWER_GPIO_B_KEEP	(  __LP_GPIO_NONE \
									/*   | __LP_GPIO_0 */   /* LoRa Dio2 */ 	\
									/*   | __LP_GPIO_1 */ 	/* LoRa Dio1 */ 	\
									/*	 | __LP_GPIO_2 */	/* User button */  	\
									/*	 | __LP_GPIO_3 */   /* spi1 */ 			\
									/*	 | __LP_GPIO_4 */	/* LoRa Dio0 */ 	\
										 | __LP_GPIO_5 		/* Led 1 */ 		\
									/*	 | __LP_GPIO_6 */	/* Led 3 / Uart1 Tx */ 		\
										 | __LP_GPIO_7 		/* Led 4 */ 		\
									/*	 | __LP_GPIO_8 */	/* i2c NA */		\
									/*	 | __LP_GPIO_9 */	/* i2c NA */ 		\
									/*	 | __LP_GPIO_10 */	/* Not Used */ 		\
									/*	 | __LP_GPIO_11 */	/* Not Used */ 		\
										 | __LP_GPIO_12 	/* spi2 NA */		\
									/*	 | __LP_GPIO_13*/	/* spi2 NA */		\
									/*	 | __LP_GPIO_14*/	/* spi2 NA */		\
									/*	 | __LP_GPIO_15*/	/* spi2 */			\
									)										// Keep activ
#define ITSDK_LOWPOWER_GPIO_C_KEEP	(     __LP_GPIO_NONE \
										| __LP_GPIO_0 	/* LoRa Reset */	\
										| __LP_GPIO_1 	/* LoRa TxBoost*/	\
										| __LP_GPIO_2 	/* LoRa Radiosw*/	\
								  /*    | __LP_GPIO_13 */ /* LoRa Dio3*/	\
								  /*	| __LP_GPIO_14 */ /* nc */			\
								  /*	| __LP_GPIO_15 */ /* nc */			\
									)										// keep radio
#define ITSDK_LOWPOWER_GPIO_D_KEEP	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank D are all off (not implemented yet)
#define ITSDK_LOWPOWER_GPIO_E_KEEP	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank E are all off (not implemented yet)
#define ITSDK_LOWPOWER_GPIO_H_KEEP	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank H are all off (not implemented yet)

																			// GPIO Wake-Up => the pin should also be in the _KEEP list
#define ITSDK_LOWPOWER_GPIO_A_WAKE	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank A can be used for wakeup
																			// SX1276 GPIO 4 & 5
#define ITSDK_LOWPOWER_GPIO_B_WAKE	(__LP_GPIO_NONE)
																			// During Low Power mode, the GPIO bank B can be used for wakeup
																			// SX1276 GPIO 0 & 1 & 2

#define ITSDK_LOWPOWER_GPIO_C_WAKE	(__LP_GPIO_NONE \
									)										// During Low Power mode, the GPIO bank C can be used for wakeup
																			// SX1276 GPIO 3
#define ITSDK_LOWPOWER_GPIO_D_WAKE	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank D can be used for wakeup
#define ITSDK_LOWPOWER_GPIO_E_WAKE	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank E can be used for wakeup
#define ITSDK_LOWPOWER_GPIO_H_WAKE	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank H can be used for wakeup

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SCHEDULER & STATE MACHINE
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define ITSDK_SHEDULER_TASKS		1										// Maximum number of Task (0 will deactivate scheduler code)
#define ITSDK_STATEMACHINE_TASKS	0										// Maximum number of state machine task (0 will deactivate STM code)
#define ITSDK_STATEMACHINE_NAMESZ	8										// Maximum size for task name (-1)
#define ITSDK_STATEMACHINE_STATIC 	__DISABLE								// state machine optimization with definition stored in flaash instead of RAM

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// APP SPECIFIC NVM CONFIG
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define ITSDK_CONFIGURATION_MODE		__CONFIG_EEPROM						// Select the type of configuration used
																			// EEPROM = Store the config in EEPROM
																			// MEMORY = The config is reinit at boottime but store in memory
																			// STATIC = No config use in memory, only static settings

#define ITSDK_WITH_CONFIGURATION_APP	__ENABLE							// The application have a configuration stored in NVM
																			// This is enable the app specific part of NVM config
																			// The file it_sdk/configNvm.h will be included and
																			//  contains the application specific configuration


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECURE STORE & CONSOLE
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define ITSDK_WITH_SECURESTORE		__ENABLE								// Enable EEPROM secured storage
#define ITSDK_SECSTORE_USRBLOCK		0										//  Number of USER BLOCK to allocate (from 0 to 7)
#define ITSDK_SECSTORE_DEFKEY		{   \
									  0xC0,0xA5,0x84,0xEB,0x36,0x4F, \
									  0xF4,0x63,0xBE,0x48,0x5A,0x0C  \
									}										// CHANGE ME
																			// Default dynamic key for the SECSTORE
#define ITSDK_SECSTORE_CONSOLEKEY   "changeme"								// Default console passwd string (max 15 char)

#define ITSDK_WITH_CONSOLE			__ENABLE								// Enable / Disable the Console feature
#define ITSDK_CONSOLE_SERIAL		__UART_USART2							// Serial port to be used for console
#define ITSDK_CONSOLE_LINEBUFFER	40										// Max Size of a line in the console. Dropped after.
#define ITSDK_CONSOLE_EXPIRE_S		300										// After 300 Seconds the console will lock automatically
#define ITSKD_CONSOLE_COPYRIGHT		"(c) 2019 Paul Pinault\r\n"				// CHANGE ME : copyright string

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Communication layer
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define ITSDK_WITH_SIGFOX_LIB		__DISABLE								// Include the sigfox code when 1 disabled when 0
#define ITSDK_SIGFOX_LIB			__SIGFOX_NONE							// Type of Sigfox module

#define ITSDK_WITH_LORAWAN_LIB		__ENABLE								// Include the lorawan code when 1 disabled when 0
#define ITSDK_LORAWAN_LIB			__LORAWAN_SX1276

#define ITSDK_DEFAULT_NETWORK		__ACTIV_NETWORK_LORAWAN					// Default network to activate
#define ITSDK_DEFAULT_REGION		__LPWAN_REGION_EU868				    // default region to activate


#define ITSDK_PROTECT_KEY			0xA7459BC3 	 	/* CHANGE ME */			// A random value used to protect the SIGFOX (and others) KEY in memory (better than nothing)

#define ITSDK_ENCRYPT_AES_SHAREDKEY	( 0xAE632397 ^ ITSDK_PROTECT_KEY )      // CHANGE ME
																			// Shared Key for CTR generation
#define ITSDK_ENCRYPT_AES_INITALNONCE ( 0x25 )								// CHANGE ME
																			// Initial value for Nonce used for AES128-CRT
#define ITSDK_ENCRYPT_SPECKKEY		(   (uint64_t)0xEF583AB7A57834BC  \
									  ^ (  (uint64_t)ITSDK_PROTECT_KEY \
									     | ((uint64_t)ITSDK_PROTECT_KEY << 32)) \
									)										// CHANGE ME
																			// Shared Key for SPECK32/64 Encryption
#define ITSDK_ENCRYPT_AES_MASTERKEYH (   (uint64_t)0x2B7E151628AED2A6  \
									  ^ (  (uint64_t)ITSDK_PROTECT_KEY \
									     | ((uint64_t)ITSDK_PROTECT_KEY << 32)) \
									 )										// CHANGE ME
																			// Static 16B key used as master key (8B HIGH)
																			// for end to end encryption
#define ITSDK_ENCRYPT_AES_MASTERKEYL (   (uint64_t)0xABF7158809CF4F3C  \
									  ^ (  (uint64_t)ITSDK_PROTECT_KEY \
									     | ((uint64_t)ITSDK_PROTECT_KEY << 32)) \
									 )										// CHANGE ME
																		    // Static 16B key used as master key (8B LOW)
																		    // for end to end encryption


#if ITSDK_PLATFORM == __PLATFORM_STM32L0
	#include <stm32l_sdk/config.h>
	#include "stm32l0xx_hal.h"
	//#include "stm32l0xx.h"
#endif

#if ITSDK_WITH_SIGFOX_LIB == __ENABLE
	#include <it_sdk/configSigfox.h>
#endif

#if ITSDK_WITH_LORAWAN_LIB == __ENABLE
	#include <it_sdk/configLoRaWan.h>
#endif

#if ITSDK_WITH_DRIVERS == __ENABLE
   #include <it_sdk/configDrivers.h>
#endif

#if ITSDK_WITH_CONFIGURATION_APP == __ENABLE
	#include <it_sdk/configNvm.h>
#endif


#endif /* IT_SDK_CONFIG_H_ */
