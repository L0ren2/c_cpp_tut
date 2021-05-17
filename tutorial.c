#include <stdio.h> // dont worry bout this now


// single line comment
/*
  multiline comment
  /*
    cant be nested, just if you wanted to know
  */
// */

// you might have heard that c is a close-to-hardware-language. that is true. 
// so much so that there are several categories on how to save data.
// we call those "data-types".
// basic data types:
int i;      // holds whole numbers, on most machines that will be 4 bytes. ~ -32k - 32k
float f;    // floating point numbers, on most machines that will be 4 bytes. ~ -149 - 127
double d;   // double precision float, on most machines that will be 8 bytes. ~ −2^53 - 2^53
char c;     // holds one character of data, that is 1 byte. a char might be 'A'. -128 - 127
unsigned int ui;   // same as int but without the ability to store negative nums: 0 - ~65k
unsigned char uc;  // same as char but it cant store negative nums: 0 - 255
// these are the ones you are very likely to encounter on your c-journey. however there are some more.
// to learn about them, please visit https://en.wikipedia.org/wiki/C_data_types.


// since c is a language that has been quite late to the game, it has of course functions.
// if you never heard of functions, you should learn the concepts first. its not hard to find useful
// information about that online.

// foo is a function of type int, that is why it has to return an integer.
int foo()
{ // per c-conventions we put the brace here, you might be wondering on that if you come from java.
  return 0; // dont forget the semicolon.
}

int bar(int x)
{
  // call to another function
  return x + foo(); // add x to foo's return value
}

void baz()
{
  // void doesnt need to return anything
}

void bazz() 
// as you can see, we can do some real dumb shit with the braces here. i could write them waaay down, c doesnt care. however dont.
// your co-workers will kill you...
{
  //printf, one of the most classic print functions
  // %d will take an int, put that shitter in the string and print it
  // in other words, %d will be substituted by the return value of bar.
  //we need stdio to use printf
  printf("bar return: %d", bar(69));
  //again, no return
}
void some_stuff()
{
  // now that we know so much about functions, lets do some other stuff here.
  // there is this weird principle called pointers... but dont let them fool you!
  // pointers are really not that hard. if you have problems understanding this shit,
  // please go to https://www.youtube.com/watch?v=iChalAKXffs. that guy can explain stuff really well.

  //for now, you can stick around :)
  // i holds an integer and is located somewhere in memory. about where -- we usually dont give a shit.
  int i = 42;

  // the '&' means like: "gimme the mem adress youre at"
  int* ip = &i;
  // ip now stores the adress of where i is located.

  // print the adress of i
  printf("i is located at: &d", ip);

  // *ip means: "gimme what ip points to" -- that is -- i
  printf(" i is: %d", *ip);

  // now i hear you saying "man this was some dumb ass example, we could have just done that shit with an int directly".
  // and your right! we could have done this with an int alone.

  // but -- and this is really important: assume that instead of int i -- we had a really large block of memory (> 2 kB) and we had to move it around... 
  // that happens quite regularly in programming btw... you know how moving works? if you want to move 'a' to place B, you got to
  // copy 'a' from where it is now, then paste it to wherever the heck B is, and then delete the original place of where 'a' was.
  // seems nice right? you see -- this is very inefficient, like big time.
  // you wanna go to efficient town, you gotta stop the damn copies!

  // long story short: if you can get away with using a pointer, you should. because with pointer you dont need to copy.
  // always use a pointer when you can!
  // except if the data the pointer points to is very small -- were talking smaller than 10 bytes.
  // that is because a pointer itself needs 8 bytes of memory to be stored. also the memory needs to be looked up, which takes some time.
  // stuff smaller than 10 byte is usually faster to look up and copy than to look up the 8 byte pointer to it and copy the original memory's adress.

  // and that is it about pointers. you can get very sophisticated with that shit. and we will do later on. make sure you get this stuff.
  // take a break, take it easy and just read shit about pointers, watch the video, do some dumb practice like with the int i up there
}

// there are int argc and char** argv, just ignore those for now. i included them so you arent confusy when you see them in the wild.
int main(int argc, char** argv)
{
  some_stuff();
  return 0;
}