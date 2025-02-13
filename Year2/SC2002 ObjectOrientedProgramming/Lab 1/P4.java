import java.util.Scanner;


public class P4{
    public static void main(String[] args){
        String aa = "AA";
        String bb = "BB";

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number: ");
        int input44 = sc.nextInt();

       for(int j = 0; j<=input44; j++)
       {
            if(j %2 == 0)
            {
                for(int i = 0; i < j; i+=2 )
                {
                    System.out.print(bb+aa);
                }
            }
            
            else
            {
                System.out.print(aa);
                for(int i = 1; i < j; i+=2 )
                {
                    System.out.print(bb+aa);
                    
                }  
            }
            System.out.println("");

       }

        
    }
}