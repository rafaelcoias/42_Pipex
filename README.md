# 42_Pipex

## Assignment

Create a program that works like shell commands. Using pipes and file descriptors.

## Goal

This project will let you discover in detail a UNIX mechanism that you already know by using it in your program.

## What you need to know before starting pipex

### Functions Manual

  - <a href="https://man7.org/linux/man-pages/man2/access.2.html">access()</a>
  - <a href="https://man7.org/linux/man-pages/man2/dup.2.html">dup()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/fork.2.html">fork()</a>
  - <a href="https://man7.org/linux/man-pages/man2/execve.2.html">execve()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/pipe.2.html">pipe</a> 
  - <a href="https://man7.org/linux/man-pages/man2/unlink.2.html">unlink()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/wait.2.html">wait()</a>
  - <a href="https://man7.org/linux/man-pages/man2/waitpid.2.html">waitpid()</a> 

### File Descriptors

Every file we open with the <a href="https://man7.org/linux/man-pages/man2/open.2.html">open()</a> function has a file descriptor.

There are 3 standard file descriptors (fd's) : **STD_INPUT(0)** , **STD_OUTPUT(1)** and **STD_ERROR(2)**.

When we use Pipes the file descriptor changes so the *output* of a command is not displayed. Instead it goes to the next command *input*.

For example :

    cat file > file2
    
If the *file2 fd* is 3, the command above changes *file2 fd*(3) to the **STD_OUT**(1) so the output is not displayed, but goes to *file2*.\n

### Pipes

Pipes are a very common thing when programming in bash. It is important to understand how they work.

The pipe ( **|** ) creates a tunnel between the output of the left command and the input for the right command relativly to the pipe.

Here is an example : 

    cat file | wc -l

The **cat** command would have displayed what is in *file* , but the output goes to the input of the *wc -l* command.

The function **dup2()** is used to change where the output goes. Instead of going to the *STD_OUT*(1) it goes to the other side of the pipe. Dup2() changes the file descriptor of the pipe created to be the *STD_OUT*. Knowing that we also change the input side of the pipe to be the *STD_IN*(0).

![image](https://user-images.githubusercontent.com/91686183/190929267-10c6cb55-7ce0-49be-b2ae-be28abfeb07b.png)

## Preview

<details><summary>My Pipex</summary>
  
  ![Screencast from 19-09-2022 00_02_27](https://user-images.githubusercontent.com/91686183/190931989-878ae3b9-86ee-4c66-ad44-a58749431806.gif)
  
</details>

<details><summary>My grade</summary>
  
  ![image](https://user-images.githubusercontent.com/91686183/169928122-e9d298b3-7720-40ba-b932-07404a8c2e15.png)
  
</details>

<hr>

I hope you found it interesting!

If you are going to do pipex, I wish you good luck and hope that you learned something here!
