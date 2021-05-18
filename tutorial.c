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

// so you understood pointers and came back huh? ok lets move on then.
// there are int argc and char** argv, just ignore those for now. i included them so you arent confusy when you see them in the wild.
int main(int argc, char** argv)
{
  some_stuff();
  // this main method is the one being executed when you double click the .exe file the compiler spits out.
  // all your program ever will do is what the main method does.
  // since main is of type int we need to return an integer. however since main is special, we dont have to.
}// this is perfectly fine also.

void some_more_stuff()
{
  // now that we know all about methods, functions, data types and pointers, its time to introduce you to something called objects.
  // c has no classes, which most other object oriented languages use. 
  // c uses structs or unions.
  struct Demo_Struct
  {
    int a, b;
  };
  // this is how you define a struct
  // the Demo_Struct then can be used as if it was a built-in data type.

  // this is how you instantiate a struct e.g. you actually make one. defining is merely the blueprint for making it.
  struct Demo_Struct ds;
  ds.a = 69;
  ds.b = 420;

  // you can do the same shit with unions:
  union Demo_Union
  {
    int a;
    char b[4];
  };

  union Demo_Union du;
  du.a = 69;

  // unions and struct are similar but distinct.
  // when you look inside memory, structs will reserve just as much memory as they need to put all the members in there.
  // the members are a and b in the case of Demo_Struct.
  // structs lay out the members directly after one another in memory.

  // unions behave different. they only need as much memory as one of their members.
  // all members have the same memory adress.
  // the values are just being interpreted in other ways.
  // you will not need a union as often as a struct, but it does come in handy from time to time.

  struct UFO
  {
    double velocity;
    double coordinate_x;
    double coordinate_y;
    double height;
  };

  // now we programmers do some good stuff like programming a game that has ufos in it.
  // everytime we wanted to instanciate a ufo we had to do:
  struct UFO ufo_1;
  // then we had to manually fill all the members with data:
  ufo_1.coordinate_x = 0;
  ufo_1.coordinate_y = 0;
  ufo_1.velocity = 0;
  ufo_1.height = 0;

  // this sucks! so much effort to type this shit out. imagine we were to create 100 ufos. so much work.
  // luckily since we programmers are a lazy bunch we have ways to make this shit easier.
  // like defining a function that does all this crap for us.
}

// we pass a pointer to a ufo in there so we change the ufo that we give in.
// if we were to just put in the ufo directly like in
// void init_ufo(struct UFO ufo)
// then we would make a copy of the ufo we pass in. we dont want to copy, thats slow. use a pointer.
// besides being slow as fuck, we wouldnt change the ufo if we passed it in like in the example of init_ufo()
// because the function makes a copy we wouldnt change the actual ufo but make the changes to the copy of the ufo.
// when we leave the function our copy is gone and so are the changes we made.
// so we just pass in a pointer. problem solved.

void initialize_ufo(struct UFO* theUfo)
{
  theUfo->coordinate_x = 0;
  theUfo->coordinate_y = 0;
  theUfo->velocity = 0;
  theUfo->height = 0;
}

// did you remember how to instantiate an integer?
void more_stuff()
{
  //just like this
  int a = 69;

  // and now how to make a ufo?
  struct UFO ufo;
  initialize_ufo(&ufo);

  // now theres not really anything wrong with that but what if i told you that there is a way where you could leave out the struct everytime you instanciated a ufo
  // heres how to do that:

  typedef struct
  {
    double velocity;
    double coordinate_x;
    double coordinate_y;
    double height;
  }UFO2;

  //with this typedef struff we can now:
  UFO2 ufo2;
  initialize_ufo(&ufo2);
  // i just think this looks a little nicer and cleaner.
  // same thing works with unions.  
}

