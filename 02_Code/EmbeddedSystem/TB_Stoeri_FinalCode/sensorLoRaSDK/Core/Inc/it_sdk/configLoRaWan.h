/* ==========================================================
 * configSigfox.h - SDK Configuration file for Sigfox communication
 * Project : Disk91 SDK
 * ----------------------------------------------------------
 * Created on: 4 nov. 2018
 *     Author: Paul Pinault aka Disk91
 * ----------------------------------------------------------
 * Copyright (C) 2018 Disk91
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
 * S2LP:
 *    In cube MX declare the CSn and SDN pin as output.
 *      CSn is pullup set to High initially
 *      SDN is set to low initially (no shutdown)
 *    Declare SPI. default configuration normally match.
 *
 * ==========================================================
 */

#ifndef IT_SDK_CONFIG_SIGFOX_H_
#define IT_SDK_CONFIG_SIGFOX_H_

#include <it_sdk/config_defines.h>
#if ITSDK_LORAWAN_LIB == __LORAWAN_SX1276
	#include "spi.h"
#endif

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// | SDK SETTING                   | USER SELECTED VALUE                  | SETTING DESCRIPTION                   |
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +------------LORAWAN------------|--------------------------------------|---------------------------------------|
#if ITSDK_WITH_LORAWAN_LIB == __ENABLE

#define ITSDK_LORAWAN_STACK			__LORAWAN_SEMTECH					   // Select the SEMTECH lorawan stack
#define ITSDK_LORAWAN_ACTTYPE		__LORAWAN_ACTIVATION_STATIC			   // Activation type selected at compilation time
#define ITSDK_LORAWAN_ACTIVATION	__LORAWAN_OTAA 						   // Activation OTAA or ABP
#define ITSDK_LORAWAN_NETWORKTYPE   __LORAWAN_NWK_PUBLIC				   // type of network - public / private
#define ITSDK_LORAWAN_DEVEUI_SRC	__LORAWAN_DEVEUI_STATIC				   // Device EUI is static / generated
#define ITSDK_LORAWAN_ADR			__LORAWAN_ADR_OFF					   // Adaptative Data Rate
#define ITSDK_LORAWAN_DEFAULT_DR	__LORAWAN_DR_0						   // Default data rate (SF12 125KHz)
#define ITSDK_LORAWAN_CNF_RETRY		3									   // Number of retry when Confirm mode is applied
#ifndef ITSDK_MURATA_TCXO_WARMUP
#define ITSDK_MURATA_TCXO_WARMUP	50									   // Warmup time for TCXO
#define ITSDK_MURATA_WAKEUP_TIME    53 									   // WakeUp time correction for RX window start at least TCXO Time [ms]
#endif
#define ITSDK_LORAWAN_MAX_RX_ERROR	0									   // Extends the RX windows with +/- MS
																		   // This is for unprecised clocks (0=default value)
#define ITSDK_LORAWAN_MAX_DWNLNKSZ	32									   // Max downlink Size in Byte for reception buffer

																		   // =============================
																		   // FREQUENCY MAPPING
																		   // =============================
#define ITSDK_LORAWAN_REGION_ALLOWED (								\
										__LORAWAN_REGION_EU868	|	\
										__LORAWAN_REGION_AS923	|	\
										__LORAWAN_REGION_AU915	|	\
										__LORAWAN_REGION_CN470	|	\
										__LORAWAN_REGION_CN779	|	\
										__LORAWAN_REGION_EU433	|	\
										__LORAWAN_REGION_KR920	|	\
										__LORAWAN_REGION_IN865	|	\
										__LORAWAN_REGION_US915	|	\
										__LORAWAN_REGION_RU864	|	\
										__LORAWAN_REGION_NONE		\
									 )										// List of zone to be available as part
																			// of the code compilation. Size optimization

																		   // =============================
																		   // OTAA
																		   // =============================

#define ITSDK_LORAWAN_DEVEUI		{ 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x05, 0xFB, 0xD3 }
																		   // Static DEVEUI (big endian)
																		   // Bytes are in the same order as
																		   // in a String.

#define ITSDK_LORAWAN_APPEUI		{ 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
																			// Static APPEUI (big endian)
																			// Bytes are in the same order as
																			// in a String.

#define ITSDK_LORAWAN_APPKEY		{ 0x43, 0x21, 0x1E, 0x68, 0x9B, 0x42, 0xAF, 0x0D, 0xE3, 0x03, 0xCF, 0x8E, 0x73, 0x2A, 0xD6, 0x39 }
																			// Static APPKEY (byte[])
																			// Bytes are in the same order compared
																			// as in a String.


