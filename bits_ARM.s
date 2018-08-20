 @ Name: Jiaqi Fan
 @ PID: A12584051
 @ UserID: SoraMitsuki

 @ Name: Xuanru Zhu
 @ PID: A91064234
 @ UserID: Aaron12138
.syntax unified

.text

.align 8
.global bitAnd_ARM
.func bitAnd_ARM, bitAnd_ARM
.type bitAnd_ARM, %function

bitAnd_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
    @ YOUR CODE GOES HERE 
    MVN r4, r0 @ wave x
    MVN r5, r1 @wave y
    ORR r6, r4, r5 @wave x OR wave y
    MVN r7, r6
    @ put your return value in r0 here:
    MOV r0, r7 @ put result in r0
    @ restore caller's registers
    pop {r4-r11, ip, lr}
    @ ARM equivalent of return
    BX lr
.endfunc

.global getByte_ARM
.func getByte_ARM, getByte_ARM
.type getByte_ARM, %function

getByte_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE 
    @-----------------------
    LSL r4, r1, #3 @ n << 3
    LSR r5, r0, r4 @ x >> (n <<3 )
    AND r0, r5, 0xFF @ above & 0xFF
    @ put your return value in r0 here:
    @ restore caller's registers
    pop {r4-r11, ip, lr}
    @ ARM equivalent of return
    BX lr
.endfunc

.global logicalShift_ARM
.func logicalShift_ARM, logicalShift_ARM
.type logicalShift_ARM, %function

logicalShift_ARM:
    push {r4-r11, ip, lr}

    MOV r4, #1 @ assign mask to r4
    LSL r4, r4, #31 @ fishnish mask shift 31
    LSR r5, r4, r1 @ mask >> n
    LSL r5, r5, #1 @ above result shift << 1
    MVN r5, r5  @ ~above result
    LSR r0, r0, r1 @ x >> n
    AND r0, r0, r5 @ final and 

    pop {r4-r11, ip, lr}
    BX lr
.endfunc

.global bitCount_ARM
.func bitCount_ARM
.type bitCount_ARM, %function

bitCount_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
    @ YOUR CODE GOES HERE
    MOV r4, #0x55 @ mask1 0101010..
    LSL r11, r4, #8
    ORR r4, r4, r11
    LSL r11, r4, #16
    ORR r4, r4, r11
    AND r5, r0, r4 @ result(r5) = x & r4
    LSR r6, r0, #1 @ x >> 1 stored in r6
    AND r6, r6, r4 @ x >> 1 and mask
    ADD r5, r5, r6 @ add result to r6
    MOV r6, #0x33 @ now r6 is temp 0x333333
    LSL r11, r6, #8
    ORR r6, r6, r11
    LSL r11, r6, #16
    ORR r6, r6, r11
    MOV r7, #0x3
    LSL r7, r7, #30
    MVN r7, r7 @ now r7 is mask2 ~0x3FFFFFF
    MOV r8, r5 @ temp variable to store r5 result
    AND r8, r8, r6 @ bitwais and temp store in r8
    LSR r5, r5, #2 @shift r5(result) to right 2
    AND r5, r5, r7 @ finished resut>>2 & mask2
    AND r5, r5, r6 @ finished resl >>2 & mask2 & mask
    ADD r5, r5, r8 @ add the two result stored in r5 (result)
    LSR r8, r5, #16 @ make r8 the new temp stored result >> 16
    ADD r5, r5, r8 @ add the result >> 16 to result still in r5
    MOV r8, #0xF @ temp is r8 with 1111000011
    LSL r11, r8, #8
    ORR r8, r8, r11
    MOV r9, r5 @ store result in temp r9
    AND r9, r9, r8 @ now r9 is reult & temp
    LSR r5, r5, #4 @ r5 result shift right 4
    AND r5, r5, r8 @ and a temp r8
    ADD r5, r5, r9 @ combine and add r5 and r9 to get newest result
    MOV r10, r5 @ temp variable for r5
    LSR r10, r10, #8 @ shifh 8
    ADD r5, r5, r10
    AND r5, r5, #0x000000FF
    MOV r0, r5
    @ restore caller's registers
    pop {r4-r11, ip, lr}
    @ ARM equivalent of return
    BX lr 
.endfunc

.global fitsBits_ARM
.func fitsBits_ARM, fitsBits_ARM
.type fitsBits_ARM, %function

fitsBits_ARM:
    push {r4-r11, ip, lr}
    LSR r4, r0, #31 @ make a mask into r4
    MVN r5, r0 @ r5 is ~x
    MVN r6, r4 @ r6 is ~mask
    AND r7, r5, r4 @ ~x & mask
    AND r8, r0, r6 @ x & ~mask
    ADD r7, r7, r8 @ max + min
    ADD r1, r1, #1 @ n + 1
    LSR r7, r7, r1 @ need to bang r7
    LSR r9, r7, #31 @ shift r7 right 31
    MVN r7, r7 @ ~r7
    MOV r11, #0xFF
    LSL r10, r11, #8
    ORR r11, r11, r10
    LSL r10, r11, #16
    ORR r10, r10, r11
    ADD r7, r7, r10 @ ~r7 + 1
    LSR r7, r7, #31 @ right shift r7 by 31
    ORR r9, r9, r7 @ xM OR opM
    MVN r9, r9 @ ~result above
    AND r0, r9, #1 @ above result & 1 put in r0
    pop {r4-r11, ip, lr}
    BX lr
.endfunc

.global negate_ARM
.func negate_ARM, negate_ARM
.type negate_ARM, %function
negate_ARM:
    push {r4-r11, ip, lr}
    MVN r0, r0
    ADD r0, r0, #1
    pop {r4-r11, ip, lr}
    BX lr
.endfunc

.global isLessOrEqual_ARM
.func isLessOrEqual_ARM, isLessOrEqual_ARM
.type isLessOrEqual_ARM, %function
isLessOrEqual_ARM:
    push {r4-r11, ip, lr}
    MVN r1, r1
    ADD r1, r1, #1
    ADD r0, r0, r1 @ this r0 now is diff
    MOV r4, #1
    MVN r4, r4
    ADD r4, r4, #0x01 @ this is (~1 + 1)
    ADD r0, r0, r4
    LSR r0, r0, #31
    AND r0, r0, #1
    pop {r4-r11, ip, lr}
    BX lr
.endfunc

.end

