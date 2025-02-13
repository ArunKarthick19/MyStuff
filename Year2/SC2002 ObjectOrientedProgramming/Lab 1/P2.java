import java.util.Scanner;


public class P2{
    public static void main(String[] args){
        //3.3
        System.out.println("Hello!");

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter person's salary: ");
        int salary33 = sc.nextInt();
        System.out.print("Enter person's merit points: ");
        int merit33 = sc.nextInt();

        if(salary33>=700 && salary33<=799 && merit33<20)
        {
                System.out.println("Grade B"); 
        }

        else if(salary33>=700 && salary33<=899)
        {
            System.out.println("Grade A");
        }

        else if(salary33>=600 && salary33<=649 && merit33<10)
        {
                System.out.println("Grade C");
        }

        else if(salary33>=600 && salary33<=799)
        {
            System.out.println("Grade B");
        }

        else if(salary33>=500 && salary33<=649)
        {
            System.out.println("Grade C");
        }

    }
}