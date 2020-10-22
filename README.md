# C-Animals
I basic 20 questions style game where the computer tries to guess what animal you are thinking of
## What is this?
This program simulates a game similar to 20 questions where the computer will ask the user a series of yes/no questions to try and figure out what animal the 
user is thinking of. At the start the only animal the computer knows is dog. So the first question it will ask is "is it a dog?". If the user answered yes then the computer wins.
However if the user answered no then the computer will ask what animal the user was thinking of and ask for a yes/no question that can differentiate a dog and whatever animal
the user thought of. The computer will then learn this and store the new questions in a binary tree data structure. The game will continue on and on like this until the user 
either quits or the computer correctly guesses what animal they were thinking of.

## Example Output




Is it a dog?  
 no  
I lose! What animal were you thinking of?  
 cat  
Please give me a yes/no question that distinguishes between a dog and a cat.  
 Does it bark?  
Would the answer to this question be yes or no for a dog?  
 yes  
Thank you.  Would you like to play again?  
 yes  

Does it bark?  
 no  
Is it a cat?  
 no  
I lose! What animal were you thinking of?  
 turtle  
Please give me a yes/no question that distinguishes between a cat and turtle  
 Does it have a shell?  
Would the answer to this question be yes or no for a cat?  
 no  
Thank you.  Would you like to play again?  
 yes  

Does it bark?  
 no  
Does it have a shell?  
 yes  
Is it a turtle?  
 no  
I lose! What animal were you thinking of?  
 snail  
Please give me a yes/no question that distinguishes between a turtle and snail  
 Is it a reptile?  
Would the answer to this question be yes or no for a turtle?  
 yes  
Thank you.  Would you like to play again?  
 yes  

Does it bark?  
 no  
Does it have a shell?  
 yes  
Is it a reptile?  
 no  
Is it a snail?  
 yes  
I win!  
