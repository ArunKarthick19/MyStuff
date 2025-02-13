public interface Shape {
    double calculateSurfaceArea(); 
}



public class Sphere implements Shape {
    private double radius;

    public Sphere(double radius) {
        this.radius = radius;
    }

    @Override
    public double calculateSurfaceArea() {
        return 4 * Math.PI * radius * radius;
    }
}

public class Cone implements Shape {
    private double radius;
    private double height;

    public Cone(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    @Override
    public double calculateSurfaceArea() {
        return Math.PI * radius * (radius + Math.sqrt(height * height + radius * radius));
    }
}

public class Cuboid implements Shape {
    private double length;
    private double breadth;
    private double height;

    public Cuboid(double length, double breadth, double height) {
        this.length = length;
        this.breadth = breadth;
        this.height = height;
    }

    @Override
    public double calculateSurfaceArea() {
        return 2 * (length * breadth + breadth * height + height * length);
    }
}
