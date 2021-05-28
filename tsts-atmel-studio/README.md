# Atmel Studio development environment test
These tests are geared towards using Atmel proprietary hardware tools, STK500, JTAGICE mkII, etc. While some tools can be driven with open software programs (e.g. AVRdude), complete control requires the use of Atmel Studio.

Atmel Studio 7 (today Microchip Studio), is free, closed source, and based on MS Visual Studio.

### Note:
After cloning the repository, and before pushing commits to source, please run these commands in your local sandbox so that Git ignores all custom file changes from your Atmel Studio environment from now on:

```
git update-index --assume-unchanged * .cproj
git update-index --assume-unchanged * .atsuo
```

To revert this setting:

```
git update-index --no-assume-unchanged * .cproj
git update-index --no-assume-unchanged * .atsuo
```
