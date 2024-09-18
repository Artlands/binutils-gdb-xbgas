	.data
	.section	.tdata,"awT",@progbits
	.fill 0x1000,1,0
var:
	.word 1
	.text
	.global	fn1
	.type	gn1,@function
fn1:
<<<<<<< HEAD:ld/testsuite/ld-loongarch-elf/ie-le.s
	# expect IE to relax LE in nomal cmodel.
	la.tls.ie	$a0,var
	# extreme cmodel do not do transition.
	la.tls.ie	$a0,$a1,var
=======
	# expect IE to relax LE.
	la.tls.ie $a0,var
>>>>>>> upstream/binutils-2_43-branch:ld/testsuite/ld-loongarch-elf/ie-le-norelax.s
