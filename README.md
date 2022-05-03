# Minitalk - Establish a communication between 2 programs

As said in the title, this project consists in establishing a connection between two programs to send a message from a client to a server.
The catch here is the only allowed way to communicate is through the use of signals, specifically SIGUSR1 and SIGUSR2. If you're trying to
do this project from scratch, I advise you to read up on **sigaction** and, most importantly, **bitwise operations**. Final tip, *printf* 
is **not** async safe and could lead to errors while printing the message.

## How to use it

After cloning the repository, use the ```make``` command to get the **client** and **server** executables. Run the **server** in a terminal
to get the *PID* argument that the **client** requires and then run the following in another terminal:

```
./client [PID] [message]
```
Send any message you'd like (including unicode characters) and confirm the reception on the server side. Have fun!
