Practice: standard file permissions -Abhishek Pradeep


1. As normal user, create a directory ~/permissions. Create a file owned by yourself in there.

Ans: Genesis27@Trainee27:~/Desktop$ mkdir permissions
+ mkdir permissions
Genesis27@Trainee27:~/Desktop/permissions$ touch myfile.txt
+ touch myfile.txt


2. Copy a file owned by root from /etc/ to your permissions dir, who owns this file now ?

Ans: Genesis27@Trainee27:~/Desktop/permissions$ cp /etc/hosts ~/permissions/
+ cp /etc/hosts /home/Genesis27/permissions/
The copy is owned by me.


3. As root, create a file in the users ~/permissions directory.

Ans: touch /home/Genesis27/permissions/rootfile


4. As normal user, look at who owns this file created by root.

Ans: ls -l ~/permissions
Owned by root


5. Change the ownership of all files in ~/permissions to yourself.

Ans: Genesis27@Trainee27:~$ chown Genesis27 ~/permissions/*
You cannot become owner of the file that belongs to root.


6. Make sure you have all rights to these files, and others can only read.

Ans: chmod 644 (on files)
     chmod 755 (on directories)
     

7. With chmod, is 770 the same as rwxrwx--- ?

Ans: Yes


8. With chmod, is 664 the same as r-xr-xr-- ?

Ans: Yes


9. With chmod, is 400 the same as r-------- ?

Ans: Yes


10. With chmod, is 734 the same as rwxr-xr-- ?

Ans: No


11a. Display the umask in octal and in symbolic form.

Ans: Genesis27@Trainee27:~$ umask
+ umask
0002
Genesis27@Trainee27:~$ umask -S
+ umask -S
u=rwx,g=rwx,o=rx


11b. Set the umask to 077, but use the symbolic format to set it. Verify that this works.

Ans: Genesis27@Trainee27:~$ umask -S u=rwx,go=
+ umask -S u=rwx,go=
u=rwx,g=,o=


12. Create a file as root, give only read to others. Can a normal user read this file ? Test writing to this file with nano.

Ans: Genesis27@Trainee27:~/Desktop$ echo hello > /home/Genesis27/Desktop/root.txt
+ echo hello
Genesis27@Trainee27:~/Desktop$ chmod 744 /home/Genesis27/Desktop/root.txt
+ chmod 744 /home/Genesis27/Desktop/root.txt
Genesis27@Trainee27:~/Desktop$ nano root
+ nano root


13a. Create a file as normal user, give only read to others. Can another normal user read this file ? Test writing to this file with vi.

Ans: Genesis27@Trainee27:~/Desktop$ echo hello > file
+ echo hello
Genesis27@Trainee27:~/Desktop$ chmod 744 file
+ chmod 744 file
Yes, others can read this file


13b. Can root read this file ? Can root write to this file with vi ?

Ans: Yes, root can read and write to this file. Because Permissions do not apply to root.


14. Create a directory that belongs to a group, where every member of that group can read and write to files, and create files. Make sure that people can only delete their own files.

Ans: mkdir /home/project42 
     groupadd project42
     chgrp project42 /home/project42 
     chmod 775 /home/project42