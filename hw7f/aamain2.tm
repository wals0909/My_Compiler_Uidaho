* C- compiler version 
* Built: 
* Author: 
* File compiled:  aamain2.tm
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION input
  1:     ST  3,-1(1)	Store return address 
  2:     IN  2,2,2	Grab int input 
  3:     LD  3,-1(1)	Load return address 
  4:     LD  1,0(1)	Adjust fp 
  5:    JMP  7,0(3)	Return 
* END FUNCTION input
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION output
  6:     ST  3,-1(1)	Store return address 
  7:     LD  3,-2(1)	Load parameter 
  8:    OUT  3,3,3	Output integer 
  9:     LD  3,-1(1)	Load return address 
 10:     LD  1,0(1)	Adjust fp 
 11:    JMP  7,0(3)	Return 
* END FUNCTION output
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION inputb
 12:     ST  3,-1(1)	Store return address 
 13:    INB  2,2,2	Grab bool input 
 14:     LD  3,-1(1)	Load return address 
 15:     LD  1,0(1)	Adjust fp 
 16:    JMP  7,0(3)	Return 
* END FUNCTION inputb
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outputb
 17:     ST  3,-1(1)	Store return address 
 18:     LD  3,-2(1)	Load parameter 
 19:   OUTB  3,3,3	Output bool 
 20:     LD  3,-1(1)	Load return address 
 21:     LD  1,0(1)	Adjust fp 
 22:    JMP  7,0(3)	Return 
* END FUNCTION outputb
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION inputc
 23:     ST  3,-1(1)	Store return address 
 24:    INC  2,2,2	Grab char input 
 25:     LD  3,-1(1)	Load return address 
 26:     LD  1,0(1)	Adjust fp 
 27:    JMP  7,0(3)	Return 
* END FUNCTION inputc
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outputc
 28:     ST  3,-1(1)	Store return address 
 29:     LD  3,-2(1)	Load parameter 
 30:   OUTC  3,3,3	Output char 
 31:     LD  3,-1(1)	Load return address 
 32:     LD  1,0(1)	Adjust fp 
 33:    JMP  7,0(3)	Return 
* END FUNCTION outputc
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outnl
 34:     ST  3,-1(1)	Store return address 
 35:  OUTNL  3,3,3	Output a newline 
 36:     LD  3,-1(1)	Load return address 
 37:     LD  1,0(1)	Adjust fp 
 38:    JMP  7,0(3)	Return 
* END FUNCTION outnl
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION main
 39:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -2
* CALL EXPRESSION
* CALL output
 40:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -3
* TOFF: -4
 41:    LDC  3,666(6)	Load Integer constant 
 42:     ST  3,-4(1)	Push parameter 1001 
* Param end output
 43:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 44:    LDA  3,1(7)	Return address in ac 
 45:    JMP  7,-40(7)	CALL OUTPUT output
 46:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -2
* CALL EXPRESSION
* CALL outputb
 47:     ST  1,-2(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -3
* TOFF: -4
 48:    LDC  3,1(6)	Load Boolean constant 
 49:     ST  3,-4(1)	Push parameter 1001 
* Param end outputb
 50:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 51:    LDA  3,1(7)	Return address in ac 
 52:    JMP  7,-36(7)	CALL OUTPUT outputb
 53:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -2
* CALL EXPRESSION
* CALL outnl
 54:     ST  1,-2(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 55:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 56:    LDA  3,1(7)	Return address in ac 
 57:    JMP  7,-24(7)	CALL OUTPUT outnl
 58:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -2
* CALL EXPRESSION
* CALL input
 59:     ST  1,-2(1)	3 Store fp in ghost frame for input
* Param end input
 60:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 61:    LDA  3,1(7)	Return address in ac 
 62:    JMP  7,-62(7)	CALL OUTPUT input
 63:    LDA  3,0(2)	Save the result in ac 
* CALL end input
* TOFF: -2
* CALL EXPRESSION
* CALL inputb
 64:     ST  1,-2(1)	3 Store fp in ghost frame for inputb
* Param end inputb
 65:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 66:    LDA  3,1(7)	Return address in ac 
 67:    JMP  7,-56(7)	CALL OUTPUT inputb
 68:    LDA  3,0(2)	Save the result in ac 
* CALL end inputb
* TOFF: -2
* RETURN
 69:     LD  3,-1(1)	Load return address 
 70:     LD  1,0(1)	Adjust fp 
 71:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 72:    LDC  2,0(6)	Set return value to 0 
 73:     LD  3,-1(1)	Load return address 
 74:     LD  1,0(1)	Adjust fp 
 75:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,75(7)	Jump to init [backpatch] 
* INIT
 76:    LDA  1,0(0)	set first frame at end of globals 
 77:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
 78:    LDA  3,1(7)	Return address in ac 
 79:    JMP  7,-41(7)	Jump to main 
 80:   HALT  0,0,0	DONE! 
* END INIT
