# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 19:15:10 by afenzl            #+#    #+#              #
#    Updated: 2022/08/24 18:56:31 by afenzl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



does not touch outfile if infile invalid
to fix
--> the lexer list is still returning (null)elem first
--> ft_split_new's bahvior needs to be recreated (env expanision, especially with quotes)
--> what do the tokens mean? a lot of them could be just syntax error cause theyre not handled anyways
--> the int pipes is basically already telling where the nodes should be :)

to do
-->appending doesnt work --> DONE
--> figure out why exit code 255 -->DONE
--> the redirout in single builtins
--> signals inside children
--> implement ?$

LAST PUSH

err(char *msg) function does not exit anymore
--> it should show that it failed tho
the free_str function is added again
--> no leaks for now (valgrind :))
the double quotes do expand the variables now
--> (but still a lot of weird behavior)
single quotes == 1, double == 2
added the signals for intercative mode

_______________________________________________________________________________________

the libft has some extra functions for two dimensional arrays:
-> ft_free2: it frees a split
-> ft_print2: it prints the split -debug
-> ft_splitdup: ft_strdups the whole split
-> ft_splitlen: returns the length of the split

and for env 
-> check_existence will check a split and search for a name until '\0' or '='
	to work with env




























TO DO:

-->handle signals 
in ineractive mode
--- before exetcuting a program --> start of while 1 loop
use signal function, it takes another function 'void' and the function just takes an int as parameter

--- in child processes set signals back to default
use SIG_DFL


--> parse and exec








































# include <stdlib.h>
-->malloc,free, exit

# include <unistd.h>
-->write, read, close, fork,, chdir, execve, dup, dup2, pipe, access,
-->getcwd, unlink, isatty, ttyname, ttyslot
	--> int chdir(const char *path);
			the path is the Directory path which the user want
			to make the current working directory.

			Return Value: This command returns zero (0) on success.
			-1 is returned on an error and errno is set appropriately.
	int access(const char *path, int amode);
			the access() system call checks the accessibility of the file named by
			the path argument for the access permissions indicated by the mode argu-
			ment.  The value of mode is either the bitwise-inclusive OR of the access
			permissions to be checked (R_OK for read permission, W_OK for write per-
			mission, and X_OK for execute/search permission), or the existence test
			(F_OK).

	char *getcwd(char *buf, size_t size);
				The getcwd() function copies an absolute pathname of the current
				working directory to the array pointed to by buf, which is of
			length size.

			If the length of the absolute pathname of the current working
			directory, including the terminating null byte, exceeds size
			bytes, NULL is returned, and errno is set to ERANGE; an
			application should check for this error, and allocate a larger
			buffer if necessary.

	int unlink(const char *pathname);
			deletes a name from the file system.
			If that name was the last link to a file and no processes
			have the file open the file is deleted and the space
			it was using is made available for reuse.
			If the name was the last link to a file but any processes
			still have the file open the file will remain in existence
			until the last file descriptor referring to it is closed.

	int isatty(int fd);
			The isatty() function tests whether fd is an open file descriptor
			referring to a terminal.

	char *ttyname(int fd);
		The function ttyname() returns a pointer to the null-terminated
		pathname of the terminal device that is open on the file
		descriptor fd, or NULL on error (for example, if fd is not
		connected to a terminal).  The return value may point to static
		data, possibly overwritten by the next call.

	int ttyslot(void);
			If successful, this function returns the slot number.  On error
		(e.g., if none of the file descriptors 0, 1, or 2 is associated
		with a terminal that occurs in this data base) it returns 0 on
		UNIX V6 and V7 and BSD-like systems, but -1 on System V-like
		systems.

# include <stdio.h>
-->printf, perror
	void perror(const char *str);
			prints a textual description of the error code
			currently stored in the system variable errno to stderr.
		
			the contents of the null-terminated byte string pointed to by s,
			followed by ": " (unless s is a null pointer
			or the character pointed to by s is the null character)
			
			implementation-defined error message string describing
			the error code stored in errno, followed by '\n'.
			The error message string is identical to the result of strerror(errno)

