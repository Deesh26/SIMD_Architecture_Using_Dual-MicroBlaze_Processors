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

#include "xuartlite.h"
#include "xil_printf.h"
#include "xparameters.h"
#include <string.h>
#include "xtmrctr.h"
#include <stdio.h>

#define BRAM_BASE 0xC0000000
#define INPUT_ARRAY_ADDR BRAM_BASE
#define OUTPUT_ARRAY_ADDR (BRAM_BASE + 0x10)
#define OPERATION_ADDR (BRAM_BASE + 0x20)
#define FLAG_START (BRAM_BASE + 0x24)
#define FLAG_DONE (BRAM_BASE + 0x28)
#define DATA_SIZE 4
#define HALF_SIZE (DATA_SIZE / 2)

#define TIMER_DEVICE_ID XPAR_AXI_TIMER_0_DEVICE_ID
#define CLK_HZ XPAR_AXI_TIMER_0_CLOCK_FREQ_HZ


// Operations
#define OP_ADD 1
#define OP_SUB 2
#define OP_INC 3
#define OP_DEC 4

XUartLite UartLite;
XTmrCtr TimerInstance;


int inputArray[DATA_SIZE] = {10, 20, 30, 40};
int outputArray[DATA_SIZE];
int operation = OP_ADD;

int Status;
// Function prototypes
int initialize_uart(XUartLite *UartLitePtr);
int initialize_timer(XTmrCtr *TmrCtrInstancePtr);
void print_message(const char *str);
void write_to_bram(int *data, u32 base, int size);
void read_from_bram(int *data, u32 base, int size);
void print_message(const char *str);

// TIMER FUNCTIONS
void startTimer() {
	XTmrCtr_Reset(&TimerInstance, 0);
	XTmrCtr_Start(&TimerInstance, 0);
}

u32 stopTimer() {
	XTmrCtr_Stop(&TimerInstance, 0);
	return XTmrCtr_GetValue(&TimerInstance, 0);
}


int main() {

	xil_printf("Testing UARTLite...\n");

	    // Initialize UARTLite
	    if (XUartLite_Initialize(&UartLite, XPAR_UARTLITE_0_DEVICE_ID) != XST_SUCCESS) {
	        xil_printf("UARTLite initialization failed.\n");
	        return -1;
	    }
	 xil_printf("UARTLite initialized successfully.\n");

	 /* Timer driver initialization */
	     Status = XTmrCtr_Initialize(&TimerInstance, TIMER_DEVICE_ID);
	     if (Status != XST_SUCCESS) {
	            return XST_FAILURE;
	     }
	     XTmrCtr_SetOptions(&TimerInstance, 0, XTC_AUTO_RELOAD_OPTION);
	     xil_printf("AXI Timer initialized successfully.\n");

	 xil_printf("Select operation:\n1: Addition\n2: Subtraction\n3: Increment by 1\n4: Decrement by 1\n");
	        char recvChar;
	        while (1) {
	            if (XUartLite_Recv(&UartLite, (u8 *)&recvChar, 1) > 0) {
	                operation = recvChar - '0'; // Convert ASCII to integer
	                if (operation >= 1 && operation <= 4) break; // Valid operation
	                xil_printf("Invalid choice. Try again.\n");
	            }
	        }

	 startTimer();

	// Write operation and inputArray to BRAM
	Xil_Out32(OPERATION_ADDR, operation);
    // Write inputArray to shared BRAM
    write_to_bram(inputArray, INPUT_ARRAY_ADDR, DATA_SIZE);



    // Process the first half of the array
    for (int i = 0; i < HALF_SIZE; i++) {
            switch (operation) {
                case OP_ADD: outputArray[i] = inputArray[i] + 10; break;
                case OP_SUB: outputArray[i] = inputArray[i] - 10; break;
                case OP_INC: outputArray[i] = inputArray[i] + 1; break;
                case OP_DEC: outputArray[i] = inputArray[i] - 1; break;
            }
    }

    // Write the first half of the results to BRAM
    write_to_bram(outputArray, OUTPUT_ARRAY_ADDR, HALF_SIZE);

    // Signal MicroBlaze 2 to start processing
    Xil_Out32(FLAG_START, 1);

    xil_printf("Waiting for MicroBlaze 2.\n");
    // Wait for MicroBlaze 2 to finish
    while (Xil_In32(FLAG_DONE) != 1);

    // Read the second half of the results from BRAM
    read_from_bram(outputArray + HALF_SIZE, OUTPUT_ARRAY_ADDR + (HALF_SIZE * sizeof(int)), HALF_SIZE);


    // Display the results
    char buf[100];
    snprintf(buf, sizeof(buf), "Input Array: ");
    print_message(buf);
    for (int i = 0; i < DATA_SIZE; i++) {
        snprintf(buf, sizeof(buf), "%d ", inputArray[i]);
        print_message(buf);
    }
    print_message("\n");

    snprintf(buf, sizeof(buf), "Output Array: ");
    print_message(buf);
    for (int i = 0; i < DATA_SIZE; i++) {
        snprintf(buf, sizeof(buf), "%d ", outputArray[i]);
        print_message(buf);
    }
    print_message("\n");



    // Display processing time
    u32 timeTaken = stopTimer();
    // convert this to milliseconds
    timeTaken = ((double)timeTaken / CLK_HZ) * 1000;
    snprintf(buf, sizeof(buf), "Time Taken: %lu millisecond", timeTaken);
    print_message(buf);
    snprintf(buf, sizeof(buf), "s", timeTaken);
    print_message(buf);

    return 0;
}

void write_to_bram(int *data, u32 base, int size) {
    for (int i = 0; i < size; i++) {
        Xil_Out32(base + (i * sizeof(int)), data[i]);
    }
}

void read_from_bram(int *data, u32 base, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = Xil_In32(base + (i * sizeof(int)));
    }
}

void print_message(const char *str) {
    XUartLite_Send(&UartLite, (u8 *)str, strlen(str));
    while (XUartLite_IsSending(&UartLite));
    return;
}