void arrays()
{
  // now we know some stuff about objects.
  // remember when i said like what if we were to make 100 (~~ufos~~) ints?
  // how shitty would it be to just go ahead and do like
  int i1 = 0;
  int i2 = 0;
  int i3 = 0;
  int i4 = 0;
  //...
  // that would be stupid right?
  // good thing that there is something called array that really saves our ass here.
  int array[100]; // we have now memory for 100 ints that is in one row.
  // if we want to acces this memory we can just do
  array[1] = 69;
  array[2] = 420;
  array[3] = 0;
  array[4] = 0;
  array[4] = 0;
  //and we can read it by doing
  printf("%d", array[3]);

  // now thats all nice and cool but there are some issues with that:
  //    first of all we didnt save work. its still a shit-ton to type out.
  //    second: if we create all this memory how do we keep track of it?
  //    what if i want to give the array to a function to maybe initialize it?
  //      would i have to pass array[1] to array[100] manually?

  // to tackle the first one:
  // in c there are loops. with loops we can execute same code multiple times.
  int i = 0;
  while(i < 100)
  {
    i = i + 1;
    printf("%d ", i);
  }
  // this will print the numbers 0 to 99.
  // and we can use this to initialize arrays as well:
  i = 0;
  while(i < 100)
  {
    array[i] = 0;
    i = i + 1;
  }
  // puts a 0 in all the array's registers (yes array index starts at 0)

  // second: we dont have to track memory just yet.
  // if i create a scope here:
  {
    // i can create as many ints as i want
    int arr[1000];
    // by the end of the closing brace the memory will be deleted automatically.
  }
}
  // if you want to pass arrays to functions, you do what we did with the struct:
  // just pass a pointer to its memory.
void pass_array(int* array)
{
  array[0] = 69;
  array[1] = 420
  int i = 2;
  while(i < 10)
  {
    array[i] = 42;
    i = i + 1;
  }
}

void arrei()
{
  int array[10];
  pass_array(&array);
}
// easy right?

// now there are some things that can make our lifes even easier:
// instead of using i = i + 1; in every while loop, we can do i++ or ++i.
// this does the same as i = i + 1;

// there is not only the while loop, but also the for loop:
void demonstrate_for_loop()
{
  for(int i = 0; i < 10; i++)
  {
    printf("%d ", i);
  }
}
// this is pretty easy to understand: the for loop has 3 compartments:
    // in the first one there is the initialization of some index counter.
    // in the second there is the same condition as in the while
    // in the third there is the increment of the counter. this part
    // will be executed once at the end of every looping.

// that is all there is to arrays and loops but not really:

void rest()
{
  // there are conditionals:
  int i = 42;
  if(i < 69)
  {
    printf("i is %d. that is less than 69", i);
  }
  else if(i == 69)
  {
    printf("i is %d. that is exactly 69.", i);
  }
  else
  {
    printf("i is %d. that is more than 69.", i);
  }

  // there is a funny thing that makes lots and lots of conditionals a little easier to read:
  switch(i)
  {
    case 0: printf("i is zero."); break;
    case 1: printf("i is 1."); break;
    case 2: printf("i is 2."); break;
    case 3: printf("i is 3."); break;
    default: printf("i is %d.", i);
  }
  // using break is not really very clean and by some programmers its seen like some kind of heresy so be careful when you use it.

  // there is another way of allocating memory. i could go very in-depht with this but we both dont want that.
  int* bigger_array = malloc(1000000 * sizeof(int));
  // this is how we create really big arrays because they might not fit on the stack. 
  // you can look up what stack and heap are here: https://www.youtube.com/watch?v=IMC0y7ZC4YE

  // if you reserve memory using malloc, then you have to manually free it when you are done messing around with it.
  free(bigger_array);
  // heap allocation is waay slower than stack allocation. that means that you should always reserve memory on the stack when you can.
  // also stack allocation does the freeing automatically as we discussed a little earlier.
}

// and welcome. this is all about c. be sure you visit the c++ part of the tutorial if you found it helpful.