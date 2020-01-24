package currell;

import com.google.gson.Gson;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Game {

    // instance of Player stored as member variable
    private Player player;

    /**
     * Create a new game.
     * @param player The user's player.
     */
    public Game(Player player) {
        this.player = player;
    }

    /**
     * @return The user's player.
     */
    public Player getPlayer() {
        return player;
    }

    /**
     * Saves the current game state (the player stats) to a file using UTF-8 encoding.
     * @param filename the file to save to.
     */
    public void saveGame(String filename) {
        // import Gson library
        Gson gson = new Gson();
        // serialize player data
        String playerData = gson.toJson(player);

        // Save the string to a file. Note the use of the "try-with-resources" syntax.
        // For more details, see: https://www.mkyong.com/java/try-with-resources-example-in-jdk-7/
        //
        // There are simpler ways to save text files in Java, but they don't allow us to specify the character
        // encoding. This is a critical issue if we want to save a file on a computer in say, Japan, and load the
        // file on a computer in Germany. By explicitly stating how the file is encoded (UTF-8), we can make sure
        // our file is saved and read properly on any computer.
        //
        // There are some 3rd party libraries that make saving easier, but it's good to know how to do it
        // in "pure java".
        //
        // This is a very big deal, and if you haven't already, you should read:
        // https://www.joelonsoftware.com/2003/10/08/the-absolute-minimum-every-software-developer-absolutely-positively-must-know-about-unicode-and-character-sets-no-excuses/
        try(Writer w = new BufferedWriter(new OutputStreamWriter( new FileOutputStream(filename), "UTF-8"))) {
            w.write(playerData);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * This method creates a new Game instance using the contents of the specified file.
     * @param filename The file to load the player stats from.
     * @return The new game.
     */
    static Game loadGame(String filename) {
        // import Gson library
        Gson gson = new Gson();
        // preparing for file contents
        String gameData = null;

        // Loading files with a specified encoding is easier than saving them.
        try {
            byte[] encoded = Files.readAllBytes(Paths.get(filename));
            gameData = new String(encoded, "UTF-8");
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Deserialize our player back from the json string to a class instance.
        Player savedPlayer = gson.fromJson(gameData, Player.class);

        // Create a new game with the player we just deserialized.
        Game newGame = new Game(savedPlayer);

        // return the new game
        return newGame;
    }
}
