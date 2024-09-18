#as: -mrelax
#objdump: -Dr -j .eh_frame
#skip: loongarch32-*-*

.*:[    ]+file format .*


<<<<<<< HEAD
Disassembly of section .eh_frame:

[ 	]*0000000000000000 <.eh_frame>:
[ 	]+0:[ 	]+00000014[ 	]+.word[ 	]+[ 	]+0x00000014
[ 	]+4:[ 	]+00000000[ 	]+.word[ 	]+[ 	]+0x00000000
[ 	]+8:[ 	]+00527a01[ 	]+.word[ 	]+[ 	]+0x00527a01
[ 	]+c:[ 	]+01017c01[ 	]+fadd.d[ 	]+\$fa1, \$fa0, \$fs7
[ 	]+10:[ 	]+0c030d1b[ 	]+.word[ 	]+[ 	]+0x0c030d1b
[ 	]+14:[ 	]+00000016[ 	]+.word[ 	]+[ 	]+0x00000016
[ 	]+18:[ 	]+00000034[ 	]+.word[ 	]+[ 	]+0x00000034
[ 	]+1c:[ 	]+0000001c[ 	]+.word[ 	]+[ 	]+0x0000001c
=======
Disassembly of section \.eh_frame:

[ 	]*0000000000000000 <\.eh_frame>:
[ 	]+0:[ 	]+00000014[ 	].*
[ 	]+4:[ 	]+00000000[ 	].*
[ 	]+8:[ 	]+00527a01[ 	].*
[ 	]+c:[ 	]+01017801[ 	].*
[ 	]+10:[ 	]+0c030d1b[ 	].*
[ 	]+14:[ 	]+00000016[ 	].*
[ 	]+18:[ 	]+0000003c[ 	].*
[ 	]+1c:[ 	]+0000001c[ 	].*
>>>>>>> upstream/binutils-2_43-branch
[ 	]+...
[ 	]+20: R_LARCH_32_PCREL[ 	]+L0\^A
[ 	]+24: R_LARCH_ADD32[ 	]+L0\^A
[ 	]+24: R_LARCH_SUB32[ 	]+L0\^A
<<<<<<< HEAD
[ 	]+28:[ 	]+0cd64000[ 	]+.word[ 	]+[ 	]+0x0cd64000
[ 	]+29: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+29: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+2c:[ 	]+d6400016[ 	]+.word[ 	]+[ 	]+0xd6400016
[ 	]+2e: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+2e: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+30:[ 	]+4000160c[ 	]+beqz[ 	]+\$t4, 3145748[ 	]+# 300044 <L0\^A\+0x30000c>
[ 	]+33: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+33: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+34:[ 	]+00160cd6[ 	]+orn[ 	]+\$fp, \$a2, \$sp
[ 	]+38:[ 	]+160cd640[ 	]+lu32i.d[ 	]+\$zero, 26290
[ 	]+38: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+38: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+3c:[ 	]+0cd64000[ 	]+.word[ 	]+[ 	]+0x0cd64000
[ 	]+3d: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+3d: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+40:[ 	]+d6400016[ 	]+.word[ 	]+[ 	]+0xd6400016
[ 	]+42: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+42: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+44:[ 	]+4000160c[ 	]+beqz[ 	]+\$t4, 3145748[ 	]+# 300058 <L0\^A\+0x300020>
[ 	]+47: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+47: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+48:[ 	]+000000d6[ 	]+.word[ 	]+[ 	]+0x000000d6
[ 	]+4c:[ 	]+00000000[ 	]+.word[ 	]+[ 	]+0x00000000
=======
[ 	]+28:[ 	]+0cd64000[ 	].*
[ 	]+29: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+29: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+2c:[ 	]+d6400016[ 	].*
[ 	]+2e: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+2e: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+30:[ 	]+4000160c[ 	].*
[ 	]+33: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+33: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+34:[ 	]+00160cd6[ 	].*
[ 	]+38:[ 	]+160cd640[ 	].*
[ 	]+38: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+38: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+3c:[ 	]+0cd64000[ 	].*
[ 	]+3d: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+3d: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+40:[ 	]+d6400016[ 	].*
[ 	]+42: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+42: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+44:[ 	]+4000160c[ 	].*
[ 	]+47: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+47: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+48:[ 	]+00160cd6[ 	].*
[ 	]+4c:[ 	]+160cd640[ 	].*
[ 	]+4c: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+4c: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+50:[ 	]+0cd64000[ 	].*
[ 	]+51: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+51: R_LARCH_SUB6[ 	]+L0\^A
[ 	]+54:[ 	]+d6400016[ 	].*
[ 	]+56: R_LARCH_ADD6[ 	]+L0\^A
[ 	]+56: R_LARCH_SUB6[ 	]+L0\^A
>>>>>>> upstream/binutils-2_43-branch
