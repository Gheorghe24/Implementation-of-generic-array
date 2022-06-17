# TEMA 1 IOCLA (Anul I)

Main:
-------

For the beginning I allocated the commands that I was going to read from the keyboard and those 2 structures.
I specify that in the structure I allocated exactly the number of bits that each word uses and I only read on a maximum length.
Then I use a while loop until the "exit" command with each instruction

The most difficult part of these is insert.

For each type of input I initiate the variables and read them according the instructions, next I save them in the structure with the help of memcpy and the length of each type. I increase the length which helps me to go easier and know where to put each bit.

After that I read the last word and also reallocate the memory to insert it.
Then I use the Add_last function and allocate memory for data->data.

The other cases are very easy to understand so I said not to make a separate explanation.

ADD_LAST:
------------
I use an auxiliary void pointer in which I save the given structure as a parameter

I go through the structure and save it as a "bit vector". 
I need to always use casting depending on the values I have in the structure and copy this data to the "tmp" auxiliary. I also calculate the length of the "date" structure as I go through and insert it in tmp.

After this I have 2 cases:
1.when the vector is empty and I only allocate memory for it and my auxiliary children  2.when it is not empty and I need to reallocate memory to insert another element.

I always calculate the length of the whole "arr" to know how much I should reallocate and where to insert the element.

ADD_AT:
-----------
There are 3 cases:
1.index less than 0, return error
2.index higher than len, I add at the end
3.insert in array:
The first time I go through the "arr" to the end and find the length, I also find the length to the index
In another auxiliar I save the data as an element in the vector and I also save in a variable its length. I still reallocate memory for this element and find the position from where I should insert (Aux2).
Next I move the elements after the index to aux2 + the length of the inserted element and then insert it on it.
Finally, I deallocated memory for the assigned auxiliary

Find:
----------
There are also 3 cases, in case I look in the array, I go to the index as in the previous functions and then I print exactly from aux an element of "arr" with the help of the print function created below.

Delete_at:
----------
As with the add_at function, I go through the array to the end and use auxiliary pointers to save some important positions. the end of the index element (length len_aux) at the beginning of it (arr + len1 (length to index)). Reallocate less memory, same as saved lengths and decrease length (len)

Print:
---------
With the help of a repetitive for-type structure, I traverse the whole vector with an index to its length (len = number of elements in the vector);
I take the first element by casting the arr position with an unsigned char to take exactly the "type" given from the keyboard saved in the structure and then in each element.
I print the type (that's how I give it the name to use it further). This way I get to the position where I have those 2 banknotes, but I have to display the second name first and that's why I print arr + sizeof (the 2 types of numbers together). Then I display the banknotes and I can move on. in the array with their size.

After I get out of these 3 cases (3 types), I move with the bits of the second word to get to the beginning of the next element.