# include <fcntl.h>
-->open,

# include <sys/wait.h>
-->wait, waitpid, wait3, wait4
	--> waitpid(pid_t pid, int *stat_loc, int options);
			>The waitpid() system call suspends execution of the calling
			   thread until a child specified by pid argument has changed state.
			   By default, waitpid() waits only for terminated children, but
			   this behavior is modifiable via the options argument, as
			   described below.
			
			   The value of pid can be:

			   < -1   meaning wait for any child process whose process group ID
			          is equal to the absolute value of pid.

			   -1     meaning wait for any child process.

			   0      meaning wait for any child process whose process group ID
			          is equal to that of the calling process at the time of the
			          call to waitpid().

			   > 0    meaning wait for the child whose process ID is equal to
			          the value of pid.
	-->wait3(int *stat_loc, int options, struct rusage *rusage);
	-->wait4(pid_t pid, int *stat_loc, int options, struct rusage *rusage);
			The wait3() and wait4() system calls are similar to waitpid(2),
			but additionally return resource usage information about the child in the structure
			pointed to by rusage.
			
			Other than the use of the rusage argument, the following wait3() call:
			wait3(status, options, rusage);
			is equivalent to:
			waitpid(-1, status, options);
			
			Similarly, the following wait4() call:
			wait4(pid, status, options, rusage);
			is equivalent to:
			waitpid(pid, status, options);
			
			In other words, wait3() waits of any child,
			while wait4() can be used to select a specific child, or children,
			on which to wait. See wait(2) for further details.
			If rusage is not NULL, the struct rusage to which it points will be
			filled with accounting information about the child. See getrusage(2) for details.