#define ITSDK_LORAWAN_NWKKEY		{ 0x43, 0x21, 0x1E, 0x68, 0x9B, 0x42, 0xAF, 0x0D, 0xE3, 0x03, 0xCF, 0x8E, 0x73, 0x2A, 0xD6, 0x39 }
																			// Static NETWORK KEY (byte[])
																			// Bytes are in the same order compared
																			// as in a String.
																			// Same as APPKEY for OTAA

																			// =============================
																			// ABP
																			// =============================
#define ITSDK_LORAWAN_FNWKSKEY		{ 0xDA, 0x1A, 0x21, 0xF0, 0x36, 0xF9, 0x00, 0x59, 0xDB, 0x2D, 0xB6, 0x6E, 0x4E, 0x50, 0xB3, 0x2B }
// Static FORWARDING NETWORK sKEY (byte[])
																		   // Bytes are in the same order compared
																		   // as in a String.

#define ITSDK_LORAWAN_SNWKSKEY		{ 0xDA, 0x1A, 0x21, 0xF0, 0x36, 0xF9, 0x00, 0x59, 0xDB, 0x2D, 0xB6, 0x6E, 0x4E, 0x50, 0xB3, 0x2B }
// Static SERVING NETWORK sKEY (byte[])
																		   // Bytes are in the same order compared
																		   // as in a String.

#define ITSDK_LORAWAN_NWKSKEY		{ 0xDA, 0x1A, 0x21, 0xF0, 0x36, 0xF9, 0x00, 0x59, 0xDB, 0x2D, 0xB6, 0x6E, 0x4E, 0x50, 0xB3, 0x2B }
// Static NETWORK SESSION ENCRYPT KEY (byte[])
																		   // Bytes are in the same order compared
																		   // as in a String.
#define ITSDK_LORAWAN_APPSKEY		{ 0xA2, 0x65, 0x9F, 0x26, 0xD4, 0x5A, 0x61, 0x4D, 0x32, 0xF0, 0xF8, 0xFF, 0x3E, 0xE8, 0xEA, 0x65 }
																			// Static APPLICATION SESSION ENCRYPT KEY (byte[])
																			// Bytes are in the same order compared
																			// as in a String.

#define ITSDK_LORAWAN_NETWORKID		( uint32_t )0x00000000				   // 32b Network ID
#define ITSDK_LORAWAN_DEVADDR		( uint32_t )0x00000000				   // 32b Session Device address

																		   // =============================
																		   // CHANNEL STATIC CONFIG
																		   // =============================

#define ITSDK_LORAWAN_CHANNEL {										\
								5,		/*num of channel*/			\
								{									\
									{	3, 867100000, 867100000, __LORAWAN_DR_0, __LORAWAN_DR_5, 0 }, \
									{	4, 867300000, 867300000, __LORAWAN_DR_0, __LORAWAN_DR_5, 0 }, \
									{	5, 867500000, 867500000, __LORAWAN_DR_0, __LORAWAN_DR_5, 0 }, \
									{	6, 867700000, 867700000, __LORAWAN_DR_0, __LORAWAN_DR_5, 0 }, \
									{	7, 867900000, 867900000, __LORAWAN_DR_0, __LORAWAN_DR_5, 0 }  \
								}									\
							  }												// TTN EU Configuration

#define UNDEF__ITSDK_LORAWAN_CHANNEL {										\
								8,		/*num of channel*/			\
								{									\
									{	0, 903900000, 903900000, __LORAWAN_DR_0, __LORAWAN_DR_3, 0 }, \
									{	1, 904100000, 904100000, __LORAWAN_DR_0, __LORAWAN_DR_3, 0 }, \
									{	2, 904300000, 904300000, __LORAWAN_DR_0, __LORAWAN_DR_3, 0 }, \
									{	3, 904500000, 904500000, __LORAWAN_DR_0, __LORAWAN_DR_3, 0 }, \
									{	4, 904700000, 904700000, __LORAWAN_DR_0, __LORAWAN_DR_3, 0 }, \
									{	5, 904900000, 904900000, __LORAWAN_DR_0, __LORAWAN_DR_3, 0 }, \
									{	6, 905100000, 905100000, __LORAWAN_DR_0, __LORAWAN_DR_3, 0 }, \
									{	7, 905300000, 905300000, __LORAWAN_DR_0, __LORAWAN_DR_3, 0 }  \
								}									\
							  }												// TTN US915 Configuration


																		   // =============================
																		   // ITSDK E2E ENCRYPTION STATIC CONFIG
																		   // =============================

