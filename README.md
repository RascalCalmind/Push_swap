# push_swap
Push_swap is a project from [Codam](https://www.codam.nl) which requires you to sort a list of integers from the standard input with some constraints on how you are allowed to sort them. And to create a checker program that checks if this output is correct and the list is in fact sorted this way. The purpose of the project is to learn more about sorting algorithms and their characteristics. And the computational complexity of algorithms.

## Compiling
Run ```make```, two executables called ```checker``` and ```push_swap``` should compile directly.

## Challenge
#### For push_swap:
The goal is to sort the list of integers using only 2 stacks: stack a and stack b. 

Beside that restriction you will only be allowed to use these 11 operations:
* ```sa``` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
* ```sb``` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
* ```ss``` : ```sa``` and ```sb``` at the same time.
* ```pa``` : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* ```pb``` : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ```ra``` : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* ```rb``` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* ```rr``` : ```ra``` and ```rb``` at the same time.
* ```rra``` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* ```rrb``` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* ```rrr``` : ```rra``` and ```rrb``` at the same time.

#### For checker:
The goal is to check if the list is sorted or not, allowing the user to give a list of integers as parameter and then asking for operations to perform before evaluating the list.
Checker will give a OK if the list is sorted and a KO if it's not.
You can stop the program by pressing ENTER or CTRL+D.

## Bonus
To see what is actually happening to the stacks I've created a flag to display the stacks after each given operation called ```-v```.
Another flag I've created is ```-f``` allowing you to use a file as input instead of writing down the integers as parameter.
The ```-v``` flag and the ```-f``` can be used for both ```push_swap``` and ```checker```, and in combination with one another as ```-fv``` or ```-vf```.

If the input or the flags are incorrect according to mentioned above, the program will return an error.


## Usage
After creating the executable files, ```checker``` and ```push_swap```, they can be executed by giving them a list of integers as parameter e.g.:

```./push_swap 0 5 1 2 -4```

In this case, the output looks like shown below. 

```
-----------------------------------------------
|	0		|
|	5		|
|	1		|
|	2		|
|	-4		|
|			|
-----------------------------------------------
|  stack a		|  stack b
-----------------------------------------------

pb
rra
pb
sb
rra
rra
pa
pa

Amount of calculations: 8
```

It will visualize what the beginning of the stacks looks like, the steps it will do to sort the list and the amount of calculations/steps used to sort the list.


```./checker 0 3 1```

In this case if we press ENTER or CTRL+D right away, the output looks like shown below. 

```
-----------------------------------------------
|	0		|
|	3		|
|	1		|
|			|
-----------------------------------------------
|  stack a		|  stack b
-----------------------------------------------

KO
```

If we were to use some operations, you will call the program and afterwards type an operation followed by an ENTER to perform said operation.

```
./checker 0 3 1 2
pb
sa
pa
```

This example will give ```KO``` as return.

If you would like to use the ```-f``` flag to use a file as input write the commandline as followed:
```./push_swap -f [FILELOCATION/FILENAME]```

```./checker -f [FILELOCATION/FILENAME]```

If you would like to use the ```-v``` flag to display the stack after each operation write the commandline as followed:

```./push_swap -v [YOUR SET OF INTEGERS]```

```./checker -v [YOUR SET OF INTEGERS]```

You can also use the ```-f``` and ```-v``` flags at the same time writing the commandline as either one of these:

```./push_swap -vf [FILELOCATION/FILENAME]```

```./push_swap -fv [FILELOCATION/FILENAME]```

```./checker -vf [FILELOCATION/FILENAME]```

```./checker -fv [FILELOCATION/FILENAME]```


## Challenge
Allowed functions for the mandatory part are ```exit```, ```write```, ```read```, ```malloc``` and ```free```.
The challenge is to try to get the least amount of operations to sort a list of certain amounts of values. In the end the project was tested on how the algorithm for ```push_swap``` sorts lists of 3, 5, 100 and 500 random integer values and with how many operations. I've learned the difference between different existing sorting algorithms and how to adjust them to the restrictions of the operations we're allowed to use and the use of only two stacks.
