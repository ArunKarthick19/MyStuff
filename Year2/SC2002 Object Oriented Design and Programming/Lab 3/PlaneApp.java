package LAB3;

import java.util.Scanner;

public class PlaneApp {

    public static void main(String[] args) {
        Plane plane = new Plane();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n(1) Show number of empty seats");
            System.out.println("(2) Show the list of empty seats");
            System.out.println("(3) Show the list of seat assignments by seat ID");
            System.out.println("(4) Show the list of seat assignments by customer ID");
            System.out.println("(5) Assign a customer to a seat");
            System.out.println("(6) Remove a seat assignment");
            System.out.println("(7) Exit");
            System.out.print("Enter the number of your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    plane.showNumEmptySeats();
                    break;

                case 2:
                    plane.showEmptySeats();
                    break;

                case 3:
                    plane.showAssignedSeats(true); // Show by Seat ID
                    break;

                case 4:
                    plane.showAssignedSeats(false); // Show by Customer ID
                    break;

                case 5:
                    System.out.print("Please enter SeatID: ");
                    int seatId = scanner.nextInt();
                    System.out.print("Please enter Customer ID: ");
                    int custId = scanner.nextInt();
                    plane.assignSeat(seatId, custId);
                    break;

                case 6:
                    System.out.print("Enter SeatID to unassign customer from: ");
                    int unassignSeatId = scanner.nextInt();
                    plane.unAssignSeat(unassignSeatId);
                    break;

                case 7:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice, please try again.");
                    break;
            }

        } while (choice != 7);

        scanner.close();
    }
}
