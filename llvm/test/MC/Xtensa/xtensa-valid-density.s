# RUN: llvm-mc %s -triple=xtensa  -mattr=+density -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK,CHECK-INST %s

.align	4
LBL0:

# Instruction format RRRN
# CHECK-INST:  ill.n
# CHECK: encoding: [0x6d,0xf0]
ill.n

# Instruction format RRRN
# CHECK-INST: add.n a3, a9, a4
# CHECK: encoding: [0x4a,0x39]
add.n a3, a9, a4

# Instruction format RRRN
# CHECK-INST: addi.n a8, a1, 12
# CHECK: encoding: [0xcb,0x81]
addi.n a8, a1, 12

# Instruction format RRRN
# CHECK-INST: l32i.n a5, a1, 8
# CHECK: encoding: [0x58,0x21]
l32i.n a5, sp, 8

# Instruction format RRRN
# CHECK-INSt: s32i.n a5, a1, 56
# CHECK: encoding: [0x59,0xe1]
s32i.n a5, sp, 56
