Filename: crack

Author: Canahedo


This program accepts a hash as a command line argument, and attempts to crack it using a salt, assumed to be "50", but changeable in code.
The program only works for passwords of up to four charactors.

It will cycle through uppercase then lower case letters for a one charactor password, crypting each, and comparing to the given hash.
If successful, it will output the password, if unsuccessful it will attempt a password with one aditional charactor.
If still unsuccessful after attempting a four charactor password, an error will occur.