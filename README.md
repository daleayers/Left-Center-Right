# Left-Center-Right
7-2 Final Project LCR
I chose LCR because it is a game that my family and I have played together on holidays. The game presents a few challenges when coding. These problems include:
1.	How to store players and their corresponding scores
a.	How to display the players and scores
b.	How to determine a winner
2.	How to roll dice
a.	What to do depending on the dice roll
b.	How to match the corresponding amount of dice to the number of chips
How I began was I thought that I would store the players and scores using a map. Using a map seemed like the most straightforward choice because it was an easy way to store key-value pairs. This presented a problem later in coding, though, as inside a map, it cannot iterate over a 0 and in this game, that is required. I played around with some solutions in trying to maybe convert the 0 to a different type of variable but ultimately decided that I would have to start from the beginning and use vectors instead. Dealing with issues from my decision to use a map was probably the most significant hurdle in this entire project. 
After the problem with the map, the rest was simple logic building and coding. Playing with if-else statements to get the desired outcomes after rolling the dice. I chose to have the player press r after every turn to "roll the dice" to create suspense. After the dice is rolled, I would display the scores of each player, including the number of chips in the pot. This would loop until there was one player left with chips. The rolling of the dice is simply that I used a random number generator to create the feel of a dice roll and used if-else statements to work out the logic. I then had to check and make sure that the dice matched the number of chips the player had with a max of three. I solved this by defining a constant max dice and then used a series of if-else statements to match the number of dice to the number of chips. 
In the end, I had a lot of fun making this game and learned a valuable lesson regarding maps.





PsuedoCode 
START

1.	Display a main menu where you can:
•	1. Display Rules
•	2. Start the Game
•	3. Exit
2. IF the game is started, ask the user to enter the number of players
3. IF the number of players is less than three, ask the user to add more players
4. Each player starts with three chips
5. LOOP until only one player has chips:
  6. For each player:
    7. Calculate the number of dice to roll based on the player's remaining chips (1 die IF 1 chip, 2 dice IF 2 chips)
    8. Roll the dice by randomly generating a number between 1 and 6 for each die
    9. For each die:
      10. IF the result is 1 (L), pass one chip to the player to the left
      11. IF the result is 2 (R), pass one chip to the player to the right
      12. IF the result is 3 (C), place one chip into the center pot
    13. Check if the player has no chips left, IF so, player is still in the game but does not roll dice
6. Display a message to the game winner

END
Psuedocode exmplination
I essentially followed my pseudocode; the one thing that I modified is I got rid of the menu just to save time. I added some complexity when it comes to 5. Here I made the user enter 'r' to roll the dice and display the scores to create suspense for those playing the game. Otherwise, the players are just hitting enter, and the game is displaying a winner, what's the fun in that? 




 

