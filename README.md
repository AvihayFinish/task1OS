# waiters:
> Avihay Finish , 208907113.

> Amit Rovshitz , 207701426.

- [Our Project](#our-project)
    - [Part one](#part-one)
    - [Part two](#part-two)
    - [part three](#part-three)
    
# Our Project:

> This project is divided into three parts. The first part of the project involves the creation of two tools that work with files, The second part of the project will focus on dynamic libraries. <br>
> The final part of the project is a mini shell program.

# Part one:

> **Tool 1:**

>In this part, we will create a tool that compares two files. The tool will take two required arguments, which are the names of the files to be compared. In addition, it will optionally accept two more arguments. <br>
> If the files equal, the tool will print 0, otherwise it will print 1.
> The first optional argument is a flag "-v", which indicates that the user wants to see a string answer indicating whether the files are equal or distinct. If the files are equal, the tool will print "equal", otherwise, it will print "distinct". <br>
> The second optional argument is a flag "-i", which indicates that the comparison should be done in a case-insensitive manner. If this flag is not provided, the tool will perform a case-sensitive comparison by default. <br>

> To run this part, you simply need to execute the command 'git clone https://github.com/AvihayFinish/task1OS.git' in your terminal, and then run the command 'make cmp'. This will build the executable file named 'cmp'. <br>
> To compare two files using the 'cmp' tool, run the command './cmp file1 file2'. Here, 'file1' and 'file2' should be replaced with the names of the files you want to compare. <br>
> You can also add optional flags to customize the comparison behavior. For example, to print a string answer indicating whether the files are equal or distinct, run './cmp file1 file2 -v'. To perform a case-insensitive comparison, run './cmp file1 file2 -v -i'. <br>
> Overall, this tool is easy to use and provides a simple way to compare the contents of two files, with some additional flexibility in terms of comparison options. <br>

**Tool 2:**

> This tool is a file copy utility that can be used to copy the contents of one file to another. The tool takes two required arguments, which are the names of the source file and the destination file, respectively. The tool will print 0 if the copy succssed, otherwise it will print 1. If the second file is exsit then the tool dont overwite him, in this situation the tool will print 1. <br>
>In addition, the tool also accepts two optional flags. The first flag, "-v", causes the tool to print a string answer indicating whether the copy operation was successful or not. For example, if the copy operation was successful, the tool might print the string "success". If the copy operation failed, the tool might print the string "failure". <br>
>The second optional flag, "-f", indicates that the tool should overwrite the destination file if it already exists. If this flag is not provided and the destination file already exists, the tool will fail. <br>
> Overall, this tool provides a convenient way to copy the contents of one file to another, while also offering some flexibility in terms of optional flags that can be used to customize the behavior of the tool. <br>
> To download this tool, you need to run the same commands as the first tool but the last command is "make copy" and not "make cmp", the executable file named "copy". To run this tool, you should run 
"./copy file1 file2" Here, 'file1' is the source file and should be replaced with the name of your file and 'file2' is the destination file that want you create. <br>
> You can also add optional flags to customize the comparison behavior. For example, to print a string answer indicating whether the files are copyed or not, run './copy file1 file2 -v'. To forst overwrite, run './cmp file1 file2 -v -f'. <br>

# Part two:

> This part of the project involves two dynamic libraries, "codecA" and "codecB". Each of these libraries contains two functions that can be used to encode and decode strings. <br>
> In the "codecA" library, the "encode" function takes a string and replaces all lowercase letters with their uppercase counterparts. The "decode" function does the opposite, replacing all uppercase letters with their lowercase counterparts. <br>
> In the "codecB" library, the "encode" function also takes a string, but in addition to changing the case of letters, it adds 3 to the ASCII value of each character. The "decode" function undoes this transformation, subtracting 3 from the ASCII value of each character. <br>
> In addition to the dynamic libraries, there are also two programs that use these libraries at runtime. The first program, "encode", can use the "encode" function from both the codecA and codecB libraries to encode a string. The second program, "decode", can use the "decode" function from both libraries to decode a string. <br>
> Overall, this part of the project demonstrates how dynamic libraries can be used to provide reusable functions that can be easily incorporated into different programs. <br>
> To create this part you should download this project and run the four commands - "make codecA", "make codecB", "make encode" and "make decode". <br>
> I give you few examples how to use the program - <br>
> "./encode codecA aaaBBB", this will run the encode program and use the codecA library of the aaaBBB string, the output will be AAAbbb. <br>
> "./decode codecB eeeddd", this will run the decode program and use the codecB library of the eeeddd string, the output will be bbbaaa. <br>

# Part three:

> The  last program represents a mini shell that allows users to execute commands and supports three specific commands: ">" (redirect output to a file), ">>" (append output to a file), and "|" (pipe output from one command to another). <br>
> The shell can handle up to two pipes at a time, which allows users to chain together multiple commands. For example, a user might enter a command like "ls | grep .txt | wc -l", which would list all files in the current directory with the ".txt" extension, pass the output to grep to filter for lines containing ".txt", and then pass the filtered output to wc to count the number of lines. <br>
> The shell also supports running the dynamic libraries described earlier in this project. Users can execute the "encode" or "decode" programs from the codecA and codecB libraries by entering the appropriate command followed by a string to be encoded or decoded, and the tools copt and cmp that we describe before. <br>
> Finally, the shell ignores the SIGINT signal, which means that pressing Ctrl-C will not kill the shell. Instead, users must use the "exit" command to close the shell and return to the command prompt. <br>
> Overall, this mini shell provides a basic command-line interface that allows users to execute commands and perform a variety of operations, including output redirection, piping, and running dynamic libraries. <br>



