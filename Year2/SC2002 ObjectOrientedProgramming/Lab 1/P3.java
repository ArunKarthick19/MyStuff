import java.util.Scanner;


public class P3{

    static void tableheader()
    {
        System.out.println(" US$     S$");
        System.out.println("------------");
    }
    public static void main(String[] args){
        double USD = 1.82;
        Scanner sc = new Scanner(System.in);

        //Table 1 for loop
        System.out.print("Enter starting: ");
        int starting33 = sc.nextInt();
        System.out.print("Enter ending: ");
        int ending33 = sc.nextInt();
        System.out.print("Enter increament: ");
        int increament33 = sc.nextInt();

        if(ending33 < starting33)
        {
            System.out.println("Error input!!");
            return;
            
        }

        tableheader();

        for(int i = starting33; i <= ending33; i += increament33 )
        {
            System.out.println(i + "      " + USD*i);
        }


        //Table 2 while loop

        System.out.print("Enter starting: ");
        int starting332 = sc.nextInt();
        System.out.print("Enter ending: ");
        int ending332 = sc.nextInt();
        System.out.print("Enter increament: ");
        int increament332 = sc.nextInt();

        if(ending332 < starting332)
        {
            System.out.println("Error input!!");
            return;
            
        }

        tableheader();
        int counter = starting332;
        while(starting332<=ending332)
        {
            
            System.out.println(counter + "      " + USD*counter);
            counter += increament332;
            starting332 += increament332;
        }



        //Table 3 do/while loop


        System.out.print("Enter starting: ");
        int starting333 = sc.nextInt();
        System.out.print("Enter ending: ");
        int ending333 = sc.nextInt();
        System.out.print("Enter increament: ");
        int increament333 = sc.nextInt();

        if(ending333 < starting333)
        {
            System.out.println("Error input!!");
            return;
            
        }

        tableheader();
        int counter2 = starting333;

        do {
            System.out.println(counter2 + "      " + USD*counter2);
            counter2 += increament333;
            starting333 += increament333;
            
        } while (starting333<=ending333);



        
        
    }
}