/* Author: acm
 * Date: 2024-09-10
 *
 * This program demonstrates a rudimentary buffer overflow vulnerability. To
 * trigger the vulnerability, the user must input more than 64 characters.
 *
 * Compile with `gcc -o OverflowingAmbitions OverflowingAmbitions.c -fno-stack-protector -z execstack`
 * Exploit with `python -c 'print("Y"*64 + "\x01\x02\x03\x04")' | ./OverflowingAmbitions`
 */

#include <stdio.h>

void hidden_function() {
  puts("Congratulations, you've successfully exploited the buffer overflow!\n");
  puts("Here's your flag: YCTF{never_use_this_function}\n");
}

void vulnerable_function() {
  char buffer[64];
  puts("Enter some text: ");
  // This function is vulnerable because it does not check the size of the input
  gets(buffer);
}

int main() {
  vulnerable_function();
  printf("Thank you for your input!\n");
  return 0;
}
