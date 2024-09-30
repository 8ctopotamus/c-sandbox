# C Sandbox

## Resources

* [Beej's Guide to C Programming](https://beej.us/guide/bgc/)

* Following Dr. Jonas Birch Youtube tutorials: 
	* [12h of 9 different C projects](https://www.youtube.com/watch?v=9oBWVVFdI38)
	* [Master C programming - SEVEN hour Advanced course](https://www.youtube.com/watch?v=86ILXIWY9f8&t=1077s)

* Learn-c.org
	* [http://learn-c.org/](http://learn-c.org/)

* TutorialsPoint C: 
	* [https://www.tutorialspoint.com/cprogramming/index.htm](https://www.tutorialspoint.com/cprogramming/index.htm)

## Notes

* follow tail of file: `tail -f ./text.txt`
* install ncurses library: `sudo apt-get install libncurses-dev`
* link libraries when compiling: `gcc ncurses.c -o ncurses -lncurses`
* system calls trace: `strace -fp ./<binary>`
* library calls trace: `ltrace -f ./<binary>`
