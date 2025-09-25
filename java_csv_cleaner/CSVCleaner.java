// CSVCleaner.java
// Simple CLI to trim whitespace and normalize empty fields in a CSV.
// Usage: java CSVCleaner input.csv output.csv
// No external libraries required.
import java.io.*;
import java.util.*;

public class CSVCleaner {
    public static void main(String[] args) {
        if (args.length < 2) {
            System.err.println("Usage: java CSVCleaner <input.csv> <output.csv>");
            System.exit(1);
        }
        String inPath = args[0], outPath = args[1];
        try (BufferedReader br = new BufferedReader(new FileReader(inPath));
             PrintWriter pw = new PrintWriter(new FileWriter(outPath))) {

            String line;
            int lineNo = 0;
            while ((line = br.readLine()) != null) {
                lineNo++;
                // Basic CSV split (comma). For real-world CSVs, consider a proper parser.
                String[] parts = line.split(",", -1); // keep empty fields
                for (int i = 0; i < parts.length; i++) {
                    String s = parts[i].trim();
                    // Normalize common "NULL" markers to empty string
                    if (s.equalsIgnoreCase("null") || s.equals("-")) s = "";
                    parts[i] = s;
                }
                pw.println(String.join(",", parts));
            }
            System.out.println("Cleaned CSV written to " + outPath);
        } catch (IOException e) {
            System.err.println("I/O error: " + e.getMessage());
            System.exit(2);
        }
    }
}
