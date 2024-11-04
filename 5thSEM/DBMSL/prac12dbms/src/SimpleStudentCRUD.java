import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import org.bson.Document;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SimpleStudentCRUD {

    public static void main(String[] args) {
        // Connect to MongoDB
        MongoClient mongoClient = MongoClients.create("mongodb://localhost:27017"); // Update with your MongoDB URI
        MongoDatabase database = mongoClient.getDatabase("school"); // Database name
        MongoCollection<Document> collection = database.getCollection("stud"); // Collection name

        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\nMenu:");
            System.out.println("1. Add Student");
            System.out.println("2. View Students");
            System.out.println("3. Update Student");
            System.out.println("4. Delete Student");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1: // Add Student
                    System.out.print("Enter student name: ");
                    String name = scanner.nextLine();

                    System.out.print("Enter student age: ");
                    int age = scanner.nextInt();
                    scanner.nextLine(); // Consume newline

                    System.out.print("Enter student roll number: ");
                    String rollNo = scanner.nextLine();

                    // Create marks list
                    List<Document> marksList = new ArrayList<>();

                    for (int i = 1; i <= 2; i++) { // Assuming only two subjects
                        System.out.print("Enter subject " + i + " name: ");
                        String subject = scanner.nextLine();

                        System.out.print("Enter marks for " + subject + ": ");
                        int marks = scanner.nextInt();
                        scanner.nextLine(); // Consume newline

                        // Add marks to the list
                        Document marksDoc = new Document("subject", subject)
                                .append("marks", marks);
                        marksList.add(marksDoc);
                    }

                    // Input for contact information
                    System.out.print("Enter address: ");
                    String address = scanner.nextLine();

                    System.out.print("Enter email: ");
                    String email = scanner.nextLine();

                    // Create contact document
                    Document contactDoc = new Document("address", address)
                            .append("email", email);

                    // Create a new student document
                    Document newStudent = new Document("name", name)
                            .append("age", age)
                            .append("rollNo", rollNo)
                            .append("marks", marksList)
                            .append("contact", contactDoc);

                    // Insert the student document
                    collection.insertOne(newStudent);
                    System.out.println("Student added: " + newStudent.toJson());
                    break;

                case 2: // View Students
                    System.out.println("Students in the database:");
                    for (Document student : collection.find()) {
                        System.out.println(student.toJson());
                    }
                    break;

                case 3: // Update Student
                    System.out.print("Enter the roll number of the student to update: ");
                    String rollNumberToUpdate = scanner.nextLine();

                    System.out.print("Enter new name: ");
                    String newName = scanner.nextLine();

                    System.out.print("Enter new age: ");
                    int newAge = scanner.nextInt();
                    scanner.nextLine(); // Consume newline

                    // Create an update document
                    Document updatedStudent = new Document("name", newName)
                            .append("age", newAge);

                    // Update the student document
                    Document query = new Document("rollNo", rollNumberToUpdate);
                    collection.updateOne(query, new Document("$set", updatedStudent));
                    System.out.println("Student updated with roll number: " + rollNumberToUpdate);
                    break;

                case 4: // Delete Student
                    System.out.print("Enter the roll number of the student to delete: ");
                    String rollNumberToDelete = scanner.nextLine();

                    // Create a query document
                    Document deleteQuery = new Document("rollNo", rollNumberToDelete);

                    // Delete the student document
                    collection.deleteOne(deleteQuery);
                    System.out.println("Student deleted with roll number: " + rollNumberToDelete);
                    break;

                case 5: // Exit
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 5);

        // Close the connection
        mongoClient.close();
        scanner.close();
    }
}
