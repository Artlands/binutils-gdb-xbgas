	.global var
	.section .tdata,"awT",@progbits
var:
	.word 1
	.text
	.global	fn1
	.type	fn1,@function
fn1:

	# Use DESC and IE to access the same symbol,
	# DESC will relax to IE.
<<<<<<< HEAD
	la.tls.desc $a0,var
	la.tls.ie   $a0,var

	# extreme cmodel do not do transition.
	la.tls.desc $a0,$a1,var
	la.tls.ie   $a0,$a1,var
=======
	la.tls.ie $a0,var
	la.tls.desc $a0,var
>>>>>>> upstream/binutils-2_43-branch
