
import java.util.Random;
import java.util.Scanner;

public class lab2p1 {

    // Method for multiplication test
    public static void mulTest() {
        Random r = new Random();
        Scanner sc = new Scanner(System.in);
        int mulTestCorrectCounter = 0;
        int no[] = new int[10];
        int qreply[] = new int[5];
        for(int j = 0; j<10; j++)
        {
            no[j] = r.nextInt(9)+1;
        }
        
        for(int i=0; i<5; i++)
        {
            System.out.print("How much is " + no[i] + " times " + no[i+1] + " ? ");
            qreply[i] = sc.nextInt();
            if(qreply[i] == no[i]*no[i+1])
            {
                mulTestCorrectCounter++;
            }

        }
        System.out.println(mulTestCorrectCounter + " answers out of 5 are correct.");
}

    // Method for quotient using division by subtraction
    public static int divide(int m, int n) {
        if (n == 0) {
            throw new ArithmeticException("Division by zero");
        }
        int quotient = 0;
        while (m >= n) {
            m -= n;
            quotient++;
        }
        return quotient;
    }


    public static int modulus(int m, int n)
    {
        if(m<n){
            return m; 
        }
        else if(m==n){
            return 0;
        }

        else 
        {
            while(m>n)
            {
              m = m-n;
            }
        }

        return n+(m-n);
    }

    // Method for counting digits in a number
    public static int countDigits(int n) {
        if (n < 0) {
            System.out.println("error");
            return 0;
        }
        return Integer.toString(n).length();
    }

    // Method for finding the position of a digit in a number
    public static int position(int n, int digit) {
        String numstr = Integer.toString(n);
        char d = Integer.toString(digit).charAt(0);
        int pos = 1;
        for (int i = numstr.length()-1; i > 0; i--) {
        
            if (numstr.charAt(i) == d) {
          
                return pos; 
            }
            pos++;
        }
       
        return -1;
    }

    // Method for extracting odd digits from a number
    public static long extractOddDigits(long n) {
        long result = 0;
        long multiplier = 1;
        while (n > 0) {
            int digit = (int) (n % 10);
            if (digit % 2 != 0) {
                result = digit * multiplier + result;
                multiplier *= 10;
            }
            n /= 10;
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("Perform the following methods:");
            System.out.println("1. Multiplication test");
            System.out.println("2. Quotient using division by subtraction");
            System.out.println("3. Remainder using division by subtraction");
            System.out.println("4. Count the number of digits");
            System.out.println("5. Position of a digit");
            System.out.println("6. Extract all odd digits");
            System.out.println("7. Quit");

            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    mulTest();
                    break;
                case 2:
                    System.out.print("m = ");
                    int d21 = sc.nextInt();
                    System.out.print("n = ");
                    int d22 = sc.nextInt();
                    System.out.println(d21 + "/" + d22 + " = " + divide(d21, d22));
                    break;
                case 3:
                    System.out.print("m = ");
                    int d31 = sc.nextInt();
                    System.out.print("n = ");
                    int d32 = sc.nextInt();
                    System.out.println(d31 + " % " + d32 + " = " + modulus(d31, d32));
                    break;
                case 4:
                    System.out.print("n : ");
                    int number = sc.nextInt();
                    if(number<0)
                    {
                        System.out.println("n : " + number + " - Error input!!");
                        break;
                    }
                    System.out.println("n : " + number + " - count = " + countDigits(number));
                    break;
                case 5:
                    System.out.print("n : ");
                    number = sc.nextInt();
                    System.out.print("digit : ");
                    int digit = sc.nextInt();
                    int pos = position(number, digit);
                    System.out.println("Position = " + pos);
    
                    break;
                case 6:
                    System.out.print("n : ");
                    long longNumber = sc.nextLong();
                    if(longNumber<0)
                    {
                        System.out.println("oddDigits = Error Input!!");
                        break;
                    }
                    System.out.println("oddDigits = " + extractOddDigits(longNumber));
                    break;
                case 7:
                    System.out.println("Program terminating....");
                    break;
                /*default:
                    System.out.println("Invalid choice. Please enter a number between 1 and 7.");*/
            }
        } while (choice != 7);

        sc.close();
    }
}
