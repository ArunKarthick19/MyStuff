//package LAB;

public class PlaneSeat {
    private int seatId;
    private boolean assigned;
    private int customerId;

    // Constructor
    public PlaneSeat(int seatId) {
        this.seatId = seatId;
        this.assigned = false;
        this.customerId = -1; // Default value indicating no customer assigned
    }

    // Getters
    public int getSeatID() {
        return seatId;
    }

    public int getCustomerID() {
        return customerId;
    }

    public boolean isOccupied() {
        return assigned;
    }

    // Assign seat to a customer
    public void assign(int customerId) {
        this.customerId = customerId;
        this.assigned = true;
    }

    // Unassign seat
    public void unAssign() {
        this.customerId = -1;
        this.assigned = false;
    }
}

