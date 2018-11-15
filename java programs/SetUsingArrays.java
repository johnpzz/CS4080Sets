/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package CS408;

import static CS408.SetUsingArrayLists.difference;
import static CS408.SetUsingArrayLists.initialize;
import static CS408.SetUsingArrayLists.intersection;
import static CS408.SetUsingArrayLists.prompt;
import static CS408.SetUsingArrayLists.symmetricDifference;
import static CS408.SetUsingArrayLists.union;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author John
 */
public class SetUsingArrays {
    private int[] set;
   
 
    SetUsingArrays(int size) {
        set = new int[size];
        
        for (int i : set) {
            set[i] = -1;
        }
    }
    
    
    public static boolean search(int[] array, int n) {
        
        for (int i = 0; i < array.length; i++) {
            if (array[i] == n) {
                return true;
            }
        }
        
        return false;
    }
   
    
    public static void union(int[] set1, int[] set2) {
        long start = System.currentTimeMillis();
        int[] resultSet = new int[Math.max(set1.length, set2.length)*2];
        
        for (int i = 0; i < set1.length; i++) {
            boolean found = search(resultSet, set1[i]);
            if (found == false)
                resultSet[i] = set1[i];
        }
        
        for (int i = 0; i < set2.length; i++) {
            boolean found = search (resultSet, set2[i]);
            if (found == false)
                resultSet[i+set1.length] = set2[i];
        }

        System.out.print("Union Set: ");
        for (int i : resultSet) {
            if (i != 0)
                System.out.print(i + " ");
        }
        long end = System.currentTimeMillis();
        long time = Math.abs(end - start);
        System.out.println("\nTime: " + time + " ms");
        System.out.println();
        
    }
    
    /*
    public static void union(int[] set1, int[] set2) {
        int i = 0; int j = 0;
        while (i < set1.length && j < set2.length) {
            if (set1[i] < set2[j]) {
                System.out.print(set1[i] + " ");
                i++;
            } else if (set1[i] > set2[j]) {
                System.out.print(set2[j] + " ");
                j++;
            } else if (set1[i] == set2[j]) {
            System.out.print(set1[i] + " ");
            i++;
            j++;
            }   
        }
        
        while (i < set1.length) {
            System.out.print(set1[i] + " ");
            i++;
        }
        
        while (j < set2.length) {
            System.out.print(set2[j] + " ");
            j++;
        }
        
    }
    */
    
    
    public static void intersection(int[] set1, int[] set2) {
        long start = System.currentTimeMillis();
        int[] resultSet = new int[Math.max(set1.length, set2.length)];
        
        for (int i = 0; i < set1.length; i++) {
            int number = set1[i];
            
            for (int j = 0; j < set2.length; j++) {
                if (set2[j] == number && search(resultSet, number) == false) {
                    resultSet[i] = number;

                }
            }
            
            
        }
        
        System.out.print("Intersection Set: ");
        for (int i : resultSet) {
            if (i != 0)
                System.out.print(i + " ");
        }
        long end = System.currentTimeMillis();
        long time = Math.abs(end - start);
        System.out.println("\nTime: " + time + " ms");
        System.out.println();
    }
    
