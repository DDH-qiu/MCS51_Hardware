;-----------------
;Title:ʵ��ʮ�ţ��ⲿ�ж�ʵ��
;Authors:DDH-qiu
;Date:2022-3-22
;Abstract:�ⲿ�ж�ʵ��LED�Ƶ�����
;-----------------
ORG 0000H
	LED BIT P1.0
		LEDBUF BIT 0
			LJMP START
			ORG 0003H
				INTERRUPT:PUSH PSW
				CPL LEDBUF
				MOV C,LEDBUF
				MOV LED,C
				POP PSW
				RETI
				ORG 0030H
					START:CLR LEDBUF
					CLR LED
					MOV TCON,#01H
					MOV IE,#81H
					LJMP $
						END