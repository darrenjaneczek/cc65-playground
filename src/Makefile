SYS = vic20




build:
	cl65 -t $(SYS) snowflake2.c -Cl -l -Or -O -Oi -T -r -o /output/snowflake2.prg
	cc65 -t $(SYS) snowflake2.c -Cl -Or -O -Oi -T -r -o /output/snowflake2.asm
	cl65 -t $(SYS) snowflake.c -Cl -O -r -o /output/snowflake.prg
	cc65 -t $(SYS) snowflake.c -Cl -T -r -O -o /output/snowflake.asm
	cl65 -t c64 prompt2.c -o /output/musicprompt2.prg
	cl65 -t $(SYS) hello.c -o /output/hello-vic20.prg
	cl65 -t $(SYS) petscii.c -o /output/petscii.prg
	cl65 -t $(SYS) printf.c -o /output/printf.prg
	cl65 -t $(SYS) rasterhax.c -o /output/rasterhax.prg
	cl65 -t $(SYS) rasterhax2.c -o /output/rasterhax2.prg
	chmod o+w,o+r /output/*.prg
	ls -la /output/snowflake2.prg