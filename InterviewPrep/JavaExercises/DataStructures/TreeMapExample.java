import java.util.TreeMap;
import java.util.Map;

public class TreeMapExample {
    public static void main(String[] args) {
        // Creating a TreeMap
        TreeMap<String, Integer> treeMap = new TreeMap<>();
        
        // Adding key-value pairs
        treeMap.put("Alice", 30);
        treeMap.put("Bob", 25);
        treeMap.put("Charlie", 35);
        treeMap.put("AAAAba", 10000);
        treeMap.put("Zoje", 1);
        
        // Retrieving a value
        System.out.println("Alice's age: " + treeMap.get("Alice")); // 30
        
        // Checking for key or value presence
        System.out.println("Contains 'Bob'? " + treeMap.containsKey("Bob")); // true
        System.out.println("Contains value 25? " + treeMap.containsValue(25)); // true
        
        // Removing a key-value pair
        treeMap.remove("Bob");
        System.out.println("Contains 'Bob' after removal? " + treeMap.containsKey("Bob")); // false
        
        // Iterating over the TreeMap
        for (Map.Entry<String, Integer> entry : treeMap.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
        
        // Checking the size of the TreeMap
        System.out.println("Size of the map: " + treeMap.size()); // 2
        
        // Clearing the TreeMap
        treeMap.clear();
        System.out.println("Size of the map after clearing: " + treeMap.size()); // 0
        System.out.println("Is the map empty? " + treeMap.isEmpty()); // true
    }
}
