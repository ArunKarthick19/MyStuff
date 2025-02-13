import java.util.Scanner;



public class P1{
    public static void main(String[] args){
        //2.1
       System.out.println("Hello! This is my first program.");
       System.out.println("Bye Bye!");


       Scanner sc = new Scanner(System.in);

       //3.1

       System.out.print("Enter a character(A, C, D): ");
       char input31 = sc.next().charAt(0);

       if(!Character.isUpperCase(input31))
       {
            input31 =  Character.toUpperCase(input31);

       }

       System.out.println("result: " + input31);

       switch(input31)
       {
            case 'A':
                System.out.println("Action movie fan");
                break;
            case 'C':
                System.out.println("Comedy movie fan");
                break;
            case 'D':
                System.out.println("Drama movie fan");
                break;
            default:
                System.out.println("Invalid choice");
       }









        
    }
}