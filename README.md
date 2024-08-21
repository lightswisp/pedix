
# Portable and Efficient DIssasembler for linuX (PEDIX)
Simple and small x86 instruction decoder

# Current state
- [x]  16-bit instructions
- [x]  32-bit instructions
- [ ]  64-bit instructions
- [ ]  XOP instruction set 
- [ ]  VEX prefixes 
- [ ]  3Dnow!
- [x]  FPU instruction set 

## Run Locally

Clone the project

```bash
  git clone https://github.com/lightswisp/x86_decoder
```

Go to the project directory

```bash
  cd x86_decoder
```


## Building


```bash
  make
```

## Run

```bash
  make run
```


## Running Tests

To run tests, run the following command

```bash
  make test
```

# References:

[https://wiki.osdev.org/X86-64_Instruction_Encoding](https://wiki.osdev.org/X86-64_Instruction_Encoding)

[https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html)

[https://sparksandflames.com/files/x86InstructionChart.html](https://sparksandflames.com/files/x86InstructionChart.html)

[http://www.c-jump.com/CIS77/CPU/x86/lecture.html](http://www.c-jump.com/CIS77/CPU/x86/lecture.html)

[http://ref.x86asm.net/coder32.html](http://ref.x86asm.net/coder32.html)

#### Tools used:

[https://zydis.re/](https://zydis.re/)

[https://defuse.ca/online-x86-assembler.htm](https://defuse.ca/online-x86-assembler.htm)

## License

[MIT](https://choosealicense.com/licenses/mit/)


