MAI:mov @r3,LENGTH
LOOP:jmp L1
m
prn -5
bne LOOP
m1
L1:inc K
bne LOOP
END:stop
STR:.string "abcdef"
LENGTH:.data 6,-9,15
K:.data 22