* C- compiler version 
* Built: 
* Author: 
* File compiled:  assign1.tm
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
* TOFF:  -6
* ASSIGNMENT EXPRESSION
 40:    LDC  3,111(6)	Load Integer constant 
 41:     ST  3,-2(1)	Store variable x
* CALL EXPRESSION
* CALL output
 42:     ST  1,-6(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -7
* TOFF: -8
 43:     LD  3,-2(1)	2 Load variable 815 x
 44:     ST  3,-8(1)	Push parameter 1001 
* Param end output
 45:    LDA  1,-6(1)	1 Ghost frame becomes new active frame 
 46:    LDA  3,1(7)	Return address in ac 
 47:    JMP  7,-42(7)	CALL OUTPUT output
 48:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -6
* ASSIGNMENT EXPRESSION
 49:    LDC  3,222(6)	Load Integer constant 
 50:     ST  3,-3(1)	Store variable y
* CALL EXPRESSION
* CALL output
 51:     ST  1,-6(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -7
* TOFF: -8
 52:     LD  3,-3(1)	2 Load variable 815 y
 53:     ST  3,-8(1)	Push parameter 1001 
* Param end output
 54:    LDA  1,-6(1)	1 Ghost frame becomes new active frame 
 55:    LDA  3,1(7)	Return address in ac 
 56:    JMP  7,-51(7)	CALL OUTPUT output
 57:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -6
* ASSIGNMENT EXPRESSION
 58:    LDC  3,1(6)	Load Boolean constant 
 59:     ST  3,-4(1)	Store variable a
* CALL EXPRESSION
* CALL outputb
 60:     ST  1,-6(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -7
* TOFF: -8
 61:     LD  3,-4(1)	2 Load variable 815 a
 62:     ST  3,-8(1)	Push parameter 1001 
* Param end outputb
 63:    LDA  1,-6(1)	1 Ghost frame becomes new active frame 
 64:    LDA  3,1(7)	Return address in ac 
 65:    JMP  7,-49(7)	CALL OUTPUT outputb
 66:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -6
* ASSIGNMENT EXPRESSION
 67:    LDC  3,0(6)	Load Boolean constant 
 68:     ST  3,-5(1)	Store variable b
* CALL EXPRESSION
* CALL outputb
 69:     ST  1,-6(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -7
* TOFF: -8
 70:     LD  3,-5(1)	2 Load variable 815 b
 71:     ST  3,-8(1)	Push parameter 1001 
* Param end outputb
 72:    LDA  1,-6(1)	1 Ghost frame becomes new active frame 
 73:    LDA  3,1(7)	Return address in ac 
 74:    JMP  7,-58(7)	CALL OUTPUT outputb
 75:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -6
* CALL EXPRESSION
* CALL outnl
 76:     ST  1,-6(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 77:    LDA  1,-6(1)	Ghost frame becomes new active frame 
 78:    LDA  3,1(7)	Return address in ac 
 79:    JMP  7,-46(7)	CALL OUTPUT outnl
 80:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -6
* ASSIGNMENT EXPRESSION
 81:    LDC  3,333(6)	Load Integer constant 
 82:     ST  3,0(0)	Store variable gx
* CALL EXPRESSION
* CALL output
 83:     ST  1,-6(1)	1 Store fp in ghost frame for output
* Param 1
 84:     LD  3,0(0)	1 variable gx
* TOFF: -7
* TOFF: -8
 85:     LD  3,0(0)	1 Load variable 797 gx
 86:     ST  3,-8(1)	Push parameter 1001 
* Param end output
 87:    LDA  1,-6(1)	1 Ghost frame becomes new active frame 
 88:    LDA  3,1(7)	Return address in ac 
 89:    JMP  7,-84(7)	CALL OUTPUT output
 90:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -6
* ASSIGNMENT EXPRESSION
 91:    LDC  3,444(6)	Load Integer constant 
 92:     ST  3,-1(0)	Store variable gy
* CALL EXPRESSION
* CALL output
 93:     ST  1,-6(1)	1 Store fp in ghost frame for output
* Param 1
 94:     LD  3,-1(0)	1 variable gy
* TOFF: -7
* TOFF: -8
 95:     LD  3,-1(0)	1 Load variable 797 gy
 96:     ST  3,-8(1)	Push parameter 1001 
* Param end output
 97:    LDA  1,-6(1)	1 Ghost frame becomes new active frame 
 98:    LDA  3,1(7)	Return address in ac 
 99:    JMP  7,-94(7)	CALL OUTPUT output
100:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -6
* ASSIGNMENT EXPRESSION
101:    LDC  3,0(6)	Load Boolean constant 
102:     ST  3,-2(0)	Store variable ga
* CALL EXPRESSION
* CALL outputb
103:     ST  1,-6(1)	1 Store fp in ghost frame for outputb
* Param 1
104:     LD  3,-2(0)	1 variable ga
* TOFF: -7
* TOFF: -8
105:     LD  3,-2(0)	1 Load variable 797 ga
106:     ST  3,-8(1)	Push parameter 1001 
* Param end outputb
107:    LDA  1,-6(1)	1 Ghost frame becomes new active frame 
108:    LDA  3,1(7)	Return address in ac 
109:    JMP  7,-93(7)	CALL OUTPUT outputb
110:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -6
* ASSIGNMENT EXPRESSION
111:    LDC  3,1(6)	Load Boolean constant 
112:     ST  3,-3(0)	Store variable gb
* CALL EXPRESSION
* CALL outputb
113:     ST  1,-6(1)	1 Store fp in ghost frame for outputb
* Param 1
114:     LD  3,-3(0)	1 variable gb
* TOFF: -7
* TOFF: -8
115:     LD  3,-3(0)	1 Load variable 797 gb
116:     ST  3,-8(1)	Push parameter 1001 
* Param end outputb
117:    LDA  1,-6(1)	1 Ghost frame becomes new active frame 
118:    LDA  3,1(7)	Return address in ac 
119:    JMP  7,-103(7)	CALL OUTPUT outputb
120:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -6
* CALL EXPRESSION
* CALL outnl
121:     ST  1,-6(1)	3 Store fp in ghost frame for outnl
* Param end outnl
122:    LDA  1,-6(1)	Ghost frame becomes new active frame 
123:    LDA  3,1(7)	Return address in ac 
124:    JMP  7,-91(7)	CALL OUTPUT outnl
125:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -6
* ASSIGNMENT EXPRESSION
126:     LD  3,-3(1)	2 Load variable 815 y
127:     ST  3,-2(1)	Store variable x
* CALL EXPRESSION
* CALL output
128:     ST  1,-6(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -7
* TOFF: -8
129:     LD  3,-2(1)	2 Load variable 815 x
130:     ST  3,-8(1)	Push parameter 1001 
* Param end output
131:    LDA  1,-6(1)	1 Ghost frame becomes new active frame 
132:    LDA  3,1(7)	Return address in ac 
133:    JMP  7,-128(7)	CALL OUTPUT output
134:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -6
* ASSIGNMENT EXPRESSION
135:     LD  3,-5(1)	2 Load variable 815 b
136:     ST  3,-4(1)	Store variable a
* CALL EXPRESSION
* CALL outputb
137:     ST  1,-6(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -7
* TOFF: -8
138:     LD  3,-4(1)	2 Load variable 815 a
139:     ST  3,-8(1)	Push parameter 1001 
* Param end outputb
140:    LDA  1,-6(1)	1 Ghost frame becomes new active frame 
141:    LDA  3,1(7)	Return address in ac 
142:    JMP  7,-126(7)	CALL OUTPUT outputb
143:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -6
* CALL EXPRESSION
* CALL outnl
144:     ST  1,-6(1)	3 Store fp in ghost frame for outnl
* Param end outnl
145:    LDA  1,-6(1)	Ghost frame becomes new active frame 
146:    LDA  3,1(7)	Return address in ac 
147:    JMP  7,-114(7)	CALL OUTPUT outnl
148:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -6
* ASSIGNMENT EXPRESSION
149:     LD  3,-1(0)	1 Load variable 797 gy
150:     ST  3,0(0)	Store variable gx
* CALL EXPRESSION
* CALL output
151:     ST  1,-6(1)	1 Store fp in ghost frame for output
* Param 1
152:     LD  3,0(0)	1 variable gx
* TOFF: -7
* TOFF: -8
153:     LD  3,0(0)	1 Load variable 797 gx
154:     ST  3,-8(1)	Push parameter 1001 
* Param end output
155:    LDA  1,-6(1)	1 Ghost frame becomes new active frame 
156:    LDA  3,1(7)	Return address in ac 
157:    JMP  7,-152(7)	CALL OUTPUT output
158:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -6
* ASSIGNMENT EXPRESSION
159:     LD  3,-3(0)	1 Load variable 797 gb
160:     ST  3,-2(0)	Store variable ga
* CALL EXPRESSION
* CALL outputb
161:     ST  1,-6(1)	1 Store fp in ghost frame for outputb
* Param 1
162:     LD  3,-2(0)	1 variable ga
* TOFF: -7
* TOFF: -8
163:     LD  3,-2(0)	1 Load variable 797 ga
164:     ST  3,-8(1)	Push parameter 1001 
* Param end outputb
165:    LDA  1,-6(1)	1 Ghost frame becomes new active frame 
166:    LDA  3,1(7)	Return address in ac 
167:    JMP  7,-151(7)	CALL OUTPUT outputb
168:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -6
* CALL EXPRESSION
* CALL outnl
169:     ST  1,-6(1)	3 Store fp in ghost frame for outnl
* Param end outnl
170:    LDA  1,-6(1)	Ghost frame becomes new active frame 
171:    LDA  3,1(7)	Return address in ac 
172:    JMP  7,-139(7)	CALL OUTPUT outnl
173:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -6
* RETURN
174:     LD  3,-1(1)	Load return address 
175:     LD  1,0(1)	Adjust fp 
176:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
177:    LDC  2,0(6)	Set return value to 0 
178:     LD  3,-1(1)	Load return address 
179:     LD  1,0(1)	Adjust fp 
180:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,180(7)	Jump to init [backpatch] 
* INIT
181:    LDA  1,-4(0)	set first frame at end of globals 
182:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
183:    LDA  3,1(7)	Return address in ac 
184:    JMP  7,-146(7)	Jump to main 
185:   HALT  0,0,0	DONE! 
* END INIT
