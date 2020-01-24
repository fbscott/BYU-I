package currell;

import java.util.HashMap;
import java.util.Map;

public class Player {

    private String name;
    private int health;
    private int mana;
    private int gold;

    private Map<String, Integer> equipment;

    /**
     * Creates a new instance of the player class.
     * @param name The name of the player.
     * @param health The player's starting health.
     * @param mana The player's starting mana.
     * @param gold The player's starting gold.
     */
    public Player(String name, int health, int mana, int gold) {
        this.name = name;
        this.health = health;
        this.mana = mana;
        this.gold = gold;

        // Another example of "interface (Map) vs implementation (HashMap)"
        // Everything that deals with equipment is only needed for the stretch challenge.
        // To read more about Maps and HashMaps, see:
        //
        // https://docs.oracle.com/javase/tutorial/collections/interfaces/map.html
        // https://www.mkyong.com/java/how-to-use-hashmap-tutorial-java/
        // https://www.tutorialspoint.com/java/java_map_interface.htm
        this.equipment = new HashMap<>();
    }

    public String toString() {
        return String.format("Player %s has %d health, %d mana, and %d gold.\nThey are holding %d items.\n",
                name, health, mana, gold, equipment.size());
    }

    // public void displayPlayer() {
    //     System.out.println("Name: " + name);
    //     System.out.println("Health: " + health);
    //     System.out.println("Mana: " + mana);
    //     System.out.println("Gold: " + gold);
    // }

    /**
     * Add an item to the player's equipment.
     * @param itemName The item's name.
     * @param itemValue The item's value.
     */
    public void addEquipment(String itemName, int itemValue) {
        equipment.put(itemName, itemValue);
    }
}
