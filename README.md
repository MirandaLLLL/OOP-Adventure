# OOP-Adventure

The Story

Adventure is a CLI game. The player has to explore a castle, which consists of several levels and many rooms. The task of the player is to find the room where the princess is prisoned and take her leave!

There are many types of rooms, and each type has distinct exits. Note that there is a monster in one of the rooms, whose exact location is unknown. But once the player meets the monster, the game is over.

The program always shows information about the room into which the player enters: the name of the room, how many exits are there, and the names of all the exits. For example, the player is in the lobby of the castle when the game starts, and the program outputs:

Welcome to the lobby. There are 3 exits: east, west and up.
Enter your command:
Then the player can input the command go followed by the name of the exit that he/she would like to pass through, e.g.,

go east
Consequently, the player goes into the room to the east. The program gives the information of that room, like what is shown above for the lobby. This process repeats.

During this process, if the player enters a room with a monster, the program shows a message and game over. Likewise, once the player enters the secret room where the princess is, the program shows the conversation between the role and the princess. After that, she is ready to leave with the role. Then the player has to find their way out. The only way to leave the castle is via the lobby.

To simplify the implementation, all the printed messages and the user input are shown in English.
