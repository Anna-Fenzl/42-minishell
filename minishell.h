/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:33:47 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/28 18:11:48 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
// -->malloc,free, exit
# include <unistd.h>
// -->write, read, close, fork, getcwd, chdir, execve, dup, dup2, pipe
	// --> char *getcwd(char *buffer, size_t size); (get current working directory)
			// The getcwd() function copies the absolute path-
			//  name of the current working directory into the
			//  memory referenced by buf and returns a pointer
			//  to buf.  The size argument is the size, in
			//  bytes, of the array referenced by buf.

			//  If buf is NULL, space is allocated as necessary
			//  to store the pathname and size is ignored.
			//  This space may later be free(3)'d.
	// --> int chdir(const char *path);
			// the path is the Directory path which the user want
			// to make the current working directory.

			// Return Value: This command returns zero (0) on success.
			// -1 is returned on an error and errno is set appropriately.

# include <fcntl.h>
// -->open,
# include <sys/wait.h>
// -->wait, waitpid, wait3, wait4
	//--> waitpid(pid_t pid, int *stat_loc, int options);
			// >The waitpid() system call suspends execution of the calling
			//    thread until a child specified by pid argument has changed state.
			//    By default, waitpid() waits only for terminated children, but
			//    this behavior is modifiable via the options argument, as
			//    described below.
			
			//    The value of pid can be:

			//    < -1   meaning wait for any child process whose process group ID
			//           is equal to the absolute value of pid.

			//    -1     meaning wait for any child process.

			//    0      meaning wait for any child process whose process group ID
			//           is equal to that of the calling process at the time of the
			//           call to waitpid().

			//    > 0    meaning wait for the child whose process ID is equal to
			//           the value of pid.
	// -->wait3(int *stat_loc, int options, struct rusage *rusage);
	// -->wait4(pid_t pid, int *stat_loc, int options, struct rusage *rusage);
			// The wait3() and wait4() system calls are similar to waitpid(2),
			// but additionally return resource usage information about the child in the structure
			// pointed to by rusage.
			
			// Other than the use of the rusage argument, the following wait3() call:
			// wait3(status, options, rusage);
			// is equivalent to:
			// waitpid(-1, status, options);
			
			// Similarly, the following wait4() call:
			// wait4(pid, status, options, rusage);
			// is equivalent to:
			// waitpid(pid, status, options);
			
			// In other words, wait3() waits of any child,
			// while wait4() can be used to select a specific child, or children,
			// on which to wait. See wait(2) for further details.
			// If rusage is not NULL, the struct rusage to which it points will be
			// filled with accounting information about the child. See getrusage(2) for details.

# include <signal.h>
	// -->signal
		// void (*signal(int sig, void (*func)(int)))(int);
		//   or in the equivalent but easier to read type-def'd version:

		//  typedef void (*sig_t) (int);

		//  sig_t
		//  signal(int sig, sig_t func);
		
			// Signals allow the manipulation of a process
			//  from outside its domain, as well as allowing
			//  the process to manipulate itself or copies of
			//  itself (children).  There are two general types
			//  of signals: those that cause termination of a
			//  process and those that do not.  Signals which
			//  cause termination of a program might result
			//  from an irrecoverable error or might be the
			//  result of a user at a terminal typing the
			//  `interrupt' character.  Signals are used when a
			//  process is stopped because it wishes to access
			//  its control terminal while in the background
			//  (see tty(4)).  Signals are optionally generated
			//  when a process resumes after being stopped,
			//  when the status of child processes changes, or
			//  when input is ready at the control terminal			==> for CTRL C, CTRL D, CTRL /??
	// -->kill
		// int kill(pid_t pid, int sig);
			// The kill utility sends a signal to the processes specified by the pid operands.

			//  Only the super-user may send signals to other
			//  users' processes.
# include <sys/stat.h>
	// stat, lstat, fstat
		// int stat(const char *restrict pathname, struct stat *restrict statbuf);
			// The stat utility displays information about the
			// file pointed to by file.  Read, write or exe-
			// cute permissions of the named file are not
			// required, but all directories listed in the
			// path name leading to the file must be search-
			// able.  If no argument is given, stat displays
			// information about the file descriptor for stan-
			// dard input.
		// int lstat(const char *restrict pathname, struct stat *restrict statbuf);
			// lstat() is identical to stat(), except that if pathname is a
			// symbolic link, then it returns information about the link itself,
			// not the file that the link refers to.
		// int fstat(int fd, struct stat *statbuf);
			// fstat() is identical to stat(), except that the file about which
			// information is to be retrieved is specified by the file
			// descriptor fd.

# include <sys/types.h>
# include <dirent.h>
	// opendir, readdir, closedir
		// DIR *opendir(const char *name);
			//  The opendir() function opens a directory stream corresponding to
			// the directory name, and returns a pointer to the directory
			// stream.  The stream is positioned at the first entry in the
			// directory.
	// struct dirent *readdir(DIR *dirp);
			// 	The readdir() function returns a pointer to a dirent structure
			//    representing the next directory entry in the directory stream
			//    pointed to by dirp.  It returns NULL on reaching the end of the
			//    directory stream or if an error occurred.
	// int closedir(DIR *dirp);
			// 	The closedir() function closes the directory stream associated
			// with dirp.  A successful call to closedir() also closes the
			// underlying file descriptor associated with dirp.  The directory
			// tream descriptor dirp is not available after this call.
	
# include <string.h>
	// strerror
		// char *strerror(int errnum);
			// he strerror() function returns a pointer to a string that
			// describes the error code passed in the argument errnum, possibly
			// using the LC_MESSAGES part of the current locale to select the
			// appropriate language.  (For example, if errnum is EINVAL, the
			// returned description will be "Invalid argument".)  This string
			// must not be modified by the application, but may be modified by a
			// subsequent call to strerror() or strerror_l().  No other library
			// function, including perror(3), will modify this string.
	
# include <errno.h>
	// errno
		// The <errno.h> header file defines the integer variable errno,
		// which is set by system calls and some library functions in the
		// event of an error to indicate what went wrong.

		//errno
		//  The value in errno is significant only when the return value of
		//  the call indicated an error (i.e., -1 from most system calls; -1
		//  or NULL from most library functions); a function that succeeds is
		//  allowed to change errno.  The value of errno is never set to zero
		//  by any system call or library function.

		// Error numbers and names
		// Valid error numbers are all positive numbers.  The <errno.h>
		// header file defines symbolic names for each of the possible error
		// numbers that may appear in errno.

		// All the error names specified by POSIX.1 must have distinct
		// values, with the exception of EAGAIN and EWOULDBLOCK, which may
		// be the same.  On Linux, these two have the same value on all
		// architectures.

#endif