/*     Loglan82 Compiler&Interpreter
     Copyright (C) 1993 Institute of Informatics, University of Warsaw
     Copyright (C)  1993, 1994 LITA, Pau
     
     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.
     
     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.
     
             You should have received a copy of the GNU General Public License
             along with this program; if not, write to the Free Software
             Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

 contacts:  Andrzej.Salwicki@univ-pau.fr

or             Andrzej Salwicki
                LITA   Departement d'Informatique
                Universite de Pau
                Avenue de l'Universite
                64000 Pau   FRANCE
		 tel.  ++33 59923154	fax. ++33 59841696

=======================================================================
*/

	NAME	CINTA
	PUBLIC	_logon, _logoff, _attention, _ignore, _send, _receive
	EXTRN	_endrun:FAR, COPYOK:FAR

DGROUP	GROUP	_data

CINTA_TEXT SEGMENT PUBLIC 'CODE'
	ASSUME	CS:DRIVER

; PATCH FOR RECEIVE MESSAGE INTERRUPT HANDLER
PATCH	PROC	FAR
	PUSHF
	PUSH	AX
	PUSH	BX
	PUSH	CX
	PUSH	DX
	PUSH	DS
	PUSH	ES
	CALL	FAR PTR _ignore	; DISABLE ATTENTION
	MOV	AX, DGROUP
	MOV	DS, AX
	ASSUME	CS:DRIVER, DS:DGROUP
	PUSH	AX
	MOV	AX, OFFSET DGROUP:MSGBUF
	PUSH	AX
	CALL	FAR PTR _receive
	CALL	DWORD PTR MSGINT
	ADD	SP, 4
	POP	ES
	POP	DS
	POP	DX
	POP	CX
	POP	BX
	POP	AX
	POPF
	RET
PATCH	ENDP
PATLEN	=	$-PATCH
SAVLEN	=	PATLEN
CINTA_TEXT ENDS

_data	SEGMENT	WORD PUBLIC 'data'
SAVCOD	DB	SAVLEN DUP(?)	; SPACE FOR SAVING PATCHED CODE
USER	DB	8 DUP(?)
MSGBUF	DB	80 DUP(' ')
MSGINT	DD	?
_data	ENDS

; SEGMENT FOR ADDRESSING DRIVER CODE
DRIVER	SEGMENT	AT 0
	ORG	102EH		; ***** ONLY FOR D-LINK VERSION 3.21 *****
DISPLAY	LABEL	FAR		; RECEIVE MESSAGE INTERRUPT HANDLER
	ORG	$+PATLEN
DRIVER	ENDS

CINTA_TEXT SEGMENT 'CODE'
	ASSUME	CS:CINTA_TEXT

NETWORK	DB	0		; NETWORK OPERATION FLAG

BREAK	PROC	FAR		; CONTROL-BREAK INTERRUPT ROUTINE
	MOV	AX, DGROUP
	MOV	DS, AX
	CALL	_endrun
	RET	2
BREAK	ENDP

; int logon(msgint)
; void (*msgint)();
;
; CHECK IF DRIVER IS INSTALLED AND CONNECT TO RECEIVE MESSAGE INTERRUPT HANDLER.
; RETURN NODE NUMBER (-1 MEANS NODE NOT LOGGED ON)

_logon	PROC	FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	AX		; PUSH DUMMY PARAMETER FOR COPYOK
	PUSH	AX
	CALL	COPYOK		; CHECK FOR AUTHORIZATION
	OR	AX, AX
	JZ	NOTAUT		; UNAUTHORIZED DUPLICATE
	MOV	AX, 2523H	; REPLACE CONTROL-BREAK INTERRUPT
	MOV	DX, OFFSET BREAK
	PUSH	CS
	POP	DS
	INT	21H
	MOV	AX, 357DH	; GET NIOS VECTOR INTO ES:BX
	INT	21H
	CMP	WORD PTR ES:[BX-2], 'ns'
	JNE	NONE		; DRIVER NOT INSTALLED
	MOV	AH, 17H		; GET NIOS VERSION NUMBER
	INT	7DH
	CMP	AX, 1503H	; IS VERSION = 3.21
	JNE	NONE		; INCORRECT NIOS VERSION
	PUSH	ES
	POP	DS
	MOV	AX, DGROUP
	MOV	ES, AX
	ASSUME	CS:CINTA_TEXT, DS:DRIVER, ES:DGROUP
	MOV	BX, OFFSET DGROUP:USER
	MOV	AH, 02H		; GET USER NAME
	MOV	DL, 0FFH	; OUR NODE (UNKNOWN YET)
	INT	7DH
	OR	AL, AL
	JNZ	NONE
	MOV	NETWORK, 1	; FLAG NETWORK INSTALLED
	CLD
	MOV	SI, OFFSET DISPLAY
	MOV	DI, OFFSET DGROUP:SAVCOD
	MOV	CX, SAVLEN
	REP	MOVSB
	CALL	FAR PTR _ignore ; DISABLE ATTENTION FOR A MOMENT
	PUSH	DS		; AND REPLACE WITH OUR
	POP	ES
	PUSH	CS
	POP	DS
	ASSUME	CS:CINTA_TEXT, DS:CINTA_TEXT, ES:DRIVER
	MOV	SI, OFFSET PATCH
	MOV	DI, OFFSET DISPLAY
	MOV	CX, PATLEN
	REP	MOVSB
	MOV	AX, DGROUP
	MOV	DS, AX
	ASSUME	CS:CINTA_TEXT, DS:DGROUP, ES:DRIVER
	MOV	AX, [BP+6]	; STORE ADDRESS OF USER INTERRUPT ROUTINE
	MOV	WORD PTR MSGINT, AX
	MOV	AX, [BP+8]
	MOV	WORD PTR MSGINT+2, AX
	MOV	AL, DL		; RETURN OUR NODE NUMBER
	XOR	AH, AH
	JMP	SHORT L1
