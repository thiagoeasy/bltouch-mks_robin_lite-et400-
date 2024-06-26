/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * MKS Robin E3 & E3D (STM32F103RCT6) common board pin assignments
 */

#include "env_validate.h"

#define BOARD_WEBSITE_URL "github.com/makerbase-mks"

#define BOARD_NO_NATIVE_USB
#define USES_DIAG_JUMPERS

//#define DISABLE_DEBUG
#define DISABLE_JTAG

//
// Servos
//
#define SERVO0_PIN                          PA3

//
// Limit Switches
//
#define X_STOP_PIN                          PC13
#define Y_STOP_PIN                          PC0
#define Z_MIN_PIN                           PC12

//
// Z Probe
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN                   PB9
#endif

//
// Steppers
//
#define X_STEP_PIN                          PC6
#define X_DIR_PIN                           PB12
#define X_ENABLE_PIN                        PB10

#define Y_STEP_PIN                          PB11
#define Y_DIR_PIN                           PB2
#define Y_ENABLE_PIN                        PB10

#define Z_STEP_PIN                          PB1
#define Z_DIR_PIN                           PC5
#define Z_ENABLE_PIN                        PB10

#define E0_STEP_PIN                         PC4
#define E0_DIR_PIN                          PA5
#define E0_ENABLE_PIN                       PA4


//
// Heaters 0,1 / Fans / Bed
//
#define HEATER_0_PIN                        PC9
#define FAN0_PIN                            PA8
#define HEATER_BED_PIN                      PC8

//
// Temperature Sensors
//
#define TEMP_BED_PIN                        PA1
#define TEMP_0_PIN                          PA0

#define FIL_RUNOUT_PIN                      PB8   // MT_DET

/**                ------
 *   (BEEPER) PD2 | 1  2 | PB3  (ENC)
 *      (EN1) PB5 | 3  4 | PA11 (RESET?)
 *      (EN2) PB4   5  6 | PC1  (LCD_D4)
 *   (LCD_RS) PC3 | 7  8 | PC2  (LCD_EN)
 *            GND | 9 10 | 5V
 *                 ------
 *               "E3" EXP1
 */
#define EXP3_01_PIN                         PD2
#define EXP3_02_PIN                         PB3
#define EXP3_03_PIN                         PB5
#define EXP3_04_PIN                         PA11  // RESET?
#define EXP3_05_PIN                         PB4
#define EXP3_06_PIN                         PC1
#define EXP3_07_PIN                         PC3
#define EXP3_08_PIN                         PC2
#define EXP3_09_PIN                         -1    // GND
#define EXP3_10_PIN                         -1    // 5V

//
// LCD Pins
//
#if HAS_WIRED_LCD
  #define BEEPER_PIN                 EXP3_01_PIN
  #define BTN_ENC                    EXP3_02_PIN
  #define LCD_PINS_RS                EXP3_07_PIN

  #define BTN_EN1                    EXP3_03_PIN
  #define BTN_EN2                    EXP3_05_PIN

  #define LCD_PINS_EN                EXP3_08_PIN

  #if ENABLED(MKS_MINI_12864)

    #define LCD_BACKLIGHT_PIN               -1
    #define LCD_RESET_PIN                   -1
    #define DOGLCD_A0                EXP3_06_PIN
    #define DOGLCD_CS                EXP3_08_PIN
    #define DOGLCD_SCK                      PB13
    #define DOGLCD_MOSI                     PB15

  #else // !MKS_MINI_12864

    #define LCD_PINS_D4              EXP3_06_PIN
    #if IS_ULTIPANEL
      #define LCD_PINS_D5                   -1
      #define LCD_PINS_D6                   -1
      #define LCD_PINS_D7                   -1
    #endif

  #endif // !MKS_MINI_12864

  // Alter timing for graphical display
  #if IS_U8GLIB_ST7920
    #define BOARD_ST7920_DELAY_1             125
    #define BOARD_ST7920_DELAY_2             125
    #define BOARD_ST7920_DELAY_3             125
  #endif

#endif // HAS_WIRED_LCD

// Alter timing for graphical display
#if IS_U8GLIB_ST7920
  #ifndef BOARD_ST7920_DELAY_1
    #define BOARD_ST7920_DELAY_1             125
  #endif
  #ifndef BOARD_ST7920_DELAY_2
    #define BOARD_ST7920_DELAY_2             125
  #endif
  #ifndef BOARD_ST7920_DELAY_3
    #define BOARD_ST7920_DELAY_3             125
  #endif
#endif

// Motor current PWM pins
#define MOTOR_CURRENT_PWM_XY_PIN            PB0
#define MOTOR_CURRENT_PWM_Z_PIN             PA7
#define MOTOR_CURRENT_PWM_E_PIN             PA6
#define MOTOR_CURRENT_PWM_RANGE (65535/10/3.3) // (255 * (1000mA / 65535)) * 257 = 1000 is equal 1.6v Vref in turn equal 1Amp
#define DEFAULT_PWM_MOTOR_CURRENT { 1000, 1000, 1000 } // 1.05Amp per driver, here is XY, Z and E. This values determined empirically.

//

//
// SD Card
//
#define SDCARD_CONNECTION                ONBOARD
#define SPI_DEVICE                             2  // Maple
#define ONBOARD_SPI_DEVICE                     2
#define SDSS                           SD_SS_PIN
#define ONBOARD_SD_CS_PIN              SD_SS_PIN
#define SD_DETECT_PIN                       PC10
#define NO_SD_HOST_DRIVE

// TODO: This is the only way to set SPI for SD on STM32 (for now)
#define ENABLE_SPI2
#define SD_SCK_PIN                          PB13
#define SD_MISO_PIN                         PB14
#define SD_MOSI_PIN                         PB15
#define SD_SS_PIN                           PA15
