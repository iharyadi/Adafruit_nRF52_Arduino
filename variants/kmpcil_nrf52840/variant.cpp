/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  Copyright (c) 2018, Adafruit Industries (adafruit.com)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"
#include "wiring_constants.h"
#include "wiring_digital.h"
#include "nrf.h"
#include "nrf_pwm.h"

const uint32_t g_ADigitalPinMap[] =
{
  // D0 .. D8
/*  _PINNUM(0, 26),   // P0.26 RES NFC
  _PINNUM(0, 27),   // P0.27 
  _PINNUM(1, 1),    // P1.01 SPI2_SCK
  _PINNUM(1, 2),    // P1.02 SPI2_MOSI
  _PINNUM(1, 8),    // P1.08 SPI2_MISO
  _PINNUM(1, 10),   // P1.10 SERIAL_RX
  _PINNUM(1, 11),   // P1.11 SERIAL_TX
  _PINNUM(1, 12),   // P1.12 
  _PINNUM(1, 03),   // P1.03 

  // D9 .. D21
  _PINNUM(0, 6),    // P0.06 SS  NFC
  _PINNUM(0, 8),    // P0.08 INT NFC 
  _PINNUM(1, 14),   // P1.14 
  _PINNUM(1, 13),   // P1.13 INT USB
  _PINNUM(1, 15),   // P1.15 
  _PINNUM(0, 31),   // P0.31 SCK
  _PINNUM(0, 30),   // P0.30 MISO
  _PINNUM(0, 29),   // P0.29 MOSI
  _PINNUM(0, 28),   // P0.28 SS USB
  _PINNUM(0, 4),    // P0.04 
  _PINNUM(0, 3),    // P0.03 
  _PINNUM(0, 11),   // P0.11 
  _PINNUM(0, 18),   // P0.18 

  // D22 .. D24
  _PINNUM(0, 13),   // P0.13 
  _PINNUM(0, 14),   // P0.14 
  _PINNUM(0, 15),   // P0.15 

  // D25 .. D26
  _PINNUM(0, 24),   // P0.24 
  _PINNUM(0, 25),   // P0.25 

  // D27 .. D28
  _PINNUM(0, 9),    // P0.09 
  _PINNUM(0, 10),   // P0.10 

  // D29 .. 36
  _PINNUM(0, 3),   // P0.03 
  _PINNUM(0, 4),   // P0.04 
  _PINNUM(0, 28),  // P0.28 
  _PINNUM(0, 29),  // P0.29 RES_USB
  _PINNUM(0, 30),  // P0.30 
  _PINNUM(0, 31),  // P0.31 
  _PINNUM(0, 5),   // P0.05 
  _PINNUM(0, 2),   // P0.02 

  // D37 .. D38
  _PINNUM(0, 12),  // P0.12
  _PINNUM(1, 9),   // P1.09 
  _PINNUM(0, 7),   // P0.07 
  _PINNUM(0, 17),  // P0.17 
  _PINNUM(0, 20),  // P0.20 
  _PINNUM(0, 22),  // P0.22 */

#ifdef OLD_MAP
    //0..14
    _PINNUM(1,11),  //0  P1.11           *
    _PINNUM(1,10),  //1  P1.10           *
    _PINNUM(0,3),   //2  P0.03    /AIN1  *
    _PINNUM(0,28),  //3  P0.28    /AIN4  *
    _PINNUM(1,13),  //4  INT USB         *
    _PINNUM(0,2),   //5  P0.02    /AIN0  *
    _PINNUM(0,29),  //6  MOSI     /AIN5  *
    _PINNUM(0,31),  //7  SCK      /AIN7  *
    _PINNUM(0,30),  //8  MISO     /AIN6  *
    _PINNUM(0,26),  //9  RES W5500           
    _PINNUM(0,6),   //10 CS  W5500
    _PINNUM(0,8),   //11 INT W5500
    _PINNUM(0,4),   //12 P0.04  AIN2
    _PINNUM(0,5),   //13 P0.05  AIN3
    _PINNUM(1,9),   //14 RES_USB

    //15..28
    _PINNUM(0,10),  //15 NFC_ANTENNA
    _PINNUM(0,9),   //16 NFC_ANTENNA
    _PINNUM(1,6),   //17 P1.06 SERIAL RX  *
    _PINNUM(1,4),   //18 P1.04 SERIAL TX  *
    _PINNUM(1,2),   //19 P1.02 SERIAL CTS *
    _PINNUM(0,24),  //20 P0.24 SERIAL RTS 
    _PINNUM(0,13),  //21 P0.13         
    _PINNUM(1,0),   //22 P1.00            QSPI
    _PINNUM(0,22),  //23 P0.22            QSPI
    _PINNUM(0,20),  //24 P0.20           
    _PINNUM(0,17),  //25 P0.17
    _PINNUM(0,15),  //26 P0.15  SS_USB
    _PINNUM(0,7),   //27 P0.07  SS_NFC
    _PINNUM(0,12),  //28 P0.12  IRQ_NFC

#else 
   //0..14
    _PINNUM(1,11),  //0  P1.11           *
    _PINNUM(1,10),  //1  P1.10           *
    _PINNUM(0,3),   //2  P0.03    /AIN1  *
    _PINNUM(0,28),  //3  P0.28    /AIN4  *
    _PINNUM(1,13),  //4  RES_USB         *
    _PINNUM(0,2),   //5  P0.02    /AIN0  *
    _PINNUM(0,29),  //6  P0.29    /AIN5  *
    _PINNUM(0,31),  //7  P0.31    /AIN7  *
    _PINNUM(0,30),  //8  RES_W5500       *
    _PINNUM(0,26),  //9  MOSI           
    _PINNUM(0,6),   //10 SCK
    _PINNUM(0,8),   //11 MISO
    _PINNUM(0,4),   //12 P0.04    /AIN2
    _PINNUM(0,5),   //13 P0.05    /AIN3
    _PINNUM(1,9),   //14 INT USB

    //15..28
    _PINNUM(0,10),  //15 NFC_ANTENNA
    _PINNUM(0,9),   //16 NFC_ANTENNA
    _PINNUM(1,6),   //17 P1.06
    _PINNUM(1,4),   //18 P1.04 SERIAL CTS  *
    _PINNUM(1,2),   //19 P1.02 SERIAL RTS  *
    _PINNUM(0,24),  //20 P0.24 SERIAL RX
    _PINNUM(0,13),  //21 P0.13 SERIAL TX          
    _PINNUM(1,0),   //22 P1.00       SDA   QSPI
    _PINNUM(0,22),  //23 P0.22       SCL   QSPI
    _PINNUM(0,20),  //24 CS_W5500          
    _PINNUM(0,17),  //25 INT_W5500 
    _PINNUM(0,15),  //26 P0.15  SS_USB
    _PINNUM(0,7),   //27 P0.07  SS_NFC
    _PINNUM(0,12),  //28 P0.12  IRQ_NFC

#endif


    
};

void initVariant()
{
 
}