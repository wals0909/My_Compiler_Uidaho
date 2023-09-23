* C- compiler version 
* Built: 
* Author: 
* File compiled:  scope2.tm
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
* FUNCTION ant
 39:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -5
* ASSIGNMENT EXPRESSION
 40:    LDC  3,111(6)	Load Integer constant 
 41:     ST  3,-4(1)	Store variable b
* ASSIGNMENT EXPRESSION
 42:    LDC  3,222(6)	Load Integer constant 
 43:     ST  3,-2(1)	Store variable x
* ASSIGNMENT EXPRESSION
 44:    LDC  3,333(6)	Load Integer constant 
 45:     ST  3,0(0)	Store variable g
* COMPOUND
* TOFF:  -7
* ASSIGNMENT EXPRESSION
 46:    LDC  3,444(6)	Load Integer constant 
 47:     ST  3,-3(1)	Store variable a
* ASSIGNMENT EXPRESSION
 48:    LDC  3,555(6)	Load Integer constant 
 49:     ST  3,-6(1)	Store variable b
* ASSIGNMENT EXPRESSION
 50:    LDC  3,666(6)	Load Integer constant 
 51:     ST  3,-5(1)	Store variable c
* ASSIGNMENT EXPRESSION
 52:    LDC  3,777(6)	Load Integer constant 
 53:     ST  3,0(0)	Store variable g
* ASSIGNMENT EXPRESSION
 54:    LDC  3,888(6)	Load Integer constant 
 55:     ST  3,-2(1)	Store variable x
