# Course Schedule Solution

## **1.Description**
This project provides a solution to the **Course Schedule** problem using **Topological Sorting (Kahn's Algorithm)**. The problem is solved using **Breadth-First Search (BFS)** to determine if all courses can be completed without conflicts due to prerequisite cycles. Additionally, the program returns a possible order in which courses can be completed.

### **Features**
- ✅ Determines if all courses can be completed.
- ✅ Finds a valid course order if possible.
- ✅ Efficient implementation using **Graph + BFS (Kahn’s Algorithm)**.
- ✅ Separate test cases to validate functionality.

---

## **2.Limitations**
The solution assumes **valid course numbers from 0 to numCourses - 1**.
If multiple valid course orders exist, only one is returned.
The program does **not** handle invalid inputs (e.g., negative course numbers).

---

## **How to Compile and Run**

### **Prerequisites**
- Java Development Kit (JDK) **8 or later**
- A terminal or command prompt

### **3.Steps to Compile Clear and detailed instructions **

![image](https://github.com/user-attachments/assets/c2b78e4b-b25a-4e59-b3f2-20d9d19b30b8)

After downloading and extracting this folder : 

1. **Navigate to the project folder** in your terminal:
   ```sh
   cd MISBAH_BAGWAN_72301019G\src>

2.Compile the Java files:

    javac CourseSchedule.java CourseScheduleTest.java

This will create .class files of java program

3.After compilation, execute the test program:

    java CourseScheduleTest
    
## **4.Instructions on how to execute included tests.**

The test cases are included in CourseScheduleTest.java 

and only the above two commands are needed to execute 

Above commands will create .class file for java program

The main() method from where execution starts it in the CourseScheduleTest.java 
file 

thus for executing write :

    java CourseScheduleTest

It contains a total of 5 testcases like 

1 (Cycle exists)	

2 (Valid order)	

3 (No prerequisites)	

4 (Cycle exists)

5 (Valid order)

TIME and Space complexity :

both O(V+E)







