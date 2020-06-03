# RUN: llvm-mc %s -triple=xtensa -mcpu=esp32 -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK,CHECK-INST %s


.align	4
LBL0:

# CHECK-INST: rfde
# CHECK: encoding: [0x00,0x32,0x00]
 rfde

# CHECK-INST: rfe
# CHECK: encoding: [0x00,0x30,0x00]
 rfe
