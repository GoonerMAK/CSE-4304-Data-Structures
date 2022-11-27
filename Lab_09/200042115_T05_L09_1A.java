package org.example;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map.Entry;

public class UniqueCharacterSet {

    static final int MAX_CHAR = 26;

    static String getKey(String str)
    {
        boolean[] visited = new boolean[MAX_CHAR];
        Arrays.fill(visited, false);


        for (int j = 0; j < str.length(); j++)
        {
            System.out.println(str.charAt(j) - 'a');
            visited[str.charAt(j) - 'a'] = true ;
        }

        String key = "";
        for (int j=0; j < MAX_CHAR; j++)
            if (visited[j])
                key = key + (char)('a'+j);
        return key;
    }


    static void wordsWithSameCharSet(String words[], int n)
    {

        HashMap<String, ArrayList<Integer>> Hash = new HashMap<>();

        // Traverse all words
        for (int i=0; i<n; i++)
        {
            String key = getKey(words[i]);

            System.out.println(key);

            if(Hash.containsKey(key))
            {
                ArrayList<Integer> get_al = Hash.get(key);
                get_al.add(i);
                System.out.println(get_al);
                Hash.put(key, get_al);
                System.out.println(Hash);
            }


            else
            {
                ArrayList<Integer> new_al = new ArrayList<>();
                new_al.add(i);
                System.out.println(new_al);
                Hash.put(key, new_al);
                System.out.println(Hash);
            }
        }

        // print all words that have the same unique character set
        for (Entry<String, ArrayList<Integer>> it : Hash.entrySet())
        {
            ArrayList<Integer> get =it.getValue();
            for (Integer v:get)
                System.out.print( words[v] + ", ");
            System.out.println();
        }
    }


    public static void main(String args[])
    {
        String str = "you may know the answer but it is not yam or maaayaaay or yammy";

        String[] words = str.split(" ");

        for (int i = 0; i < words.length; i++)
        {
            System.out.println(words[i]);
        }


        int n = words.length;
        System.out.println("Size of the sentence: " + n);

        wordsWithSameCharSet(words, n);
    }
}
