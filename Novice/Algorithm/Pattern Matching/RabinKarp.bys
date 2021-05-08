/*String Matching*/
/*There is a string and a pattern. Whethere the pattern pat is substring of 
the given string str or not.*/
/*Rabin Karp ALgorithm [Average Case :- O(n+m)]
It is based on rolling hash technique. Suppose we have a hash function and
which take a input string and gives a unique hash.
Let 
   str -> ababcabdab
   hash(str) --> x
   hash("babc") --> y
   str[1,4]-->babc
   If we know the hash value of given sub-string starting from index i and ending 
   at index j.
   If we want to know the hash value of given sub-string starting from index i+1 and ending 
   at index j+1. Then we can get this is O(1).
   
   Suppose for the string index from 0 to 2.The sub-string is "aba".There is a
   hash function which only does the simple thing that adds the ASCII value of
   characters. ASCII a+b+a :- 97+98+97=292.
                                          We can calulate the hash value of 
    index i+1 to j+1 in O(1). a+b+a-a+b=292-97+98=293.
    
    ALgorithm
    
    Hash(str)
    1.Calcualte the hash of pattern.
    2.Calcualte of the hash of the sub-string of given string.[0,patsize-1].
    These two step will take O(m).Where m is size of pattern.
    
    At each step we will check the hash of pattern is equal to hash of the
    sub-string. 
     (i)If the match is found then for double checking we will iterate over
        the whole pattern and sub-string characters by characters.If all the 
        characters matches then we found a pattern.
    (ii)If the match is not found then we will shift the windows
        to str[i+1,j+1] hash value.
        
    The ALgorithm can be shortened in these steps :-
    1. Initially calculate the Hash value of pattern and the first sub-string.
    2.Try to iterate over the whole given sub-string in particular window-size.
      Then,we will check if our current hash-value matches the hash-value of 
      pattern. If it matches we will double check by iterating over the pattern
      and sub-string characters by characters.If all the characters matches then
      we found a pattern.
    In worst case if every sub-string has the same hash value as of pattern.
    Then this will also take same complexity as brute force. O(n*m).
   */
