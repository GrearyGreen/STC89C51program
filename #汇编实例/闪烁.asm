		  ORG 0000H
	MAIN: CLR P2.0  		;����LED
		  MOV R1,#200		;LED��������ʱһ��ʱ��
	D1:   MOV R2,#150
	D2:	  DJNZ R2,D2
		  DJNZ R1,D1
		  SETB P2.0			;Ϩ��LED��
		  MOV R1,#200		;LED��Ϩ�����ʱһ��ʱ��
	D1_1: MOV R2,#150
	D2_2: DJNZ R2,D2_2		  
		  DJNZ R1,D1_1
		  LJMP MAIN			;���ص�MAIN
	END
