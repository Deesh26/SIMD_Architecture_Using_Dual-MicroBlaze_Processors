/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include "xparameters.h"
#include "xil_io.h"

#define BRAM_BASE 0xC0000000
#define INPUT_ARRAY_ADDR BRAM_BASE
#define OUTPUT_ARRAY_ADDR (BRAM_BASE + 0x10)
#define OPERATION_ADDR (BRAM_BASE + 0x20)
#define FLAG_START (BRAM_BASE + 0x24)
#define FLAG_DONE (BRAM_BASE + 0x28)
#define DATA_SIZE 4
#define HALF_SIZE (DATA_SIZE / 2)

int main() {
    int inputArray[DATA_SIZE] = {0};
    int outputArray[DATA_SIZE] = {0};
    int operation;

    // Wait for MicroBlaze 1 to signal start
    while (Xil_In32(FLAG_START) != 1);

    // Read the operation and inputArray from shared BRAM
        operation = Xil_In32(OPERATION_ADDR);
        for (int i = 0; i < DATA_SIZE; i++) {
            inputArray[i] = Xil_In32(INPUT_ARRAY_ADDR + (i * sizeof(int)));
        }

        // Process the second half of the array
           for (int i = HALF_SIZE; i < DATA_SIZE; i++) {
               switch (operation) {
                   case 1: outputArray[i] = inputArray[i] + 10; break; // Addition
                   case 2: outputArray[i] = inputArray[i] - 10; break; // Subtraction
                   case 3: outputArray[i] = inputArray[i] + 1; break;  // Increment
                   case 4: outputArray[i] = inputArray[i] - 1; break;  // Decrement
               }
           }

    // Write the results back to shared BRAM
    for (int i = HALF_SIZE; i < DATA_SIZE; i++) {
        Xil_Out32(OUTPUT_ARRAY_ADDR + (i * sizeof(int)), outputArray[i]);
    }

    // Signal MicroBlaze 1 that processing is complete
    Xil_Out32(FLAG_DONE, 1);

    return 0;
}
