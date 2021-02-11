		  ORG 0000H
	MAIN: CLR P2.0  		;点亮LED
		  MOV R1,#200		;LED电亮后延时一段时间
	D1:   MOV R2,#150
	D2:	  DJNZ R2,D2
		  DJNZ R1,D1
		  SETB P2.0			;熄灭LED灯
		  MOV R1,#200		;LED电熄灭后延时一段时间
	D1_1: MOV R2,#150
	D2_2: DJNZ R2,D2_2		  
		  DJNZ R1,D1_1
		  LJMP MAIN			;跳回到MAIN
	END
