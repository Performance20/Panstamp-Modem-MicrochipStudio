/*
 * modem.h
 *
 * Copyright (c) 2014 panStamp <contact@panstamp.com>
 * 
 * This file is part of the panStamp project.
 * 
 * panStamp  is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * panStamp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with panStamp; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 
 * USA
 * 
 * Author: Daniel Berenguer
 * Creation date: 10/12/10
 */
 
#ifndef _MODEM_H
#define _MODEM_H

#include "Arduino.h"
#include "panstamp.h"
#include "version.h"

#define SERIAL_SPEED             38400
#define SERIAL_BUF_LEN           128     // Maximum length for any serial string
#define TIMER1_TICK_PERIOD_US    500000  // Timer1 tick = 500 ms
#define MAX_SERIAL_SILENCE_MS    1000    // Maximum serial silence between serial command characters = 1000 ms
#define MAX_SERIAL_SILENCE_TK    MAX_SERIAL_SILENCE_MS / (TIMER1_TICK_PERIOD_US / 1000)  // Max serial silence in ticks

/**
 * AT command set
 */
#define AT_ATTENTION             "AT"        // Basic Attention command
#define AT_RESET                 "ATZ"       // Reset modem
#define AT_GOTO_CMDMODE          "+++"       // Go to command mode
#define AT_GOTO_DATAMODE         "ATO"       // Go to data mode
#define AT_HVERSION              "ATHV"      // Hardware version
#define AT_FVERSION              "ATFV"      // Firmware version
#define AT_FREQCHANNEL           "ATCH"      // Frequency channel
#define AT_SYNCWORD              "ATSW"      // Synchronization word
#define AT_DEVADDRESS            "ATDA"      // Device address
#define AT_ADDRCHECK             "ATAC"      // Address check

/**
 * Serial modes
 */
enum SERMODE
{
  SERMODE_DATA,
  SERMODE_COMMAND  
};

/**
 * Type of AT query
 */
enum ATQUERY
{
  ATQUERY_COMMAND = 0,
  ATQUERY_REQUEST
};

/**
 * Global variables
 */
CCPACKET *rxPacket;
char strSerial[SERIAL_BUF_LEN];          // Serial buffer
byte ch;
int len = 0;
SERMODE serMode = SERMODE_DATA;          // Serial mode (data or command mode)
boolean packetAvailable = false;         // Wireless packet received when true

#endif    // _MODEM_H

