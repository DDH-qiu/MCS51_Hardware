;-----------------
;Title:实验七：P1口输入输出实验
;Authors:DDH-qiu
;Date:2022-3-22
;Abstract:实现流水灯的程序
;-----------------
ORG 0000H
	LJMP START
	ORG 0040H
		START:MOV A,#0FEH
		MOV R2,#8
		OUTPUT:MOV P1,A
		RL A
		ACALL DELAY
		DJNZ R2,OUTPUT
		LJMP START
		MOV R6,#0
		DELAY:MOV R7,#0
		DELAYLOOP:DJNZ R7,DELAYLOOP
		DJNZ R6,DELAY
		RET
		END