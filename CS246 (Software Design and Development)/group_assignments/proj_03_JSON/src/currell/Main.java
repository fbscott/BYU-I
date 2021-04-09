package currell;

public class Main {

    static final String SAVE_FILE = "C:/git_repos/BYU-I/CS246/group_assignments/proj_03_JSON/data/saveGame.txt";

    public static void main(String[] args) {
        // Create the player
        Player player = new Player(
                "Scott",
                100,
                50,
                50
        );
        // Create a game using our player, then save the game to a file.
        Game game = new Game(player);

        // Print it out to verify its values. We can put it directly in the println()
        // function because Player overrides the Object class' toString() method.
        // See https://docs.oracle.com/javase/7/docs/api/java/lang/Object.html#toString()
        System.out.println(player);

        game.saveGame(SAVE_FILE);

        // Create a new game using the file we created, then print out the player object
        // the game holds to make sure it matches what we had originally.
        Game newGame = Game.loadGame(SAVE_FILE);
        System.out.println(newGame.getPlayer());

        // STRETCH CHALLENGE //

        // Add some equipment to the player
        player.addEquipment("Sword", 10);
        player.addEquipment("Shield", 40);
        player.addEquipment("Lunch", 100);
        System.out.println(player);

        game.saveGame(SAVE_FILE);
        Game thirdGame = Game.loadGame(SAVE_FILE);
        System.out.println(thirdGame.getPlayer());
    }
}
