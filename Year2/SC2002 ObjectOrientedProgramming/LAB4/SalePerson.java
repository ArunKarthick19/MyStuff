import java.util.Scanner;

public class SalePerson implements Comparable<SalePerson> {
    private String firstName;
    private String lastName;
    private int totalSales;

   
    public SalePerson(String firstName, String lastName, int totalSales) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.totalSales = totalSales;
    }

    
    public String toString() {
        return lastName + ", " + firstName + " : " + totalSales;
    }

    
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;

        SalePerson other = (SalePerson) obj;
        return firstName.equals(other.firstName) && lastName.equals(other.lastName);
    }

   
    public int compareTo(SalePerson other) {
        // Compare by total sales (descending)
        if (this.totalSales != other.totalSales) {
            return Integer.compare(other.totalSales, this.totalSales); // descending order of sales
        }
        // If total sales are the same, compare by last name (descending alphabetical order)
        return this.lastName.compareTo(other.lastName); // descending alphabetical order
    }
    
    
    

    /*public static void main(String[] args){

    }*/
}
