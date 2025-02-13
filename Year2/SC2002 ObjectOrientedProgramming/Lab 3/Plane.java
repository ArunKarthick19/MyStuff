package LAB3;

	import java.util.Arrays;
	import java.util.Comparator;

	public class Plane {
	    private PlaneSeat[] seats;
	    private int numEmptySeat;

	    // Constructor
	    public Plane() {
	        seats = new PlaneSeat[12];
	        for (int i = 0; i < seats.length; i++) {
	            seats[i] = new PlaneSeat(i + 1);
	        }
	        numEmptySeat = seats.length;
	    }

	    private PlaneSeat[] sortSeats() {
	        PlaneSeat[] sortedSeats = Arrays.copyOf(seats, seats.length);
	        Arrays.sort(sortedSeats, Comparator.comparingInt(PlaneSeat::getCustomerID));
	        return sortedSeats;
	    }


	    // Show number of empty seats
	    public void showNumEmptySeats() {
	        System.out.println("There are " + numEmptySeat + " empty seats");
	    }

	    // Show list of empty seats
	    public void showEmptySeats() {
	        System.out.println("The following seats are empty:");
	        for (PlaneSeat seat : seats) {
	            if (!seat.isOccupied()) {
	                System.out.println("SeatID " + seat.getSeatID());
	            }
	        }
	    }

	    // Show assigned seats by seat ID or customer ID
	    public void showAssignedSeats(boolean bySeatId) {
	        System.out.println("The seat assignments are as follows:");
	        PlaneSeat[] displaySeats = bySeatId ? seats : sortSeats();

	        for (PlaneSeat seat : displaySeats) {
	            if (seat.isOccupied()) {
	                System.out.println("SeatID " + seat.getSeatID() + " assigned to CustomerID " + seat.getCustomerID());
	            }
	        }
	    }

	    // Assign seat to a customer
	    public void assignSeat(int seatId, int custId) {
	        if (seatId < 1 || seatId > 12) {
	            System.out.println("Invalid Seat ID.");
	            return;
	        }

	        PlaneSeat seat = seats[seatId - 1];
	        if (seat.isOccupied()) {
	            System.out.println("Seat already assigned to a customer.");
	        } else {
	            seat.assign(custId);
	            numEmptySeat--;
	            System.out.println("Seat Assigned!");
	        }
	    }

	    // Unassign seat
	    public void unAssignSeat(int seatId) {
	        if (seatId < 1 || seatId > 12) {
	            System.out.println("Invalid Seat ID.");
	            return;
	        }

	        PlaneSeat seat = seats[seatId - 1];
	        if (seat.isOccupied()) {
	            seat.unAssign();
	            numEmptySeat++;
	            System.out.println("Seat Unassigned!");
	        } else {
	            System.out.println("Seat is already empty.");
	        }
	    }
	}