NONE:	MOV	AX, -1
	MOV	NETWORK, 0
	JMP	SHORT L1
NOTAUT:	MOV	AX, -2
L1:	POP	DS
	POP	DI
	POP	SI
	POP	BP
	RET
_logon	ENDP


; void logoff()
;
; RESTORE ORIGINAL INTERRUPT HANDLER

_logoff	PROC	FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	SI
	PUSH	DI
	PUSH	DS
	ASSUME	CS:CINTA_TEXT
	CMP	NETWORK, 0
	JZ	L2		; NOTHING IF NO NETWORK 
	CALL	FAR PTR _ignore	; DISABLE ATTENTION FOR A MOMENT
	CLD
	MOV	AX,DGROUP
	MOV	DS,AX
	MOV	AX,357DH	; GET DRIVER SEGMENT INTO ES
	INT	21H
	ASSUME	CS:CINTA_TEXT, DS:DGROUP, ES:DRIVER
	MOV	SI,OFFSET DGROUP:SAVCOD
	MOV	DI,OFFSET DISPLAY		
	MOV	CX,SAVLEN
	REP	MOVSB		; RESTORE PATCHED CODE
	CALL	FAR PTR _attention	; ATTENTION BACK ON
L2:	POP	DS
	POP	DI
	POP	SI
	POP	BP
	RET
_logoff	ENDP


; void attention()
;
; ENABLE ATTENTION

_attention	PROC	FAR
	CMP	NETWORK, 0
	JZ	A1
	MOV	AX,1600H
	INT	7DH
A1:	RET
_attention	ENDP


; void ignore()
;
; DISABLE ATTENTION

_ignore PROC	FAR
	CMP	NETWORK, 0
	JZ	I1
	MOV	AX,16FFH
	INT	7DH
I1:	RET
_ignore ENDP


; int send(node, msg)
; int node;
; message *msg;
;
; SEND MESSAGE MSG TO NODE

_send	PROC	FAR
	PUSH	BP
	MOV	BP,SP
	MOV	AH,0DH		; SEND MESSAGE
	MOV	DL,[BP+6]	; NODE NUMBER
	LES	BX,[BP+8]	; BUFFER ADDRESS
	INT	7DH
	XOR	AH,AH
	POP	BP
	RET
_send	ENDP


; int receive(msg)
; message *msg;
;
; GET STORED MESSAGE

_receive PROC	FAR
	PUSH	BP
	MOV	BP,SP
	MOV	AH,0EH		; GET MESSAGE
	LES	BX,[BP+6]	; BUFFER ADDRESS
	INT	7DH
	XOR	AH,AH
	POP	BP
	RET
_receive ENDP


; FUNCTION TICKS:INTEGER4;	
; RETURN BIOS TIME IN TICKS
TICKS	PROC	FAR
	MOV	AH,0
	INT	1AH
	MOV	AX,DX		; LOW WORD
	MOV	DX,CX		; HIGH WORD
	RET
TICKS	ENDP

; PROCEDURE DTIME(VAR H,M,S:INTEGER);
; RETURN DOS DAY TIME IN HOURS, MINUTES, AND SECONDS
DTIME	PROC	FAR
	PUSH	BP
	MOV	BP,SP
	MOV	AH,2CH		; GET TIME
	INT	21H
	MOV	BX,[BP+10]
	MOV	[BX],CH		; HOURS
	MOV	BYTE PTR [BX+1],0
	MOV	BX,[BP+8]
	MOV	[BX],CL		; MINUTES
	MOV	BYTE PTR [BX+1],0
	MOV	BX,[BP+6]
	MOV	[BX],DH		; SECONDS
	MOV	BYTE PTR [BX+1],0
	POP	BP
	RET	6
DTIME	ENDP

; FUNCTION SHIFT(PATTERN, COUNT:INTEGER):INTEGER;
; SHIFT LEFT LOGICALY PATTERN BY COUNT BITS
SHIFT	PROC	FAR
	PUSH	BP
	MOV	BP,SP
	MOV	AX,[BP+8]	; PATTERN
	MOV	CL,[BP+6]	; BIT COUNT
	AND	CL,0FH		; MASK LOW 4 BITS
	TEST	CL,08H		; TEST THEIR SIGN BIT
	JZ	S0		; OK IF POSITIVE
	OR	CL,0F0H		; EXTEND SIGN TO ENTIRE BYTE IF NEGATIVE
S0:	CMP	CL,0		; TEST BIT COUNT ONCE AGAIN
	JZ	S2		; IF = 0 DO NOTHING
	JG	S1		; IF > 0 SHIFT LEFT
	NEG	CL		; IF < 0 NEGATE BIT COUNT AND
	SHR	AX,CL		; SHIFT RIGHT
	JMP	SHORT S2
S1:	SHL	AX,CL		; SHIFT LEFT
S2:	POP	BP
	RET	4
SHIFT	ENDP

CINTA_TEXT ENDS
	END

