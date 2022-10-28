# RUN: not llvm-mc  -triple xtensa < %s 2>&1 | FileCheck %s

LBL0:

# Out of range immediates

# imm8
addi a1, a2, 33000
# CHECK:      error: expected immediate in range [-32896, 32639]

# imm8
addi a1, a2, -33000
# CHECK:      error: expected immediate in range [-32896, 32639]

# imm1_16
extui  a1, a2, 5, 17
# CHECK:      error: expected immediate in range [1, 16]

# imm8_sh8
addmi a1, a2, 33
# CHECK:      error: expected immediate in range [-32768, 32512], first 8 bits should be zero

# shimm1_31
slli a1, a2, 0
# CHECK:      error: expected immediate in range [1, 31]

# uimm4
srli a1, a2, 16
# CHECK:      error: expected immediate in range [0, 15]

# uimm5
ssai 32
# CHECK:      error: expected immediate in range [0, 31]

# imm64n_4n
ssai 32
# CHECK:      error: expected immediate in range [0, 31]

# offset8m8
s8i a1, a2, 300
# CHECK:      error: expected immediate in range [0, 255]

# offset16m8
l16si a1, a2, 512
# CHECK:      error: expected immediate in range [0, 510], first bit should be zero

# offset32m8
l32i a1, a2, 1024
# CHECK:      error: expected immediate in range [0, 1020], first 2 bits should be zero

# b4const
beqi a1, 257, LBL0
# CHECK:      error: expected b4const immediate

# b4constu
bgeui a9, 32000, LBL0
# CHECK:      error: expected b4constu immediate

# Invalid number of operands
addi a1, a2 # CHECK: :[[@LINE]]:1: error: too few operands for instruction
addi a1, a2, 4, 4 # CHECK: :[[@LINE]]:17: error: invalid operand for instruction

# Invalid mnemonics
aaa a10, a12 # CHECK: :[[@LINE]]:1: error: unrecognized instruction mnemonic

# Invalid operand types
and sp, a2, 10 # CHECK: :[[@LINE]]:13: error: invalid operand for instruction
addi sp, a1, a2 # CHECK: :[[@LINE]]:14: error: expected immediate in range [-32896, 32639]

# Check invalid register names for different formats
# Instruction format RRR
or r2, sp, a3 # CHECK: :[[@LINE]]:4: error: invalid operand for instruction
and a1, r10, a3 # CHECK: :[[@LINE]]:9: error: invalid operand for instruction
sub a1, sp, a100 # CHECK: :[[@LINE]]:13: error: invalid operand for instruction
# Instruction format RRI8
addi a101, sp, 10 # CHECK: :[[@LINE]]:6: error: invalid operand for instruction
addi a1, r10, 10 # CHECK: :[[@LINE]]:10: error: invalid operand for instruction
# Instruction format RSR
wsr.uregister a2 # CHECK: :[[@LINE]]:1: error: invalid register name
wsr a2, uregister # CHECK: :[[@LINE]]:9: error: invalid operand for instruction
# Instruction format BRI12
beqz b1, LBL0 # CHECK: :[[@LINE]]:6: error: invalid operand for instruction
# Instruction format BRI8
bltui r7, 16, LBL0 # CHECK: :[[@LINE]]:7: error: invalid operand for instruction
# Instruction format CALLX
callx0 r10 # CHECK: :[[@LINE]]:8: error: invalid operand for instruction

# Check invalid operands order for different formats
# Instruction format RRI8
addi a1, 10, a2 # CHECK: :[[@LINE]]:10: error: invalid operand for instruction
# Instruction format RSR
wsr sar, a2 # CHECK: :[[@LINE]]:5: error: invalid operand for instruction
# Instruction format BRI12
beqz LBL0, a2 # CHECK: :[[@LINE]]:6: error: invalid operand for instruction
# Instruction format BRI8
bltui 16, a7, LBL0 # CHECK: :[[@LINE]]:7: error: invalid operand for instruction
bltui a7, LBL0, 16 # CHECK: :[[@LINE]]:20: error: unknown operand

