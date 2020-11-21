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
  _PINNUM(0, 26),   // P0.26 (SDA)
  _PINNUM(0, 27),   // P0.27 (SCL)
  _PINNUM(1, 1),    // P1.01 
  _PINNUM(1, 2),    // P1.02 
  _PINNUM(1, 8),    // P1.08 
  _PINNUM(1, 10),   // P1.10 
  _PINNUM(1, 11),   // P1.11 
  _PINNUM(1, 12),   // P1.12 
  _PINNUM(1, 03),   // P1.03 

  // D9 .. D21
  _PINNUM(0, 6),    // P0.06 
  _PINNUM(0, 8),    // P0.08 
  _PINNUM(1, 14),   // P1.14 
  _PINNUM(1, 13),   // P1.13 
  _PINNUM(1, 15),   // P1.15 
  _PINNUM(0, 31),   // P0.31 
  _PINNUM(0, 30),   // P0.30 
  _PINNUM(0, 29),   // P0.29 
  _PINNUM(0, 28),   // P0.28 
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
  _PINNUM(0, 29),  // P0.29 
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
  _PINNUM(0, 22),  // P0.22 
};

void initVariant()
{
 
}