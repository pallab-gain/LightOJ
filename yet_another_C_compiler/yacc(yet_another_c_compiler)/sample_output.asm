		SECTION .data
fmtStr:	db	"%s", 0	; The printf format for newline
fmtInt:	db	"%d", 0	; The printf format for integer
fmtFlo:	db	"%f", 0	; The printf format for floating


_c_lev4:	dd	30 ; integer
_c_lev5:	dd	10 ; integer
_c_lev6:	dd	0 ; integer
_newline:	db "", 0Ah; string

		SECTION .bss
_v_x_lev0:	resd 1 	 ; integer
_v_y_lev1:	resd 1 	 ; integer
_v_yy_lev2:	resd 1 	 ; integer
_v_z_lev3:	resd 1 	 ; integer


		SECTION .text
		global	main
		extern	printf
main:


		mov eax ,[_c_lev4] ; integer
		mov [_v_y_lev1], eax

		mov eax ,[_c_lev4] ; integer
		mov [_v_x_lev0], eax

		mov eax ,[_c_lev5] ; integer
		mov [_v_x_lev0], eax

		mov eax ,[_v_x_lev0] ; variable
		mov [_v_z_lev3], eax

		push dword [_v_x_lev0]
		push dword fmtInt 	;print integer
		call printf
		add esp, 8
		push dword _newline
		push dword fmtStr
		call printf
		add esp, 8

		push dword [_v_y_lev1]
		push dword fmtInt 	;print integer
		call printf
		add esp, 8
		push dword _newline
		push dword fmtStr
		call printf
		add esp, 8

		push dword [_v_z_lev3]
		push dword fmtInt 	;print integer
		call printf
		add esp, 8
		push dword _newline
		push dword fmtStr
		call printf
		add esp, 8


ret
