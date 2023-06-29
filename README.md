# my_bcmp

The purpose of the function is to compare the len of bytes, starting from where b1 points to, to the len of bytes, starting from where b2 points.
The return value is 0 if the two memory segments are found to contain identical content, and otherwise some value other than 0.
The order of the data in the input is: len, followed by the two indexes, and finally the string.
