/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package CS408;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author John
 */
public class SetUsingArrayLists {
    
    private List<Integer> numberSet;
    
    SetUsingArrayLists() {
        numberSet = new ArrayList<Integer>();
        
    }
    
    SetUsingArrayLists(int size) {
        numberSet = new ArrayList<Integer>(size);
        
    }
    
    public static void union(List<Integer> list1, List<Integer> list2) {
        long start = System.currentTimeMillis();
        List<Integer> resultList = new ArrayList<Integer>();
        
        for (int i : list1) {
            resultList.add(i);
        }
        
        for (int j : list2) {
            if (!resultList.contains(j)) {
                resultList.add(j);
            }
        }
        
        System.out.print("Union Set: ");
        for (int num : resultList) {
            System.out.print(num + " ");
        }
        long end = System.currentTimeMillis();
        long time = Math.abs(end - start);
        System.out.println("\nTime: " + time + " ms");
        System.out.println();
        
    }
    
    public static void intersection(List<Integer> list1, List<Integer> list2) {
        long start = System.currentTimeMillis();
        List<Integer> resultList = new ArrayList<Integer>();
        
        for (int i : list1) {
            if (list2.contains(i)) {
                resultList.add(i);
            }

        }
        
        System.out.print("Intersection Set: ");
        for (int num : resultList) {
            System.out.print(num + " ");
        }
        long end = System.currentTimeMillis();
        long time = Math.abs(end - start);
        System.out.println("\nTime: " + time + " ms");
        System.out.println();        
        
    }
    
    public static void difference(List<Integer> list1, List<Integer> list2) {
        long start = System.currentTimeMillis();
        List<Integer> resultList = new ArrayList<Integer>();
        
        for (int i : list1) {
            if (!list2.contains(i)) {
                resultList.add(i);
            }
 
        }
        
        System.out.print("Difference Set: ");
        for (int num : resultList) {
            System.out.print(num + " ");
        }
        long end = System.currentTimeMillis();
        long time = Math.abs(end - start);
        System.out.println("\nTime: " + time + " ms");
        System.out.println();
        
        
    }
    
    public static void symmetricDifference(List<Integer> list1, List<Integer> list2) {
        long start = System.currentTimeMillis();
        List<Integer> resultList = new ArrayList<Integer>();
        
        for (int i : list1) {
            if (!list2.contains(i)) {
                resultList.add(i);
            }
 
        }
        
        for (int i : list2) {
            if (!list1.contains(i)) {
                resultList.add(i);
            }
        }
        System.out.print("Symmetric Difference Set: ");
        for (int num : resultList) {
            System.out.print(num + " ");
        }
        long end = System.currentTimeMillis();
        long time = Math.abs(end - start);
        System.out.println("\nTime: " + time + " ms");
        System.out.println();
        
        
    }
    
    public static void initialize(SetUsingArrayLists s1, SetUsingArrayLists s2) throws Exception {
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Please enter the set values for set 1 separated by a space (e.g. 1 2 3 4..): ");
        String set_One_Input = keyboard.nextLine();
        String[] setOneArray = set_One_Input.split(" ");
        
        for (String s : setOneArray)
            s1.numberSet.add(Integer.parseInt(s));

        
        System.out.println("Please enter the set values for set 2 separated by a space (e.g. 1 2 3 4..): ");
        String set_Two_Input = keyboard.nextLine();
        String[] setTwoArray = set_Two_Input.split(" ");

        for (String s : setTwoArray)
            s2.numberSet.add(Integer.parseInt(s));
        
    }
    
    public static void prompt(SetUsingArrayLists s1, SetUsingArrayLists s2){
        System.out.println("Welcome!\n(1) for Union\n(2) for Intersection\n(3) for Difference\n(4) for Symmetric Difference\n(0) to quit.");
        System.out.print("Input: ");
        Scanner keyboard = new Scanner(System.in);
        String selection = keyboard.next();

        while (!selection.equals("0")) {
            int choice = Integer.parseInt(selection);
            if (choice == 1) {
                union(s1.numberSet, s2.numberSet);
                System.out.println("Welcome!\n(1) for Union\n(2) for Intersection\n(3) for Difference\n(4) for Symmetric Difference\n(0) to quit.");
                selection = keyboard.next();

            } else if (choice == 2) {
                intersection(s1.numberSet, s2.numberSet);
                System.out.println("Welcome!\n(1) for Union\n(2) for Intersection\n(3) for Difference\n(4) for Symmetric Difference\n(0) to quit.");
                selection = keyboard.next();
            } else if (choice == 3) {
                difference(s1.numberSet, s2.numberSet);
                System.out.println("Welcome!\n(1) for Union\n(2) for Intersection\n(3) for Difference\n(4) for Symmetric Difference\n(0) to quit.");
                selection = keyboard.next();
            } else if (choice == 4) {
                symmetricDifference(s1.numberSet, s2.numberSet);
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
    
    
    public static void main(String[] args) {
        SetUsingArrayLists s1 = new SetUsingArrayLists();
        SetUsingArrayLists s2 = new SetUsingArrayLists();
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