    public static void difference(int[] set1, int[] set2) {
        long start = System.currentTimeMillis();
        // Set1 - Set2
        int[] resultSet = new int[Math.max(set1.length, set2.length)];
        
        for (int i = 0; i < set1.length; i++) {
            int number = set1[i];
            
            for (int j = 0; j < set2.length; j++) {
                if (search(set2, number) == true) {
                    break;
                } else if (search(resultSet, number) == false) {
                    //if (search(resultSet, number) == false)
                    resultSet[i] = number;
                }
            }
        }
        
        System.out.print("Difference Set: ");
        for (int i : resultSet) {
            if (i != 0)
                System.out.print(i + " ");
        }
        long end = System.currentTimeMillis();
        long time = Math.abs(end - start);
        System.out.println("\nTime: " + time + " ms");
        System.out.println();
        
    }
    
    
    public static void symmetricDifference(int[] set1, int[] set2) {
        long start = System.currentTimeMillis();
        // Set1 - Set2
        int[] resultSet = new int[set1.length*set2.length];
        
        for (int i = 0; i < set1.length; i++) {
            int number = set1[i];
            
            for (int j = 0; j < set2.length; j++) {
                if (search(set2, number) == true) {
                    break;
                } else if (search(resultSet, number) == false) {
                    //if (search(resultSet, number) == false)
                    resultSet[i] = number;
                }
            }
        }
        
        for (int i = 0; i < set2.length; i++) {
            int number = set2[i];
            
            for (int j = 0; j < set1.length; j++) {
                if (search(set1, number) == true) {
                    break;
                } else if (search(resultSet, number) == false) {
                    //if (search(resultSet, number) == false)
                    resultSet[i] = number;
                }
            }
        }
        
        System.out.print("Symmetric Difference Set: ");
        for (int i : resultSet) {
            if (i != 0)
                System.out.print(i + " ");
        }
        long end = System.currentTimeMillis();
        long time = Math.abs(end - start);
        System.out.println("\nTime: " + time + " ms");
        System.out.println();
        

    }
    
    
    public static void initialize(SetUsingArrays s1, SetUsingArrays s2) throws Exception {
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Please enter the set values for set 1 separated by a space (e.g. 1 2 3 4..): ");
        String set_One_Input = keyboard.nextLine();
        String[] setOneArray = set_One_Input.split(" ");
        
        for (int i = 0; i < setOneArray.length; i++) {
            s1.set[i] = Integer.parseInt(setOneArray[i]);
        }

        
        System.out.println("Please enter the set values for set 2 separated by a space (e.g. 1 2 3 4..): ");
        String set_Two_Input = keyboard.nextLine();
        String[] setTwoArray = set_Two_Input.split(" ");

        for (int i = 0; i < setTwoArray.length; i++) {
            s2.set[i] = Integer.parseInt(setTwoArray[i]);
        }
        
    }
    
    public static void prompt(SetUsingArrays s1, SetUsingArrays s2){
        System.out.println("Welcome!\n(1) for Union\n(2) for Intersection\n(3) for Difference\n(4) for Symmetric Difference\n(0) to quit.");
        System.out.print("Input: ");
        Scanner keyboard = new Scanner(System.in);
        String selection = keyboard.next();
        while (!selection.equals("0")) {
            int choice = Integer.parseInt(selection);
            if (choice == 1) {
                union(s1.set, s2.set);
                System.out.println("Welcome!\n(1) for Union\n(2) for Intersection\n(3) for Difference\n(4) for Symmetric Difference\n(0) to quit.");
                selection = keyboard.next();

            } else if (choice == 2) {
                intersection(s1.set, s2.set);
                System.out.println("Welcome!\n(1) for Union\n(2) for Intersection\n(3) for Difference\n(4) for Symmetric Difference\n(0) to quit.");
                selection = keyboard.next();
            } else if (choice == 3) {
                difference(s1.set, s2.set);
                System.out.println("Welcome!\n(1) for Union\n(2) for Intersection\n(3) for Difference\n(4) for Symmetric Difference\n(0) to quit.");
                selection = keyboard.next();
            } else if (choice == 4) {
                symmetricDifference(s1.set, s2.set);
                System.out.println("Welcome!\n(1) for Union\n(2) for Intersection\n(3) for Difference\n(4) for Symmetric Difference\n(0) to quit.");
                selection = keyboard.next();
            } else if (choice == 0) {
                break;
            }
            else {
                System.out.println("Enter a valid selection like 1, 2, 3, or 0.. ");
                selection = keyboard.next();
            }

        }

        
    }
    
    
    
    public static void main (String[] args) {
        SetUsingArrays s1 = new SetUsingArrays(50);
        SetUsingArrays s2 = new SetUsingArrays(50);
        boolean valid = false;
        while (!valid) {
            try {
            initialize(s1, s2);
            valid = true;
            } catch (Exception e) {
                System.out.println("Error. Re-initializing..");
            }
        }
    
        valid = false;
        while (!valid) {
            try {
                prompt(s1,s2);
                valid = true;
            } catch (Exception e) {
                System.out.println("Error. Re-initializing..");
            }
        }

        
    }
    
}
