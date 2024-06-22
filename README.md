How to install a shared library to system:

    1 - Compile it with the following flags: -c -fpic
        Ex.: gcc -c -fpic colors.c -o colors.o
    
    2 - Compile the object file to a lib[name]
        Ex.: gcc -o libcolors.so colors.o 

    3 - Copy the file to /usr/lib/ or /usr/local/lib 
        Ex.: cp ./libcolors.so /usr/lib/ 

    4 - Alter the permissions of said file to read-only 
        Ex.: chmod 0755 /usr/lib/libcolors.so 

    5 - Include the header file in /usr/include/ or /usr/local/include/
        Ex.: cp colors.h /usr/include/

    6 - Update the cache
        Ex.: ldconfig
   
Then, remember to update your C_INCLUDE_PATH and LD_LIBRARY_PATH to include /usr/lib/

Also, remember to use <brick.h> in every single one of your projects