# include <signal.h>
	-->signal, kill, sigaction, sigemptset, sigaddset
		void (*signal(int sig, void (*func)(int)))(int);
		  or in the equivalent but easier to read type-def'd version:

		 typedef void (*sig_t) (int);

		 sig_t
		 signal(int sig, sig_t func);

			Signals allow the manipulation of a process
			 from outside its domain, as well as allowing
			 the process to manipulate itself or copies of
			 itself (children).  There are two general types
			 of signals: those that cause termination of a
			 process and those that do not.  Signals which
			 cause termination of a program might result
			 from an irrecoverable error or might be the
			 result of a user at a terminal typing the
			 `interrupt' character.  Signals are used when a
			 process is stopped because it wishes to access
			 its control terminal while in the background
			 (see tty(4)).  Signals are optionally generated
			 when a process resumes after being stopped,
			 when the status of child processes changes, or
			 when input is ready at the control terminal		==> for CTRL C, CTRL D, CTRL /??

	int kill(pid_t pid, int sig);
			The kill utility sends a signal to the processes specified by the pid operands.

			 Only the super-user may send signals to other
			 users' processes.

	int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);

			struct  sigaction {
		         union __sigaction_u __sigaction_u;  /* signal handler */
		         sigset_t sa_mask;               /* signal mask to apply */
		         int     sa_flags;               /* see signal options below */
		 };

		 union __sigaction_u {
		         void    (*__sa_handler)(int);
		         void    (*__sa_sigaction)(int, siginfo_t *,
		                        void *);
		 };

		 #define sa_handler      __sigaction_u.__sa_handler
		//  #define sa_sigaction    __sigaction_u.__sa_sigaction
		 
			The sigaction() system call assigns an action for a signal specified by
			 sig.  If act is non-zero, it specifies an action (SIG_DFL, SIG_IGN, or a
			 handler routine) and mask to be used when delivering the specified sig-
			 nal.  If oact is non-zero, the previous handling information for the sig-
			 nal is returned to the user.

			 Once a signal handler is installed, it normally remains installed until
			 another sigaction() system call is made, or an execve(2) is performed.  A
			 signal-specific default action may be reset by setting sa_handler to
			 SIG_DFL.  The defaults are process termination, possibly with core dump;
			 no action; stopping the process; or continuing the process.  See the sig-
			 nal list below for each signal's default action.  If sa_handler is
			 SIG_DFL, the default action for the signal is to discard the signal, and
			 if a signal is pending, the pending signal is discarded even if the sig-
			 nal is masked.  If sa_handler is set to SIG_IGN current and pending
			 instances of the signal are ignored and discarded.

	int sigemptyset(sigset_t *set);
		sigemptyset() initializes the signal set given by set to empty,
		with all signals excluded from the set.

	int sigaddset(sigset_t *set, int signum);
		igaddset() adds and deletes respectively signal signum from set.

# include <sys/stat.h>
	stat, lstat, fstat
		int stat(const char *restrict pathname, struct stat *restrict statbuf);
			The stat utility displays information about the
			file pointed to by file.  Read, write or exe-
			cute permissions of the named file are not
			required, but all directories listed in the
			path name leading to the file must be search-
			able.  If no argument is given, stat displays
			information about the file descriptor for stan-
			dard input.
		int lstat(const char *restrict pathname, struct stat *restrict statbuf);
			lstat() is identical to stat(), except that if pathname is a
			symbolic link, then it returns information about the link itself,
			not the file that the link refers to.
		int fstat(int fd, struct stat *statbuf);
			fstat() is identical to stat(), except that the file about which
			information is to be retrieved is specified by the file
			descriptor fd.

# include <sys/types.h>
# include <dirent.h>
	opendir, readdir, closedir
		DIR *opendir(const char *name);
			 The opendir() function opens a directory stream corresponding to
			the directory name, and returns a pointer to the directory
			stream.  The stream is positioned at the first entry in the
			directory.
	struct dirent *readdir(DIR *dirp);
				The readdir() function returns a pointer to a dirent structure
			   representing the next directory entry in the directory stream
			   pointed to by dirp.  It returns NULL on reaching the end of the
			   directory stream or if an error occurred.
	int closedir(DIR *dirp);
				The closedir() function closes the directory stream associated
			with dirp.  A successful call to closedir() also closes the
			underlying file descriptor associated with dirp.  The directory
			tream descriptor dirp is not available after this call.

# include <sys/ioctl.h>
-->ioctl
	int ioctl(int fd, unsigned long request, ...);

# include <string.h>
	strerror
		char *strerror(int errnum);
			he strerror() function returns a pointer to a string that
			describes the error code passed in the argument errnum, possibly
			using the LC_MESSAGES part of the current locale to select the
			appropriate language.  (For example, if errnum is EINVAL, the
			returned description will be "Invalid argument".)  This string
			must not be modified by the application, but may be modified by a
			subsequent call to strerror() or strerror_l().  No other library
			function, including perror(3), will modify this string.

# include <readline/readline.h>
# include <readline/history.h>
readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay
add_history
	char * readline (const char *prompt);
		readline will read a line from the terminal and return it, using
		prompt as a prompt.  If prompt is NULL or the empty string, no
		prompt is issued.  The line returned is allocated with malloc(3);
		the caller must free it when finished.  The line returned has the
		final newline removed, so only the text of the line remains.

		readline offers editing capabilities while the user is entering
		the line.  By default, the line editing commands are similar to
		those of emacs.  A vi-style line editing interface is also
		available.

			readline returns the text of the line read.  A blank line returns
		   the empty string.  If EOF is encountered while reading a line,
		   and the line is empty, NULL is returned.  If an EOF is read with
		   a non-empty line, it is treated as a newline.

	void rl_clear_history (void) [Function]
		Clear the history list by deleting all of the entries,
		in the same manner as the History
		library’s clear_history() function. This differs from clear_history 
		because it frees private data Readline saves in the history list.


	int rl_on_new_line (void) [Function]
		Tell the update functions that we have moved onto a new (empty) line,
		usually after outputting a newline.

-->not found by compiler
	void rl_replace_line (const char *text, int clear undo) [Function]
		Replace the contents of rl_line_buffer with text.
		The point and mark are preserved, if possible.
		If clear undo is non-zero, the undo list associated with the current
		line is cleared.

	void rl_redisplay (void) [Function]
		Change what’s displayed on the screen to reflect the current
		contents of rl_line_buffer

	void	add_history(const char *)---> the input in the terminal