#define ITSDK_LORAWAN_ENCRYPTION		(  __PAYLOAD_ENCRYPT_NONE /*|*/  \
										  /*  __PAYLOAD_ENCRYPT_AESCTR */\
									      /* | __PAYLOAD_ENCRYPT_SPECK  */\
									    )									// Encryption code activated

#endif
// +-------------SX1276------------|--------------------------------------|---------------------------------------|
#if ITSDK_LORAWAN_LIB == __LORAWAN_SX1276
#ifndef ITSDK_SX1276_SPI												   // if not yet defined in configSigfox
#define ITSDK_SX1276_SPI			hspi1								   // SPI To BE USED
																		   // SPI Configured by CubeMX
																		   //  Master, 8b, Polarity Low,
																		   //  first bit msb, CRC disable...

#define ITSDK_SX1276_RESET_BANK		 __BANK_C							   // SX1276 GPIO FOR RESET
#define ITSDK_SX1276_RESET_PIN		 __LP_GPIO_0
#define ITSDK_SX1276_NSS_BANK		 __BANK_A							   // SX1276 GPIO FOR Activating Low Slave Select NSS
#define ITSDK_SX1276_NSS_PIN		 __LP_GPIO_15
#define ITSDK_SX1276_TCXO_VCC_BANK	 __BANK_A							   // SX1276 GPIO FOR Activating TCXO
#define ITSDK_SX1276_TCXO_VCC_PIN	 __LP_GPIO_12
#define ITSDK_SX1276_DIO_0_BANK	 	 __BANK_B							   // SX1276 GPIO 0 => Rx/Tx Done interrupt
#define ITSDK_SX1276_DIO_0_PIN	 	 __LP_GPIO_4
#define ITSDK_SX1276_DIO_1_BANK	 	 __BANK_B							   // SX1276 GPIO 1 => Rx Timeout interrupt
#define ITSDK_SX1276_DIO_1_PIN	 	 __LP_GPIO_1
#define ITSDK_SX1276_DIO_2_BANK	 	 __BANK_B							   // SX1276 GPIO 2 => Fhss Change channel
#define ITSDK_SX1276_DIO_2_PIN	 	 __LP_GPIO_0
#define ITSDK_SX1276_DIO_3_BANK	 	 __BANK_C							   // SX1276 GPIO 3 => cadDone/ValidHeader/Crc Error
#define ITSDK_SX1276_DIO_3_PIN	 	 __LP_GPIO_13
#define ITSDK_SX1276_DIO_4_BANK	 	 __BANK_A							   // SX1276 GPIO 4 => CAD Detected / Pll lock
#define ITSDK_SX1276_DIO_4_PIN	 	 __LP_GPIO_5
#define ITSDK_SX1276_DIO_5_BANK	 	 __BANK_A							   // SX1276 GPIO 5 => Mode Ready / Clk out
#define ITSDK_SX1276_DIO_5_PIN	 	 __LP_GPIO_4
																		   // Corresponding Interrupts needs to
																		   // have an interrupt handler configured.
																		   // EXTI activated for Pins in CubeMW for STM32
																		   // And corrsponding PIN add in the Low level Handler (stm32L...it.c)

// +-------------MURATA------------|--------------------------------------|---------------------------------------|

#define ITSDK_MURATA_ANTSW_RX_BANK 	     __BANK_A						   // MURATE ANTENNA SWITCH RX
#define ITSDK_MURATA_ANTSW_RX_PIN	     __LP_GPIO_1
#define ITSDK_MURATA_ANTSW_TXBOOST_BANK  __BANK_C						   // MURATA TX POWER BOOST
#define ITSDK_MURATA_ANTSW_TXBOOST_PIN	 __LP_GPIO_1
#define ITSDK_MURATA_ANTSW_TXRFO_BANK    __BANK_C						   // MURATA TX RFO
#define ITSDK_MURATA_ANTSW_TXRFO_PIN	 __LP_GPIO_2

#endif

#endif //__LORAWAN_SX1276

// +-------------OTHERS------------|--------------------------------------|---------------------------------------|

// Some config verifications
#if (ITSDK_TIMER_SLOTS < 3) && (ITSDK_LORAWAN_LIB == __LORAWAN_SX1276)
#error "You need 3 Timer or more to support LoRaWan Stack"
#endif


#endif /* IT_SDK_CONFIG_SIGFOX_H_ */