* CALL EXPRESSION
* CALL output
 56:     ST  1,-7(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -8
* TOFF: -9
 57:     LD  3,-3(1)	2 Load variable 815 a
 58:     ST  3,-9(1)	Push parameter 1001 
* Param end output
 59:    LDA  1,-7(1)	1 Ghost frame becomes new active frame 
 60:    LDA  3,1(7)	Return address in ac 
 61:    JMP  7,-56(7)	CALL OUTPUT output
 62:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -7
* CALL EXPRESSION
* CALL output
 63:     ST  1,-7(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -8
* TOFF: -9
 64:     LD  3,-6(1)	2 Load variable 815 b
 65:     ST  3,-9(1)	Push parameter 1001 
* Param end output
 66:    LDA  1,-7(1)	1 Ghost frame becomes new active frame 
 67:    LDA  3,1(7)	Return address in ac 
 68:    JMP  7,-63(7)	CALL OUTPUT output
 69:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -7
* CALL EXPRESSION
* CALL output
 70:     ST  1,-7(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -8
* TOFF: -9
 71:     LD  3,-5(1)	2 Load variable 815 c
 72:     ST  3,-9(1)	Push parameter 1001 
* Param end output
 73:    LDA  1,-7(1)	1 Ghost frame becomes new active frame 
 74:    LDA  3,1(7)	Return address in ac 
 75:    JMP  7,-70(7)	CALL OUTPUT output
 76:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -7
* CALL EXPRESSION
* CALL output
 77:     ST  1,-7(1)	1 Store fp in ghost frame for output
* Param 1
 78:     LD  3,0(0)	1 variable g
* TOFF: -8
* TOFF: -9
 79:     LD  3,0(0)	1 Load variable 797 g
 80:     ST  3,-9(1)	Push parameter 1001 
* Param end output
 81:    LDA  1,-7(1)	1 Ghost frame becomes new active frame 
 82:    LDA  3,1(7)	Return address in ac 
 83:    JMP  7,-78(7)	CALL OUTPUT output
 84:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -7
* CALL EXPRESSION
* CALL output
 85:     ST  1,-7(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -8
* TOFF: -9
 86:     LD  3,-2(1)	4 Load variable 851 x
 87:     ST  3,-9(1)	Push parameter 1001 
* Param end output
 88:    LDA  1,-7(1)	1 Ghost frame becomes new active frame 
 89:    LDA  3,1(7)	Return address in ac 
 90:    JMP  7,-85(7)	CALL OUTPUT output
 91:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -7
* CALL EXPRESSION
* CALL outnl
 92:     ST  1,-7(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 93:    LDA  1,-7(1)	Ghost frame becomes new active frame 
 94:    LDA  3,1(7)	Return address in ac 
 95:    JMP  7,-62(7)	CALL OUTPUT outnl
 96:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -7
* Compound Body
* TOFF:  -5
* END COMPOUND
* CALL EXPRESSION
* CALL output
 97:     ST  1,-5(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -6
* TOFF: -7
 98:     LD  3,-3(1)	2 Load variable 815 a
 99:     ST  3,-7(1)	Push parameter 1001 
* Param end output
100:    LDA  1,-5(1)	1 Ghost frame becomes new active frame 
101:    LDA  3,1(7)	Return address in ac 
102:    JMP  7,-97(7)	CALL OUTPUT output
103:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -5
* CALL EXPRESSION
* CALL output
104:     ST  1,-5(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -6
* TOFF: -7
105:     LD  3,-4(1)	2 Load variable 815 b
106:     ST  3,-7(1)	Push parameter 1001 
* Param end output
107:    LDA  1,-5(1)	1 Ghost frame becomes new active frame 
108:    LDA  3,1(7)	Return address in ac 
109:    JMP  7,-104(7)	CALL OUTPUT output
110:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -5
* CALL EXPRESSION
* CALL output
111:     ST  1,-5(1)	1 Store fp in ghost frame for output
* Param 1
112:     LD  3,0(0)	1 variable g
* TOFF: -6
* TOFF: -7
113:     LD  3,0(0)	1 Load variable 797 g
114:     ST  3,-7(1)	Push parameter 1001 
* Param end output
115:    LDA  1,-5(1)	1 Ghost frame becomes new active frame 
116:    LDA  3,1(7)	Return address in ac 
117:    JMP  7,-112(7)	CALL OUTPUT output
118:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -5
* CALL EXPRESSION
* CALL output
119:     ST  1,-5(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -6
* TOFF: -7
120:     LD  3,-2(1)	4 Load variable 851 x
121:     ST  3,-7(1)	Push parameter 1001 
* Param end output
122:    LDA  1,-5(1)	1 Ghost frame becomes new active frame 
123:    LDA  3,1(7)	Return address in ac 
124:    JMP  7,-119(7)	CALL OUTPUT output
125:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -5
* CALL EXPRESSION
* CALL outnl
126:     ST  1,-5(1)	3 Store fp in ghost frame for outnl
* Param end outnl
127:    LDA  1,-5(1)	Ghost frame becomes new active frame 
128:    LDA  3,1(7)	Return address in ac 
129:    JMP  7,-96(7)	CALL OUTPUT outnl
130:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -5
* ASSIGNMENT EXPRESSION
131:    LDC  3,11(6)	Load Integer constant 
132:     ST  3,-3(1)	Store variable a
* ASSIGNMENT EXPRESSION
133:    LDC  3,12(6)	Load Integer constant 
134:     ST  3,-4(1)	Store variable b
* ASSIGNMENT EXPRESSION
135:    LDC  3,14(6)	Load Integer constant 
136:     ST  3,-2(1)	Store variable x
* COMPOUND
* TOFF:  -5
* ASSIGNMENT EXPRESSION
137:    LDC  3,15(6)	Load Integer constant 
138:     ST  3,-2(1)	Store variable x
* Compound Body
* TOFF:  -5
* END COMPOUND
* CALL EXPRESSION
* CALL output
139:     ST  1,-5(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -6
* TOFF: -7
140:     LD  3,-3(1)	2 Load variable 815 a
141:     ST  3,-7(1)	Push parameter 1001 
* Param end output
142:    LDA  1,-5(1)	1 Ghost frame becomes new active frame 
143:    LDA  3,1(7)	Return address in ac 
144:    JMP  7,-139(7)	CALL OUTPUT output
145:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -5
* CALL EXPRESSION
* CALL output
146:     ST  1,-5(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -6
* TOFF: -7
147:     LD  3,-4(1)	2 Load variable 815 b
148:     ST  3,-7(1)	Push parameter 1001 
* Param end output
149:    LDA  1,-5(1)	1 Ghost frame becomes new active frame 
150:    LDA  3,1(7)	Return address in ac 
151:    JMP  7,-146(7)	CALL OUTPUT output
152:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -5
* CALL EXPRESSION
* CALL output
153:     ST  1,-5(1)	1 Store fp in ghost frame for output
* Param 1
154:     LD  3,0(0)	1 variable g
* TOFF: -6
* TOFF: -7
155:     LD  3,0(0)	1 Load variable 797 g
156:     ST  3,-7(1)	Push parameter 1001 
* Param end output
157:    LDA  1,-5(1)	1 Ghost frame becomes new active frame 
158:    LDA  3,1(7)	Return address in ac 
159:    JMP  7,-154(7)	CALL OUTPUT output
160:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -5
* CALL EXPRESSION
* CALL output
161:     ST  1,-5(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -6
* TOFF: -7
162:     LD  3,-2(1)	4 Load variable 851 x
163:     ST  3,-7(1)	Push parameter 1001 
* Param end output
164:    LDA  1,-5(1)	1 Ghost frame becomes new active frame 
165:    LDA  3,1(7)	Return address in ac 
166:    JMP  7,-161(7)	CALL OUTPUT output
167:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -5
* CALL EXPRESSION
* CALL outnl
168:     ST  1,-5(1)	3 Store fp in ghost frame for outnl
* Param end outnl
169:    LDA  1,-5(1)	Ghost frame becomes new active frame 
170:    LDA  3,1(7)	Return address in ac 
171:    JMP  7,-138(7)	CALL OUTPUT outnl
172:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -5
* RETURN
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
173:     LD  3,-3(1)	2 Load variable 815 a
174:     ST  3,-5(1)	Push the left side 677 
* TOFF: -6
175:     LD  3,-4(1)	2 Load variable 815 b
* TOFF: -5
176:     LD  4,-5(1)	Load Left into 1 +
177:    ADD  3,4,3	Op + +
178:     ST  3,-5(1)	Push the left side 677 
* TOFF: -6
179:     LD  3,0(0)	1 Load variable 797 g
* TOFF: -5
180:     LD  4,-5(1)	Load Left into 1 +
181:    ADD  3,4,3	Op + +
182:     ST  3,-5(1)	Push the left side 677 
* TOFF: -6
183:     LD  3,-2(1)	4 Load variable 851 x
* TOFF: -5
184:     LD  4,-5(1)	Load Left into 1 +
185:    ADD  3,4,3	Op + +
186:    LDA  2,0(3)	Copy result to ret register 
187:     LD  3,-1(1)	Load return address 
188:     LD  1,0(1)	Adjust fp 
189:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -5
* END COMPOUND
* Add standard closing in case there is no return statement
190:    LDC  2,0(6)	Set return value to 0 
191:     LD  3,-1(1)	Load return address 
192:     LD  1,0(1)	Adjust fp 
193:    JMP  7,0(3)	Return 
* END FUNCTION ant
* TOFF: -2
* FUNCTION main
194:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -3
* ASSIGNMENT EXPRESSION
195:    LDC  3,16(6)	Load Integer constant 
196:     ST  3,-2(1)	Store variable a
* ASSIGNMENT EXPRESSION
197:    LDC  3,1(6)	Load Integer constant 
198:     ST  3,0(0)	Store variable g
* CALL EXPRESSION
* CALL output
199:     ST  1,-3(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* TOFF: -5
* CALL EXPRESSION
* CALL ant
200:     ST  1,-5(1)	1 Store fp in ghost frame for ant
* Param 1
* TOFF: -6
* TOFF: -7
201:    LDC  3,2(6)	Load Integer constant 
202:     ST  3,-7(1)	Push parameter 1001 
* Param end ant
203:    LDA  1,-5(1)	1 Ghost frame becomes new active frame 
204:    LDA  3,1(7)	Return address in ac 
205:    JMP  7,-167(7)	CALL OUTPUT ant
206:    LDA  3,0(2)	Save the result in ac 
* CALL end ant
* TOFF: -5
207:     ST  3,-5(1)	Push parameter 1001 
* Param end output
208:    LDA  1,-3(1)	1 Ghost frame becomes new active frame 
209:    LDA  3,1(7)	Return address in ac 
210:    JMP  7,-205(7)	CALL OUTPUT output
211:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -3
* CALL EXPRESSION
* CALL output
212:     ST  1,-3(1)	1 Store fp in ghost frame for output
* Param 1
213:     LD  3,0(0)	1 variable g
* TOFF: -4
* TOFF: -5
214:     LD  3,0(0)	1 Load variable 797 g
215:     ST  3,-5(1)	Push parameter 1001 
* Param end output
216:    LDA  1,-3(1)	1 Ghost frame becomes new active frame 
217:    LDA  3,1(7)	Return address in ac 
218:    JMP  7,-213(7)	CALL OUTPUT output
219:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -3
* CALL EXPRESSION
* CALL output
220:     ST  1,-3(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* TOFF: -5
221:     LD  3,-2(1)	2 Load variable 815 a
222:     ST  3,-5(1)	Push parameter 1001 
* Param end output
223:    LDA  1,-3(1)	1 Ghost frame becomes new active frame 
224:    LDA  3,1(7)	Return address in ac 
225:    JMP  7,-220(7)	CALL OUTPUT output
226:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -3
* CALL EXPRESSION
* CALL outnl
227:     ST  1,-3(1)	3 Store fp in ghost frame for outnl
* Param end outnl
228:    LDA  1,-3(1)	Ghost frame becomes new active frame 
229:    LDA  3,1(7)	Return address in ac 
230:    JMP  7,-197(7)	CALL OUTPUT outnl
231:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -3
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
232:    LDC  2,0(6)	Set return value to 0 
233:     LD  3,-1(1)	Load return address 
234:     LD  1,0(1)	Adjust fp 
235:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,235(7)	Jump to init [backpatch] 
* INIT
236:    LDA  1,-1(0)	set first frame at end of globals 
237:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
238:    LDA  3,1(7)	Return address in ac 
239:    JMP  7,-46(7)	Jump to main 
240:   HALT  0,0,0	DONE! 
* END INIT
