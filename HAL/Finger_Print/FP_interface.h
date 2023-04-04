/*
 * FP_interface.h
 *
 *  Created on: Mar 12, 2023
 *      Author: Ahmed Hesham
 */

#ifndef FINGER_PRINT_FP_INTERFACE_H_
#define FINGER_PRINT_FP_INTERFACE_H_

#include "FP_types.h"

extern u8 Recieving_Buffer [30];
extern u8 Recieve_Index;

void FP_Init (void);
FP_Error_t FB_Operation (FP_OperationsID_t OperationID, FP_BufferID_t BufferID, FP_PageID_t PageID);
void FP_New_Scan (FP_PageID_t PageID);
void FP_Check (void);
void FP_Empty_Finger_Lib (void);







extern const u8 Handshake [12];
extern const u8 Collect_IMG_Ins[12];
extern const u8 Generate_Char_File_Buffer1[13];
extern const u8 Generate_Char_File_Buffer2[13];
extern const u8 Generate_Template [12];
extern const u8 Search_Finger_Lib[17];
extern const u8 Empty_Finger_Lib [12];





/*extern const u8 Header_ModelADD_Arr[6];
extern const u8 Verify_Password[16];
extern const u8 Collect_IMG_Ins[12];
extern const u8 Generate_Char_File_Buffer1[7];
extern const u8 Generate_Char_File_Buffer2[7];
extern const u8 Generate_Template [6];
extern const u8 Search_Finger_Lib[11];
extern const u8 Empty_Finger_Lib [6];*/

#endif /* FINGER_PRINT_FP_INTERFACE_H_ */
