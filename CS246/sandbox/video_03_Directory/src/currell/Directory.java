package currell;

import com.google.gson.Gson;

import java.util.*;

public class Directory {

    public static void main(String[] args) {
        /*********************************** Lists ***********************************/
        // add imports via "alt + enter"
        Collection<String> directory; // collection of strings

        // ArrayList: Put stuff at the end of the array.
        directory = new ArrayList<String>();

        // LinkedList: Deal with things on the "outside" (by reference/pointers).
        directory = new LinkedList<String>();

        // HashSets: Don't have duplicates and does't preserve order.
        //           Selects index baaed on value, not the order the item was added.
        directory = new HashSet<String>();

        // TreeSet: Don't have duplicates but does sort.
        directory = new TreeSet<String>();

        directory.add("John");
        directory.add("Paul");
        directory.add("George");
        directory.add("Ringo");
        directory.add("Paul"); // removed in HashSet and TreeSet (no duplicates allowed)

        System.out.println("/*********************************** Lists ***********************************/\n");

        for (String name : directory) {
            System.out.println(name);
        }

        System.out.println();

        /*********************************** Sets ***********************************/
        Collection<User> directory_2; // User collection

        // ArrayList: Put stuff at the end of the array.
        directory_2 = new ArrayList<User>();

        // LinkedList: Deal with things on the "outside" (by reference/pointers).
        directory_2 = new LinkedList<User>();

        // HashSets: Not supposed to have duplicates, but we're comparing objects, not strings.
        //           Java sees these as different objects. Doesn't look at the values contained in them.
        directory_2 = new HashSet<User>();

        // TreeSet: Errors out because TreeSets want to sort data. Since collections can't sort objects.
        //          No way of determining if one object is greater than or less than another.
        //          Cannot determine equality.
        // directory_2 = new TreeSet<User>();

        // Can pass multiple values because our collection is a User collection.
        // Before it was just strings. Strings cannot have multiple values.
        directory_2.add(new User(
                "John",
                "john.lennon@beatles.com",
                "555-0001",
                23)
        );
        directory_2.add(new User(
                "Paul",
                "paul.mccartney@beatles.com",
                "555-0002",
                21)
        );
        directory_2.add(new User(
                "George",
                "george.harrison@beatles.com",
                "555-0003",
                20)
        );
        directory_2.add(new User(
                "Ringo",
                "ringo.starr@beatles.com",
                "555-0004",
                23)
        );
        directory_2.add(new User(
                "Paul",
                "paul.mccartney@beatles.com",
                "555-0002",
                21)
        );

        System.out.println("/*********************************** Sets ***********************************/\n");

        for (User user : directory_2) {
            System.out.println(user);
        }

        System.out.println();

        /*********************************** Maps ***********************************/
        // Requires two values
        Map<String, User> directory_3;

        // No duplicate keys. If there are dupes, the last one will be used since the "put" overwrites the last one(s).
        directory_3 = new HashMap<String, User>();

        // Same as HashMap, but sorted by key.
        directory_3 = new TreeMap<String, User>();

        // These are all "put"s, not "add"s.
        directory_3.put("John", new User("John", "john.lennon@beatles.com", "555-0001", 23));
        directory_3.put("Paul", new User("Paul", "paul.mccartney@beatles.com", "555-0002", 21));
        directory_3.put("George", new User("George", "george.harrison@beatles.com", "555-0003", 20));
        directory_3.put("Ringo", new User("Ringo", "ringo.starr@beatles.com", "555-0004", 23));
        directory_3.put("Paul", new User("Paul", "paul.mccartney@beatles.com", "555-0002", 21));

        System.out.println("/*********************************** Maps ***********************************/\n");

        System.out.println("Get one value:");
        System.out.println(directory_3.get("George"));

        System.out.println();
        System.out.println("/*********************************** Maps (cont.) ***********************************/\n");

        System.out.println("Keys:");
        for (String key : directory_3.keySet()) { // keySet to get all keys from the set
            System.out.println(key);
        }

        System.out.println();
        System.out.println("/*********************************** Maps (cont.) ***********************************/\n");

        System.out.println("Values:");
        for (User user : directory_3.values()) {
            System.out.println(user);
        }

        System.out.println();

        /*********************************** GSON / JSON ***********************************/
        User chuck = new User("Chuck Norris", "chuck@chucknorris.com", "303.555.1234", 145);
        Gson gson = new Gson();
        String json;

        System.out.println("/*********************************** GSON / JSON ***********************************/\n");

        // Convert chuck to JSON
        json = gson.toJson(chuck);

        System.out.println(json);

        System.out.println();
        System.out.println("/*********************************** GSON / JSON (cont.) ***********************************/\n");

        // Convert JSON back to object
        User obj = gson.fromJson(json, User.class);

        System.out.println(obj);

        System.out.println();
        System.out.println("/*********************************** GSON / JSON (cont.) ***********************************/\n");

        // Another object to JSON example
        json = gson.toJson(directory_2);

        System.out.println(json);

        System.out.println();
        System.out.println("/*********************************** GSON / JSON (cont.) ***********************************/\n");

        // JSON array to objects
        User[] beatles = gson.fromJson(json, User[].class);

        for (User user : beatles) {
            System.out.println(user);
        }

        System.out.println();
        System.out.println("/*********************************** GSON / JSON (cont.) ***********************************/\n");

        // List out each array
        List<User> beatlesList = new ArrayList<User>(Arrays.asList(beatles)); // create a collection and pass it to
                                                                              // ArrayList constructor

        for (User user : beatlesList) {
            System.out.println(user);
        }
    }
}
