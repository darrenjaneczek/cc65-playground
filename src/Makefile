CL65 := cl65 
OUTPUT := ../output

VIC20_FLAGS = -t vic20 -Cl  -Or -O -Oi -T -r 


build:
	$(CL65) $(VIC20_FLAGS) snowflake2.c -o $(OUTPUT)/snowflake2.prg
	$(CL65) $(VIC20_FLAGS) snowflake.c -o $(OUTPUT)/snowflake.prg
	#$(CL65) -t c64 prompt2.c -o $(OUTPUT)/musicprompt2.prg
	#$(CL65) $(VIC20_FLAGS) hello.c -o $(OUTPUT)/hello-vic20.prg
	$(CL65) $(VIC20_FLAGS) petscii.c -o $(OUTPUT)/petscii.prg
	#$(CL65) $(VIC20_FLAGS) printf.c -o $(OUTPUT)/printf.prg
	$(CL65) $(VIC20_FLAGS) rasterhax.c -o $(OUTPUT)/rasterhax.prg
	$(CL65) $(VIC20_FLAGS) rasterhax2.c -o $(OUTPUT)/rasterhax2.prg
	chmod o+w,o+r $(OUTPUT)/*.prg
	ls -la $(OUTPUT)/snowflake2.prg